#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  int plus;
  int minus;
  int space;
  int hash;
  int zero;
  int width;
  int precision;
  char length;
  char specifier;
} s21_Options;

static void parse_format_options(const char **format, s21_Options *options,
                                 va_list *args);
static void handle_specifier(char *buffer, s21_Options *options, va_list *args);
static void format_output_string(char *dest, char *src, s21_Options *options);
static void s21_ull_to_base_str(char *buffer, unsigned long long num, int base,
                                int is_upper);
static void s21_ld_to_str(char *buffer, long double num, s21_Options *options);
static void reverse_string(char *str);

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  char *str_start = str;
  *str = '\0';

  while (*format) {
    if (*format == '%') {
      format++;
      s21_Options options = {0};
      options.precision = -1;

      parse_format_options(&format, &options, &args);

      char temp_buffer[2048] = {0};
      handle_specifier(temp_buffer, &options, &args);
      s21_strncat(str, temp_buffer, sizeof(temp_buffer) - 1);

    } else {
      if (*format == '%' && *(format + 1) == '%') {
        format++;
      }
      s21_strncat(str, format, 1);
    }
    format++;
  }

  va_end(args);
  return s21_strlen(str_start);
}

static void parse_format_options(const char **format, s21_Options *options,
                                 va_list *args) {
  while (s21_strchr("-+ #0", **format)) {
    if (**format == '-') options->minus = 1;
    if (**format == '+') options->plus = 1;
    if (**format == ' ') options->space = 1;
    if (**format == '#') options->hash = 1;
    if (**format == '0') options->zero = 1;
    (*format)++;
  }
  if (**format == '*') {
    options->width = va_arg(*args, int);
    (*format)++;
  } else {
    while (**format >= '0' && **format <= '9') {
      options->width = options->width * 10 + (**format - '0');
      (*format)++;
    }
  }
  if (**format == '.') {
    (*format)++;
    options->precision = 0;
    if (**format == '*') {
      options->precision = va_arg(*args, int);
      (*format)++;
    } else {
      while (**format >= '0' && **format <= '9') {
        options->precision = options->precision * 10 + (**format - '0');
        (*format)++;
      }
    }
  }
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    options->length = **format;
    (*format)++;
  }
  options->specifier = **format;
}

static void handle_specifier(char *buffer, s21_Options *options,
                             va_list *args) {
  char temp_str[1024] = {0};

  switch (options->specifier) {
    case 'd':
    case 'i': {
      long long val = 0;
      if (options->length == 'l')
        val = va_arg(*args, long);
      else if (options->length == 'h')
        val = (short)va_arg(*args, int);
      else
        val = va_arg(*args, int);
      if (val < 0) {
        s21_strncat(temp_str, "-", 1);
        val = -val;
      } else if (options->plus) {
        s21_strncat(temp_str, "+", 1);
      } else if (options->space) {
        s21_strncat(temp_str, " ", 1);
      }
      s21_ull_to_base_str(temp_str + s21_strlen(temp_str), val, 10, 0);
      break;
    }
    case 'u':
    case 'o':
    case 'x':
    case 'X': {
      unsigned long long val = 0;
      if (options->length == 'l')
        val = va_arg(*args, unsigned long);
      else if (options->length == 'h')
        val = (unsigned short)va_arg(*args, unsigned int);
      else
        val = va_arg(*args, unsigned int);
      int base = 10;
      if (options->specifier == 'o')
        base = 8;
      else if (options->specifier == 'x' || options->specifier == 'X')
        base = 16;
      if (options->hash && val != 0) {
        if (base == 8)
          s21_strncat(temp_str, "0", 1);
        else if (base == 16)
          s21_strncat(temp_str, (options->specifier == 'X' ? "0X" : "0x"), 2);
      }
      s21_ull_to_base_str(temp_str + s21_strlen(temp_str), val, base,
                          (options->specifier == 'X'));
      break;
    }
    case 'c': {
      temp_str[0] = va_arg(*args, int);
      temp_str[1] = '\0';
      break;
    }
    case 's': {
      char *s_val = va_arg(*args, char *);
      s21_strncpy(temp_str, (s_val == s21_NULL ? "(null)" : s_val),
                  sizeof(temp_str) - 1);
      break;
    }
    case 'p': {
      s21_strncat(temp_str, "0x", 2);
      s21_ull_to_base_str(temp_str + 2,
                          (unsigned long long)va_arg(*args, void *), 16, 0);
      break;
    }
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G': {
      long double val = options->length == 'L' ? va_arg(*args, long double)
                                               : va_arg(*args, double);
      s21_ld_to_str(temp_str, val, options);
      break;
    }
    case 'n': {
      int *n_ptr = va_arg(*args, int *);
      *n_ptr = s21_strlen(buffer);
      return;
    }
    case '%': {
      temp_str[0] = '%';
      temp_str[1] = '\0';
      break;
    }
  }
  format_output_string(buffer, temp_str, options);
}

static void format_output_string(char *dest, char *src, s21_Options *options) {
  char temp[1024] = {0};
  s21_strncpy(temp, src, sizeof(temp) - 1);

  if (options->specifier == 's' && options->precision >= 0) {
    temp[options->precision] = '\0';
  } else if (s21_strchr("diuoxX", options->specifier)) {
    if (options->precision == 0 && s21_strncmp(temp, "0", 1) == 0)
      temp[0] = '\0';

    char *num_start = temp;
    if (*num_start == '-' || *num_start == '+' || *num_start == ' ')
      num_start++;

    int num_len = s21_strlen(num_start);
    if (options->precision > num_len) {
      int diff = options->precision - num_len;
      s21_memmove(num_start + diff, num_start, num_len + 1);
      s21_memset(num_start, '0', diff);
    }
  }

  int len = s21_strlen(temp);
  int pad_len = options->width > len ? options->width - len : 0;

  if (pad_len <= 0) {
    s21_strncat(dest, temp, sizeof(temp) - 1);
    return;
  }

  char pad_char = (options->zero && !options->minus) ? '0' : ' ';

  if (options->minus) {
    s21_strncat(dest, temp, sizeof(temp) - 1);
    s21_memset(dest + len, ' ', pad_len);
    dest[len + pad_len] = '\0';
  } else {
    if (pad_char == '0' && s21_strchr("+- ", temp[0])) {
      s21_strncat(dest, &temp[0], 1);
      s21_memmove(temp, temp + 1, s21_strlen(temp));
    }
    s21_memset(dest + s21_strlen(dest), pad_char, pad_len);
    s21_strncat(dest, temp, sizeof(temp) - 1);
  }
}

static void reverse_string(char *str) {
  int len = s21_strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = temp;
  }
}

static void s21_ull_to_base_str(char *buffer, unsigned long long num, int base,
                                int is_upper) {
  if (num == 0) {
    s21_strncpy(buffer, "0", 1);
    return;
  }
  char *p = buffer;
  while (num > 0) {
    int rem = num % base;
    *p++ = (rem > 9) ? (rem - 10) + (is_upper ? 'A' : 'a') : rem + '0';
    num /= base;
  }
  *p = '\0';
  reverse_string(buffer);
}

static void s21_ld_to_str(char *buffer, long double num, s21_Options *options) {
  if (num != num) {
    s21_strncpy(buffer, "nan", 3);
    return;
  }
  if (num == 1.0 / 0.0) {
    s21_strncpy(buffer, "inf", 3);
    return;
  }
  if (num == -1.0 / 0.0) {
    s21_strncpy(buffer, "-inf", 4);
    return;
  }

  char *p = buffer;
  if (num < 0) {
    *p++ = '-';
    num = -num;
  } else if (options->plus) {
    *p++ = '+';
  } else if (options->space) {
    *p++ = ' ';
  }

  int precision = (options->precision < 0) ? 6 : options->precision;
  unsigned long long int_part = (unsigned long long)num;
  long double frac_part = num - int_part;

  long double rounder = 0.5;
  for (int i = 0; i < precision; i++) rounder /= 10.0;
  frac_part += rounder;

  if (frac_part >= 1.0) {
    int_part++;
    frac_part -= 1.0;
  }

  s21_ull_to_base_str(p, int_part, 10, 0);
  p += s21_strlen(p);

  if (precision > 0 || options->hash) {
    *p++ = '.';
    for (int i = 0; i < precision; i++) {
      frac_part *= 10;
      int digit = (int)frac_part;
      *p++ = digit + '0';
      frac_part -= digit;
    }
  }
  *p = '\0';
}