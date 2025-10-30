#include "s21_string.h"

typedef struct {
  int suppress_assignment;
  int width;
  char length;
} s21_Scanf_Options;

static int s21_isspace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
         c == '\r';
}
static int s21_isdigit(char c) { return c >= '0' && c <= '9'; }
static int s21_isalpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
static char s21_tolower(char c) {
  if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
  return c;
}

static void skip_whitespace(const char **str) {
  while (s21_isspace(**str)) {
    (*str)++;
  }
}

static int parse_integer(const char **str, int width, int base,
                         long long *result) {
  const char *p = *str;
  long long num = 0;
  int sign = 1;
  int parsed_chars = 0;

  if (*p == '-') {
    sign = -1;
    p++;
    if (width > 0) width--;
  } else if (*p == '+') {
    p++;
    if (width > 0) width--;
  }

  if (base == 0) {
    base = 10;
    if (*p == '0') {
      base = 8;
      p++;
      if (width > 0) width--;
      if (s21_tolower(*p) == 'x') {
        base = 16;
        p++;
        if (width > 0) width--;
      }
    }
  }

  int no_digits = 1;
  while (*p && (width < 0 || parsed_chars < width)) {
    int digit = -1;
    if (s21_isdigit(*p))
      digit = *p - '0';
    else if (base == 16 && s21_isalpha(*p))
      digit = s21_tolower(*p) - 'a' + 10;

    if (digit >= 0 && digit < base) {
      num = num * base + digit;
      p++;
      parsed_chars++;
      no_digits = 0;
    } else
      break;
  }

  if (no_digits) return 0;

  *result = num * sign;
  *str = p;
  return 1;
}

static int parse_long_double(const char **str, int width, long double *result) {
  const char *p = *str;
  long double num = 0.0;
  int sign = 1;
  int parsed_chars = 0;

  if (*p == '-') {
    sign = -1;
    p++;
    if (width > 0) width--;
  } else if (*p == '+') {
    p++;
    if (width > 0) width--;
  }

  int no_digits = 1;
  while (s21_isdigit(*p) && (width < 0 || parsed_chars < width)) {
    num = num * 10.0 + (*p - '0');
    p++;
    parsed_chars++;
    no_digits = 0;
  }

  if (*p == '.' && (width < 0 || parsed_chars < width)) {
    p++;
    parsed_chars++;
    long double divisor = 10.0;
    while (s21_isdigit(*p) && (width < 0 || parsed_chars < width)) {
      num += (*p - '0') / divisor;
      divisor *= 10.0;
      p++;
      parsed_chars++;
      no_digits = 0;
    }
  }

  if (no_digits) return 0;

  if (s21_tolower(*p) == 'e' && (width < 0 || parsed_chars < width)) {
    p++;
    parsed_chars++;
    int exp_sign = 1;
    long long exponent = 0;
    if (*p == '-') {
      exp_sign = -1;
      p++;
      parsed_chars++;
    } else if (*p == '+') {
      p++;
      parsed_chars++;
    }

    while (s21_isdigit(*p) && (width < 0 || parsed_chars < width)) {
      exponent = exponent * 10 + (*p - '0');
      p++;
      parsed_chars++;
    }

    long double power_of_10 = 10.0;
    if (exponent > 0) {
      while (exponent > 1) {
        power_of_10 *= 10.0;
        exponent--;
      }
      if (exp_sign > 0)
        num *= power_of_10;
      else
        num /= power_of_10;
    }
  }

  *result = num * sign;
  *str = p;
  return 1;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int assigned_count = 0;
  const char *str_ptr = str;
  const char *format_ptr = format;

  while (*format_ptr && *str_ptr) {
    if (s21_isspace(*format_ptr)) {
      skip_whitespace(&str_ptr);
      format_ptr++;
      continue;
    }

    if (*format_ptr != '%') {
      if (*str_ptr == *format_ptr) {
        str_ptr++;
        format_ptr++;
        continue;
      } else
        break;
    }

    format_ptr++;
    s21_Scanf_Options options = {0, -1, 0};

    if (*format_ptr == '*') {
      options.suppress_assignment = 1;
      format_ptr++;
    }

    while (s21_isdigit(*format_ptr)) {
      if (options.width == -1) options.width = 0;
      options.width = options.width * 10 + (*format_ptr - '0');
      format_ptr++;
    }

    if (*format_ptr == 'h' || *format_ptr == 'l' || *format_ptr == 'L') {
      options.length = *format_ptr;
      format_ptr++;
    }

    char specifier = *format_ptr;
    int success = 0;

    if (s21_strchr("diouxX", specifier)) {
      skip_whitespace(&str_ptr);
      long long val = 0;
      int base = 10;
      if (specifier == 'i')
        base = 0;
      else if (specifier == 'o')
        base = 8;
      else if (specifier == 'x' || specifier == 'X')
        base = 16;

      success = parse_integer(&str_ptr, options.width, base, &val);
      if (success && !options.suppress_assignment) {
        void *ptr = va_arg(args, void *);
        if (options.length == 'h')
          *(short *)ptr = (short)val;
        else if (options.length == 'l')
          *(long *)ptr = (long)val;
        else
          *(int *)ptr = (int)val;
      }
    } else if (specifier == 's') {
      skip_whitespace(&str_ptr);
      char *s_arg = s21_NULL;
      if (!options.suppress_assignment) s_arg = va_arg(args, char *);

      int i = 0;
      while (*str_ptr && !s21_isspace(*str_ptr) &&
             (options.width < 0 || i < options.width)) {
        if (!options.suppress_assignment) s_arg[i] = *str_ptr;
        str_ptr++;
        i++;
      }
      if (i > 0) {
        if (!options.suppress_assignment) s_arg[i] = '\0';
        success = 1;
      }

    } else if (specifier == 'c') {
      char *c_arg = s21_NULL;
      if (!options.suppress_assignment) c_arg = va_arg(args, char *);

      int read_width = (options.width > 0) ? options.width : 1;
      int i = 0;
      while (*str_ptr && i < read_width) {
        if (!options.suppress_assignment) c_arg[i] = *str_ptr;
        str_ptr++;
        i++;
      }
      if (i == read_width) success = 1;

    } else if (s21_strchr("feEgG", specifier)) {
      skip_whitespace(&str_ptr);
      long double val = 0;
      success = parse_long_double(&str_ptr, options.width, &val);
      if (success && !options.suppress_assignment) {
        void *ptr = va_arg(args, void *);
        if (options.length == 'L')
          *(long double *)ptr = val;
        else if (options.length == 'l')
          *(double *)ptr = (double)val;
        else
          *(float *)ptr = (float)val;
      }
    } else if (specifier == '%') {
      if (*str_ptr == '%') {
        str_ptr++;
        success = 1;
      }
    } else if (specifier == 'n') {
      if (!options.suppress_assignment) {
        int *n_arg = va_arg(args, int *);
        *n_arg = str_ptr - str;
      }

      format_ptr++;
      continue;
    } else if (specifier == 'p') {
      skip_whitespace(&str_ptr);
      if (s21_strncmp(str_ptr, "0x", 2) == 0 ||
          s21_strncmp(str_ptr, "0X", 2) == 0) {
        str_ptr += 2;
        if (options.width > 0) options.width -= 2;
      }

      long long val = 0;
      success = parse_integer(&str_ptr, options.width, 16, &val);

      if (success && !options.suppress_assignment) {
        void **ptr = va_arg(args, void **);
        *ptr = (void *)val;
      }
    }

    if (success) {
      if (!options.suppress_assignment && specifier != '%') assigned_count++;
    } else
      break;

    format_ptr++;
  }

  va_end(args);
  return assigned_count;
}