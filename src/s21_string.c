#include "s21_string.h"

// static const char *s21_macos_errors[] = {
//     "Undefined error: 0",
//     "Operation not permitted",
//     "No such file or directory",
//     "No such process",
//     "Interrupted system call",
//     "Input/output error",
//     "Device not configured",
//     "Argument list too long",
//     "Exec format error",
//     "Bad file descriptor",
//     "No child processes",
//     "Resource deadlock avoided",
//     "Cannot allocate memory",
//     "Permission denied",
//     "Bad address",
//     "Block device required",
//     "Resource busy",
//     "File exists",
//     "Cross-device link",
//     "Operation not supported by device",
//     "Not a directory",
//     "Is a directory",
//     "Invalid argument",
//     "Too many open files in system",
//     "Too many open files",
//     "Inappropriate ioctl for device",
//     "Text file busy",
//     "File too large",
//     "No space left on device",
//     "Illegal seek",
//     "Read-only file system",
//     "Too many links",
//     "Broken pipe",
//     "Numerical argument out of domain",
//     "Result too large",
//     "Resource temporarily unavailable",
//     "Operation now in progress",
//     "Operation already in progress",
//     "Socket operation on non-socket",
//     "Destination address required",
//     "Message too long",
//     "Protocol wrong type for socket",
//     "Protocol not available",
//     "Protocol not supported",
//     "Socket type not supported",
//     "Operation not supported",
//     "Protocol family not supported",
//     "Address family not supported by protocol family",
//     "Address already in use",
//     "Can't assign requested address",
//     "Network is down",
//     "Network is unreachable",
//     "Network dropped connection on reset",
//     "Software caused connection abort",
//     "Connection reset by peer",
//     "No buffer space available",
//     "Socket is already connected",
//     "Socket is not connected",
//     "Can't send after socket shutdown",
//     "Too many references: can't splice",
//     "Operation timed out",
//     "Connection refused",
//     "Too many levels of symbolic links",
//     "File name too long",
//     "Host is down",
//     "No route to host",
//     "Directory not empty",
//     "Too many processes",
//     "Too many users",
//     "Disc quota exceeded",
//     "Stale NFS file handle",
//     "Too many levels of remote in path",
//     "RPC struct is bad",
//     "RPC version wrong",
//     "RPC prog. not avail",
//     "Program version wrong",
//     "Bad procedure for program",
//     "No locks available",
//     "Function not implemented",
//     "Inappropriate file type or format",
//     "Authentication error",
//     "Need authenticator",
//     "Device power is off",
//     "Device error",
//     "Value too large to be stored in data type",
//     "Bad executable (or shared library)",
//     "Bad CPU type in executable",
//     "Shared library version mismatch",
//     "Malformed Mach-o file",
//     "Operation canceled",
//     "Identifier removed",
//     "No message of desired type",
//     "Illegal byte sequence",
//     "Attribute not found",
//     "Bad message",
//     "EMULTIHOP (Reserved)",
//     "No message available on STREAM",
//     "ENOLINK (Reserved)",
//     "No STREAM resources",
//     "Not a STREAM",
//     "Protocol error",
//     "STREAM ioctl timeout",
//     "Operation not supported on socket",
//     "Policy not found",
//     "State not recoverable",
//     "Previous owner died",
//     "Interface output queue is full"};
//
// static const char *s21_linux_errors[] = {
//     "Success",
//     "Operation not permitted",
//     "No such file or directory",
//     "No such process",
//     "Interrupted system call",
//     "Input/output error",
//     "No such device or address",
//     "Argument list too long",
//     "Exec format error",
//     "Bad file descriptor",
//     "No child processes",
//     "Resource temporarily unavailable",
//     "Cannot allocate memory",
//     "Permission denied",
//     "Bad address",
//     "Block device required",
//     "Device or resource busy",
//     "File exists",
//     "Invalid cross-device link",
//     "No such device",
//     "Not a directory",
//     "Is a directory",
//     "Invalid argument",
//     "Too many open files in system",
//     "Too many open files",
//     "Inappropriate ioctl for device",
//     "Text file busy",
//     "File too large",
//     "No space left on device",
//     "Illegal seek",
//     "Read-only file system",
//     "Too many links",
//     "Broken pipe",
//     "Numerical argument out of domain",
//     "Numerical result out of range",
//     "Resource deadlock avoided",
//     "File name too long",
//     "No locks available",
//     "Function not implemented",
//     "Directory not empty",
//     "Too many levels of symbolic links",
//     "Unknown error 41",
//     "No message of desired type",
//     "Identifier removed",
//     "Channel number out of range",
//     "Level 2 not synchronized",
//     "Level 3 halted",
//     "Level 3 reset",
//     "Link number out of range",
//     "Protocol driver not attached",
//     "No CSI structure available",
//     "Level 2 halted",
//     "Invalid exchange",
//     "Invalid request descriptor",
//     "Exchange full",
//     "No anode",
//     "Invalid request code",
//     "Invalid slot",
//     "Unknown error 58",
//     "Bad font file format",
//     "Device not a stream",
//     "No data available",
//     "Timer expired",
//     "Out of streams resources",
//     "Machine is not on the network",
//     "Package not installed",
//     "Object is remote",
//     "Link has been severed",
//     "Advertise error",
//     "Srmount error",
//     "Communication error on send",
//     "Protocol error",
//     "Multihop attempted",
//     "RFS specific error",
//     "Bad message",
//     "Value too large for defined data type",
//     "Name not unique on network",
//     "File descriptor in bad state",
//     "Remote address changed",
//     "Can not access a needed shared library",
//     "Accessing a corrupted shared library",
//     ".lib section in a.out corrupted",
//     "Attempting to link in too many shared libraries",
//     "Cannot exec a shared library directly",
//     "Invalid or incomplete multibyte or wide character",
//     "Interrupted system call should be restarted",
//     "Streams pipe error",
//     "Too many users",
//     "Socket operation on non-socket",
//     "Destination address required",
//     "Message too long",
//     "Protocol wrong type for socket",
//     "Protocol not available",
//     "Protocol not supported",
//     "Socket type not supported",
//     "Operation not supported",
//     "Protocol family not supported",
//     "Address family not supported by protocol",
//     "Address already in use",
//     "Cannot assign requested address",
//     "Network is down",
//     "Network is unreachable",
//     "Network dropped connection on reset",
//     "Software caused connection abort",
//     "Connection reset by peer",
//     "No buffer space available",
//     "Transport endpoint is already connected",
//     "Transport endpoint is not connected",
//     "Cannot send after transport endpoint shutdown",
//     "Too many references: cannot splice",
//     "Connection timed out",
//     "Connection refused",
//     "Host is down",
//     "No route to host",
//     "Operation already in progress",
//     "Operation now in progress",
//     "Stale file handle",
//     "Structure needs cleaning",
//     "Not a XENIX named type file",
//     "No XENIX semaphores available",
//     "Is a named type file",
//     "Remote I/O error",
//     "Disk quota exceeded",
//     "No medium found",
//     "Wrong medium type",
//     "Operation canceled",
//     "Required key not available",
//     "Key has expired",
//     "Key has been revoked",
//     "Key was rejected by service",
//     "Owner died",
//     "State not recoverable",
//     "Operation not possible due to RF-kill",
//     "Memory page has hardware error"};

#if defined(__APPLE__)
#define S21_ERR_COUNT 107
static const char *S21_ERRORS[S21_ERR_COUNT] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"

};

#elif defined(__linux__)
#define S21_ERR_COUNT 134
static const char *S21_ERRORS[S21_ERR_COUNT] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#endif
void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (!str) return s21_NULL;
  const unsigned char *string = (const unsigned char *)str;
  for (s21_size_t i = 0; i < n; ++i) {
    if (string[i] == (unsigned char)c) {
      return (void *)(string + i);
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;
  for (s21_size_t i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      return (int)(s1[i] - s2[i]);
    }
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest == s21_NULL || src == s21_NULL) return s21_NULL;
  char *d = (char *)dest;
  const char *s = (const char *)src;
  for (s21_size_t i = 0; i < n; ++i) {
    d[i] = s[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (!str) return s21_NULL;
  unsigned char *data = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; ++i) {
    data[i] = (unsigned char)c;
  }
  return str;
}

// String functions
char *s21_strchr(const char *str, int c) {
  while (*str) {
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  return c == '\0' ? (char *)str : s21_NULL;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  if (!str1 || !str2) return s21_NULL;
  for (const char *c1 = str1; *c1 != '\0'; ++c1) {
    for (const char *c2 = str2; *c2 != '\0'; ++c2) {
      if (*c1 == *c2) {
        return (char *)c1;
      }
    }
  }
  return s21_NULL;
}
char *s21_strrchr(const char *str, int c) {
  if (!str) return s21_NULL;
  const char *last = s21_NULL;
  for (const char *chr = str;; ++chr) {
    if (*chr == c) {
      last = chr;
    }
    if (*chr == '\0') {
      break;
    }
  }
  return (char *)last;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (!str1 || !str2) return -1;
  for (s21_size_t i = 0; i < n; ++i) {
    unsigned char c1 = (unsigned char)str1[i];
    unsigned char c2 = (unsigned char)str2[i];
    if (c1 != c2) {
      return (c1 - c2);
    }
    if (c1 == '\0' || c2 == '\0') {
      break;
    }
  }
  return 0;
}

// String manipulation functions
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (!dest || !src) return s21_NULL;
  s21_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  while (i < n) {
    dest[i++] = '\0';
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *d = dest;
  while (*d) d++;
  for (s21_size_t i = 0; i < n && src[i] != '\0'; i++) {
    *d++ = src[i];
  }
  *d = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  while (str1[len]) {
    for (s21_size_t j = 0; str2[j]; j++) {
      if (str1[len] == str2[j]) {
        return len;
      }
    }
    len++;
  }
  return len;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *p1, *p2;

  for (p1 = str1; *p1 != '\0'; ++p1) {
    for (p2 = str2; *p2 != '\0'; ++p2) {
      if (*p1 == *p2) break;
    }
    if (*p2 == '\0') break;
    ++count;
  }

  return count;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str && str[length]) {
    length++;
  }
  return length;
}

void *s21_to_upper(const char *str) {
  if (!str) return s21_NULL;
  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc(len + 1);
  if (result) {
    for (s21_size_t i = 0; i < len; i++) {
      result[i] =
          (str[i] >= 'a' && str[i] <= 'z') ? (str[i] - 'a' + 'A') : str[i];
    }
    result[len] = '\0';
  }
  return result;
}

void *s21_to_lower(const char *str) {
  if (!str) return s21_NULL;
  s21_size_t len = s21_strlen(str);
  char *result = (char *)malloc(len + 1);
  if (result) {
    for (s21_size_t i = 0; i < len; i++) {
      result[i] =
          (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
    }
    result[len] = '\0';
  }
  return result;
}

char *s21_strerror(int errnum) {
  static char unknown_error[50];

  if (errnum >= 0 && errnum < S21_ERR_COUNT) {
    return (char *)S21_ERRORS[errnum];
  }

  s21_sprintf(unknown_error, "Unknown error %d", errnum);
  return unknown_error;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) return s21_NULL;
  if (!trim_chars || *trim_chars == '\0') {
    s21_size_t len = s21_strlen(src);
    char *copy = (char *)malloc(len + 1);
    if (!copy) return s21_NULL;
    s21_memcpy(copy, src, len + 1);
    return copy;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src);

  while (*start && s21_strchr(trim_chars, *start)) {
    start++;
  }

  while (end > start && s21_strchr(trim_chars, *(end - 1))) {
    end--;
  }

  s21_size_t new_len = end - start;
  char *trimmed_str = (char *)malloc(new_len + 1);
  if (!trimmed_str) return s21_NULL;

  s21_memcpy(trimmed_str, start, new_len);
  trimmed_str[new_len] = '\0';

  return trimmed_str;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (!haystack || !needle) return s21_NULL;
  if (!*needle) return (char *)haystack;

  for (const char *h = haystack; *h; h++) {
    const char *n = needle;
    const char *h_start = h;
    while (*h && *n && *h == *n) {
      h++;
      n++;
    }
    if (!*n) return (char *)h_start;
    h = h_start;
  }
  return s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *next = s21_NULL;

  if (str) {
    next = str;
  } else if (!next) {
    return s21_NULL;
  }

  str = next + s21_strspn(next, delim);
  next = str + s21_strcspn(str, delim);

  if (next == str) {
    return next = s21_NULL;
  }

  if (*next) {
    *next++ = '\0';
  } else {
    next = s21_NULL;
  }

  return str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str || start_index > s21_strlen(src)) return s21_NULL;

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  s21_size_t tempStringLength = src_len + str_len + 1;

  char *tempString = (char *)malloc(tempStringLength);
  if (!tempString) return s21_NULL;

  s21_size_t i;
  for (i = 0; i < start_index; i++) {
    tempString[i] = src[i];
  }

  for (s21_size_t j = 0; j < str_len; j++) {
    tempString[i++] = str[j];
  }

  for (s21_size_t k = start_index; k < src_len; k++) {
    tempString[i++] = src[k];
  }
  tempString[tempStringLength - 1] = '\0';

  return tempString;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (d <= s || d >= s + n) {
    for (s21_size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else {
    for (s21_size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }

  return dest;
}
