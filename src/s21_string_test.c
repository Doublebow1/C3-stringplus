#include "s21_string.h"

#include <check.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

START_TEST(s21_memchr_test) {
  char test1[] = "123456";
  char test2 = '4';
  char test3 = '7';
  char test4[] = "hello/\0";
  char test5[] = "h";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 6),
                    (unsigned long)memchr(test1, test3, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 6),
                    (unsigned long)memchr(test4, test6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 6),
                    (unsigned long)memchr(test4, test8, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 6),
                    (unsigned long)memchr(test4, test9, 6));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "Apple Pay Money Day";
  char test2[] = "Apple with worm";
  char test3[] = "\0";
  char test4[] = "gud\0 job";
  char test5[] = "gud\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16) < 0,
                    memcmp(test1, test2, 16) < 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_2[4] = "<<<";
  char test_4[2] = "5";
  char test_44[2] = "5";
  char test_5[] = "";

  ck_assert_str_eq(s21_strncat(test_2, test_4, 1), "<<<5");
  ck_assert_str_eq(s21_strncat(test_44, test_5, 0), strncat(test_4, test_5, 0));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '3', 10),
                    (unsigned long)memchr(test1, '3', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '/', 8),
                    (unsigned long)memchr(test1, '/', 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '0', 4),
                    (unsigned long)memchr(test1, '0', 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '1', 3),
                    (unsigned long)memchr(test2, '1', 3));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "0123456789";
  char test2[] = "9876";
  char test3[] = "LOST: 4-8-15-16-23-42";
  char test4[] = "1234567890";
  char test5[] = "0/";
  char test6[] = "%%\\#";
  char test7[] = " ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *test1 = s21_strerror(0);
  char *test2 = strerror(0);
  char *test3 = s21_strerror(2147483647);
  char *test4 = strerror(2147483647);

  ck_assert_str_eq(test1, test2);
  ck_assert_str_eq(test3, test4);
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str1[] = "test of string";
  char dest1[15] = "";

  char str2[] = "test\0";
  char dest2[5] = "";

  char str3[] = "test ";
  char dest3[] = "crushcrush";

  ck_assert_str_eq(s21_strncpy(dest1, str1, 5), strncpy(dest1, str1, 5));
  ck_assert_str_eq(s21_strncpy(dest2, str2, 4), strncpy(dest2, str2, 4));
  ck_assert_str_eq(s21_strncpy(dest3, str3, 4), strncpy(dest3, str3, 4));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0,
                   strncmp(str1, str2, 3) == 0);
}
END_TEST
START_TEST(s21_insert_test) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 15);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 10);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 25);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    char *expected_trimmed =
        "ello, worl";  // This is the expected result after trimming
    ck_assert_str_eq(trimmed_str, expected_trimmed);
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");  // Expected result is an empty string
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");  // Expected result is an empty string
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(str_to_trim, empty_format);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str,
                     str_to_trim);  // Expected result is the original string
    free(trimmed_str);
  }

  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str ==
            s21_NULL);  // If NULL is passed, it should return NULL

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    char *expected_trimmed2 =
        "Hello, world!";  // This is the expected result after trimming
    ck_assert_str_eq(trimmed_str, expected_trimmed2);
    free(trimmed_str);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char str1[] = "hella hello motherfucker";
  char str2[] = "pRiVeT";

  char *new_str = s21_to_upper(str1);

  if (new_str) {
    ck_assert_str_eq(new_str, "HELLA HELLO MOTHERFUCKER");
    free(new_str);
  }

  new_str = s21_to_upper(str2);

  if (new_str) {
    ck_assert_str_eq(new_str, "PRIVET");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "hella HELLO motherfucker";
  char str2[] = "pRiVeT";

  char *new_str = s21_to_lower(str1);

  if (new_str) {
    ck_assert_str_eq(new_str, "hella hello motherfucker");
    free(new_str);
  }

  new_str = s21_to_lower(str2);

  if (new_str) {
    ck_assert_str_eq(new_str, "privet");
    free(new_str);
  }
}
END_TEST

START_TEST(test_s21_sprintf_prc_test) {
  char str[80];
  char str_orig[80];

  int res_1 = s21_sprintf(str, "%%");
  int res_1_orig = sprintf(str_orig, "%%");
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10%");

  ck_assert_int_eq(res_2, 10);
  ck_assert_str_eq(str, "         %");

  int res_5 = s21_sprintf(str, "abc%%defg");
  int res_5_orig = sprintf(str_orig, "abc%%defg");

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "Hello";
  char c = 'X';
  char d = 'Y';
  int result1 = s21_sprintf(str, format_str1, c);
  int result_origin1 = sprintf(str_origin, format_str1, c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "Hello, %c %c";
  int result2 = s21_sprintf(str, format_str2, c, d);
  int result_origin2 = sprintf(str_origin, format_str2, c, d);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  char *s1 = "world!";
  char *s2 = "Hello world!";
  const char *format_str3 = "Hello, %10s %10.15s";
  int result3 = s21_sprintf(str, format_str3, s1, s2);
  int result_origin3 = sprintf(str_origin, format_str3, s1, s2);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);

  short int short_num = 123;
  long int long_num = 1234567890L;

  s21_sprintf(str, "%hd", short_num);
  sprintf(str_origin, "%hd", short_num);
  ck_assert_str_eq(str, str_origin);

  s21_sprintf(str, "%ld", long_num);
  sprintf(str_origin, "%ld", long_num);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(test_s21_sprintf_c_test) {
  char str[80];
  char str1[80];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(test_s21_sprintf_s_test) {
  char str[80];
  char str1[80];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%-11.10s", x);
  int res1 = sprintf(str1, "%-11.10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%11.8s", x);
  res1 = sprintf(str1, "%11.8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(test_s21_sprintf_u_test) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%0u", a);
  int res_4_orig = sprintf(str_orig, "%0u", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-u", a);
  int res_5_orig = sprintf(str_orig, "%-u", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%u", a);
  int res_6_orig = sprintf(str_orig, "%u", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%5u", a);
  int res_7_orig = sprintf(str_orig, "%5u", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%05u", a);
  int res_8_orig = sprintf(str_orig, "%05u", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5u", a);
  int res_9_orig = sprintf(str_orig, "%-5u", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%.5u", a);
  int res_10_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%.5u", a);
  int res_11_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%-.5u", a);
  int res_12_orig = sprintf(str_orig, "%-.5u", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%-10.5u", a);
  int res_13_orig = sprintf(str_orig, "%-10.5u", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%3.5u", a);
  int res_14_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%-3.5u", a);
  int res_15_orig = sprintf(str_orig, "%-3.5u", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "%6.2u", a);
  int res_16_orig = sprintf(str_orig, "%6.2u", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%3.2u", a);
  int res_17_orig = sprintf(str_orig, "%3.2u", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%01u", a);
  int res_18_orig = sprintf(str_orig, "%01u", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%hu", (unsigned short)a);
  int res_19_orig = sprintf(str_orig, "%hu", (unsigned short)a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%lu", (unsigned long)a);
  int res_20_orig = sprintf(str_orig, "%lu", (unsigned long)a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test) {
  char str[80];
  char str_orig[80];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%05d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%hd", (unsigned short)a);
  int res_26_orig = sprintf(str_orig, "%hd", (unsigned short)a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%ld", (unsigned long)a);
  int res_27_orig = sprintf(str_orig, "%ld", (unsigned long)a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_2) {
  char str[80];
  char str_orig[80];
  int a = -23454546;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_3) {
  char str[80];
  char str_orig[80];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);

  int res_30 = s21_sprintf(str, "%+05d", a);
  int res_30_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_30, res_30_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_4) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_5) {
  char str[80];
  char str_orig[80];
  int a = -2344;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_6) {
  char str[80];
  char str_orig[80];
  int a = 23;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%+0d", a);
  int res_5_orig = sprintf(str_orig, "%+0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-+d", a);
  int res_6_orig = sprintf(str_orig, "%-+d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-+5d", a);
  int res_11_orig = sprintf(str_orig, "%-+5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-+.5d", a);
  int res_18_orig = sprintf(str_orig, "%-+.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-+10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-+10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-+3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-+3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_sprintf_d_test_0) {
  char str[80];
  char str_orig[80];
  int a = 0;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%05d", a);
  int res_5_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_s21_memchr) {
  char str[] = "abcdef";
  ck_assert_ptr_eq(s21_memchr(str, 'c', 6), memchr(str, 'c', 6));
  ck_assert_ptr_eq(s21_memchr(str, '~', 6), memchr(str, '~', 6));
  ck_assert_ptr_eq(s21_memchr(str, 'f', 6), memchr(str, 'f', 6));
  ck_assert_ptr_eq(s21_memchr(str, 'f', 7), memchr(str, 'f', 7));
  ck_assert_ptr_eq(s21_memchr(str, 'a', 1), memchr(str, 'a', 1));
  ck_assert_ptr_eq(s21_memchr("", 'a', 1), memchr("", 'a', 1));
  ck_assert_ptr_eq(s21_memchr(NULL, 'a', 1), NULL);
  ck_assert_ptr_eq(s21_memchr(str, 'z', 6), NULL);

  ck_assert_ptr_eq(s21_memchr("Hello world\0", 'o', 12),
                   memchr("Hello world\0", 'o', 12));
  ck_assert_ptr_eq(s21_memchr("Hello world\n\0", 'o', 14),
                   memchr("Hello world\n\0", 'o', 14));
  ck_assert_ptr_eq(s21_memchr("a\n\0", 'a', 3), memchr("a\n\0", 'a', 3));
  ck_assert_ptr_eq(s21_memchr(" \n\0", ' ', 3), memchr(" \n\0", ' ', 3));
  ck_assert_ptr_eq(s21_memchr(" \0", ' ', 2), memchr(" \0", ' ', 2));
  ck_assert_ptr_eq(s21_memchr("\n\0", '\n', 2), memchr("\n\0", '\n', 2));
  ck_assert_ptr_eq(s21_memchr("\0", '\0', 1), memchr("\0", '\0', 1));
}
END_TEST

START_TEST(test_s21_memcmp) {
  char str1[] = "abc";
  char str2[] = "abd";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
  ck_assert_int_eq(s21_memcmp(str1, str1, 3), memcmp(str1, str1, 3));
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));

  ck_assert_int_eq(s21_memcmp("Hello world\0", "Hello world\0", 12),
                   memcmp("Hello world\0", "Hello world\0", 12));
  ck_assert_int_eq(s21_memcmp("Hello world\n\0", "Hello world\n\0", 14),
                   memcmp("Hello world\n\0", "Hello world\n\0", 14));
  ck_assert_int_eq(s21_memcmp("a\n\0", "a\n\0", 3),
                   memcmp("a\n\0", "a\n\0", 3));
  ck_assert_int_eq(s21_memcmp(" \n\0", " \n\0", 3),
                   memcmp(" \n\0", " \n\0", 3));
  ck_assert_int_eq(s21_memcmp(" \0", " \0", 2), memcmp(" \0", " \0", 2));
  ck_assert_int_eq(s21_memcmp("\n\0", "\n\0", 2), memcmp("\n\0", "\n\0", 2));
  ck_assert_int_eq(s21_memcmp("\0", "\0", 1), memcmp("\0", "\0", 1));
}
END_TEST

START_TEST(test_s21_memcpy) {
  char dest[15];
  char src[] = "test";
  ck_assert_str_eq(s21_memcpy(dest, src, 5), memcpy(dest, src, 5));
  char str[] = "abcdef";
  ck_assert_str_eq(s21_memcpy(str + 2, str, 3), memcpy(str + 2, str, 3));
  ck_assert_ptr_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));

  ck_assert_str_eq(s21_memcpy(dest, "Hello world\0", 13),
                   memcpy(dest, "Hello world\0", 13));
  ck_assert_str_eq(s21_memcpy(dest, "Hello world\n\0", 14),
                   memcpy(dest, "Hello world\n\0", 14));
  ck_assert_str_eq(s21_memcpy(dest, "a\n\0", 3), memcpy(dest, "a\n\0", 3));
  ck_assert_str_eq(s21_memcpy(dest, " \n\0", 3), memcpy(dest, " \n\0", 3));
  ck_assert_str_eq(s21_memcpy(dest, " \0", 2), memcpy(dest, " \0", 2));
  ck_assert_str_eq(s21_memcpy(dest, "\n\0", 2), memcpy(dest, "\n\0", 2));
  ck_assert_str_eq(s21_memcpy(dest, "\0", 1), memcpy(dest, "\0", 1));
}
END_TEST

START_TEST(test_s21_memset) {
  char str[15] = "abcdef";
  ck_assert_str_eq(s21_memset(str, 'x', 3), memset(str, 'x', 3));
  char str2[15] = "";
  ck_assert_str_eq(s21_memset(str2, 'x', 3), memset(str2, 'x', 3));
  ck_assert_str_eq(s21_memset(str, 'x', 13), memset(str, 'x', 13));
  ck_assert_str_eq(s21_memset(str2, 'y', 15), memset(str2, 'y', 15));
  ck_assert_str_eq(s21_memset(str, ' ', 1), memset(str, ' ', 1));
  ck_assert_str_eq(s21_memset(str, '\n', 2), memset(str, '\n', 2));
  ck_assert_str_eq(s21_memset(str, '\0', 1), memset(str, '\0', 1));
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_uint_eq(s21_strlen("randomtext"), 10);
  ck_assert_uint_eq(s21_strlen(""), 0);
  ck_assert_uint_eq(s21_strlen("123456789"), 9);
  ck_assert_uint_eq(s21_strlen("a b c"), 5);
  ck_assert_uint_eq(s21_strlen("qwerty!@#"), 9);
  ck_assert_uint_eq(s21_strlen("Hello world\0"), strlen("Hello world\0"));
  ck_assert_uint_eq(s21_strlen("Hello world\n\0"), strlen("Hello world\n\0"));
  ck_assert_uint_eq(s21_strlen("a\n\0"), strlen("a\n\0"));
  ck_assert_uint_eq(s21_strlen(" \n\0"), strlen(" \n\0"));
  ck_assert_uint_eq(s21_strlen(" \0"), strlen(" \0"));
  ck_assert_uint_eq(s21_strlen("\n\0"), strlen("\n\0"));
  ck_assert_uint_eq(s21_strlen("\0"), strlen("\0"));
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp("abc", "abc", 3), 0);
  ck_assert_int_ne(s21_strncmp("abc", "abcd", 4), 0);
  ck_assert_int_eq(s21_strncmp("abc!", "abc!", 4), 0);
  ck_assert_int_eq(s21_strncmp("Hello world\0", "Hello world\0", 12), 0);
  ck_assert_int_ne(s21_strncmp("Hello world\0", "Hello world\n\0", 12), 0);
  ck_assert_int_eq(s21_strncmp("a\n\0", "a\n\0", 3), 0);
  ck_assert_int_ne(s21_strncmp(" \n\0", " \0", 3), 0);
  ck_assert_int_eq(s21_strncmp(" \0", " \0", 2), 0);
  ck_assert_int_ne(s21_strncmp("\n\0", "\0", 2), 0);
  ck_assert_int_eq(s21_strncmp("\0", "\0", 1), 0);
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_ptr_eq(s21_strchr("abcdef", 'c'), strchr("abcdef", 'c'));
  ck_assert_ptr_eq(s21_strchr("abcdef", 'z'), strchr("abcdef", 'z'));
  ck_assert_ptr_eq(s21_strchr("abcdef", '\0'), strchr("abcdef", '\0'));
  ck_assert_ptr_eq(s21_strchr("abcabc", 'a'), strchr("abcabc", 'a'));
  ck_assert_ptr_eq(s21_strchr("Hello world\0", 'w'),
                   strchr("Hello world\0", 'w'));
  ck_assert_ptr_eq(s21_strchr("Hello world\0", '\0'),
                   strchr("Hello world\0", '\0'));
  ck_assert_ptr_eq(s21_strchr("a\n\0", '\n'), strchr("a\n\0", '\n'));
  ck_assert_ptr_eq(s21_strchr(" \n\0", '\n'), strchr(" \n\0", '\n'));
  ck_assert_ptr_eq(s21_strchr(" \0", '\0'), strchr(" \0", '\0'));
  ck_assert_ptr_eq(s21_strchr("\n\0", '\n'), strchr("\n\0", '\n'));
  ck_assert_ptr_eq(s21_strchr("\0", '\0'), strchr("\0", '\0'));
}
END_TEST

START_TEST(test_s21_strncpy) {
  char dest[10] = {0};
  s21_strncpy(dest, "qwerty", 6);
  ck_assert_str_eq(dest, "qwerty");
  s21_strncpy("A", "A", 0);
  ck_assert_str_eq("A", "A");
  s21_strncpy(dest, "qwerty", 10);
  ck_assert_str_eq(dest, "qwerty");
  char dest1[15] = {0};
  s21_strncpy(dest1, "Hello world\0", 12);
  ck_assert_str_eq(dest1, "Hello world");
  char dest2[15] = {0};
  s21_strncpy(dest2, "Hello world\0", 15);
  ck_assert_str_eq(dest2, "Hello world\0");
  char dest3[15] = {0};
  s21_strncpy(dest3, "a\n\0", 3);
  ck_assert_str_eq(dest3, "a\n");
  char dest4[15] = {0};
  s21_strncpy(dest4, " \n\0", 4);
  ck_assert_str_eq(dest4, " \n");
  char dest5[15] = {0};
  s21_strncpy(dest5, " \0", 3);
  ck_assert_str_eq(dest5, " \0");
  char dest6[15] = {0};
  s21_strncpy(dest6, "\n\0", 2);
  ck_assert_str_eq(dest6, "\n");
  char dest7[15] = {0};
  s21_strncpy(dest7, "\0", 1);
  ck_assert_str_eq(dest7, "\0");
}
END_TEST

START_TEST(test_s21_strncat) {
  char dest1[20] = "qwerty";
  char dest2[20] = "qwerty";
  s21_strncat(dest1, " uiop", sizeof(dest1) - strlen(dest1) - 1);
  strncat(dest2, " uiop", sizeof(dest2) - strlen(dest2) - 1);
  ck_assert_str_eq(dest1, dest2);
  char dest3[20] = "";
  s21_strncat(dest3, "uiop", sizeof(dest3) - strlen(dest3) - 1);
  ck_assert_str_eq(dest3, "uiop");
  char dest4[20] = "qwerty";
  s21_strncat(dest4, "", sizeof(dest4) - strlen(dest4) - 1);
  ck_assert_str_eq(dest4, "qwerty");
}
END_TEST
START_TEST(test_s21_strcspn) {
  ck_assert_uint_eq(s21_strcspn("abcdef", "cd"), strcspn("abcdef", "cd"));
  ck_assert_uint_eq(s21_strcspn("abcdef", "xyz"), strcspn("abcdef", "xyz"));
  ck_assert_uint_eq(s21_strcspn("abcdef", "@!"), strcspn("abcdef", "@!"));
  ck_assert_uint_eq(s21_strcspn("Hello world\0", " \n"),
                    strcspn("Hello world\0", " \n"));
  ck_assert_uint_eq(s21_strcspn("a\n\0", "\n"), strcspn("a\n\0", "\n"));
  ck_assert_uint_eq(s21_strcspn(" \n\0", "\n"), strcspn(" \n\0", "\n"));
  ck_assert_uint_eq(s21_strcspn(" \0", "\0"), strcspn(" \0", "\0"));
  ck_assert_uint_eq(s21_strcspn("\n\0", "\n"), strcspn("\n\0", "\n"));
  ck_assert_uint_eq(s21_strcspn("\0", "\0"), strcspn("\0", "\0"));
}
END_TEST

START_TEST(test_s21_strerror) {
  ck_assert_str_eq(s21_strerror(2), strerror(2));
  ck_assert_str_eq(s21_strerror(100), "Network is down");
  ck_assert_str_eq(s21_strerror(-1), "Unknown error -1");
  ck_assert_str_eq(s21_strerror(89), "Destination address required");
  ck_assert_str_eq(s21_strerror(69), "Srmount error");
  ck_assert_str_eq(s21_strerror(24), "Too many open files");
  ck_assert_str_eq(s21_strerror(97),
                   "Address family not supported by protocol");
}
END_TEST

START_TEST(test_s21_to_upper) {
  ck_assert_str_eq(s21_to_upper("qwerty"), "QWERTY");
  ck_assert_str_eq(s21_to_upper("qwerty123!@#"), "QWERTY123!@#");
  ck_assert_str_eq(s21_to_upper("Hello world\0"), "HELLO WORLD\0");
  ck_assert_str_eq(s21_to_upper("a\nb\nc"), "A\nB\nC");
  ck_assert_str_eq(s21_to_upper(" \n\0"), " \n\0");
  ck_assert_str_eq(s21_to_upper(" \0"), " \0");
  ck_assert_str_eq(s21_to_upper("\n\0"), "\n\0");
  ck_assert_str_eq(s21_to_upper("\0"), "\0");
}
END_TEST

START_TEST(test_s21_to_lower) {
  ck_assert_str_eq(s21_to_lower("QWerTy"), "qwerty");
  ck_assert_str_eq(s21_to_lower("QWERTY123!@#"), "qwerty123!@#");
  ck_assert_str_eq(s21_to_lower("Hello World\0"), "hello world\0");
  ck_assert_str_eq(s21_to_lower("A\nB\nC"), "a\nb\nc");
  ck_assert_str_eq(s21_to_lower(" \n\0"), " \n\0");
  ck_assert_str_eq(s21_to_lower(" \0"), " \0");
  ck_assert_str_eq(s21_to_lower("\n\0"), "\n\0");
  ck_assert_str_eq(s21_to_lower("\0"), "\0");
}
END_TEST

START_TEST(test_s21_trim) {
  ck_assert_str_eq(s21_trim("  qwerty  ", " "), "qwerty");
  ck_assert_str_eq(s21_trim("qwerty", " "), "qwerty");
  ck_assert_str_eq(s21_trim("  Hello World\0  ", " "), "Hello World\0");
  ck_assert_str_eq(s21_trim("\n\nqwerty\n\n", "\n"), "qwerty");
  ck_assert_str_eq(s21_trim(" \n\0", " "), "\n\0");
  ck_assert_str_eq(s21_trim(" \0", " "), "\0");
  ck_assert_str_eq(s21_trim("\n\0", " "), "\n\0");
  ck_assert_str_eq(s21_trim("\0", " "), "\0");
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("qwerty123", "4"), strpbrk("qwerty123", "4"));
  ck_assert_ptr_eq(s21_strpbrk("check^21", "^"), strpbrk("check^21", "^"));
  ck_assert_ptr_eq(s21_strpbrk("suite%43", "%"), strpbrk("suite%43", "%"));
  ck_assert_ptr_eq(s21_strpbrk("", "a"), strpbrk("", "a"));
  ck_assert_ptr_eq(s21_strpbrk("abcdef", "xyz"), strpbrk("abcdef", "xyz"));
  ck_assert_ptr_eq(s21_strpbrk("Hello\nworld\0", "\n"),
                   strpbrk("Hello\nworld\0", "\n"));
  ck_assert_ptr_eq(s21_strpbrk("abc\0def", "\0"), strpbrk("abc\0def", "\0"));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("qwerty123", 'l'), strrchr("qwerty123", 'l'));
  ck_assert_ptr_eq(s21_strrchr("world!56", 'o'), strrchr("world!56", 'o'));
  ck_assert_ptr_eq(s21_strrchr("test@89", 't'), strrchr("test@89", 't'));
  ck_assert_ptr_eq(s21_strrchr("check^21", 'c'), strrchr("check^21", 'c'));
  ck_assert_ptr_eq(s21_strrchr("suite%43", 'e'), strrchr("suite%43", 'e'));
  ck_assert_ptr_eq(s21_strrchr("abcdef", '\0'), strrchr("abcdef", '\0'));
  ck_assert_ptr_eq(s21_strrchr("abcabc", 'a'), strrchr("abcabc", 'a'));
  ck_assert_ptr_eq(s21_strrchr("Hello\nworld\0", '\n'),
                   strrchr("Hello\nworld\0", '\n'));
  ck_assert_ptr_eq(s21_strrchr("abc\0def", '\0'), strrchr("abc\0def", '\0'));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_ptr_eq(s21_strstr("qwerty123", "lo"), strstr("qwerty123", "lo"));
  ck_assert_ptr_eq(s21_strstr("world!56", "wo"), strstr("world!56", "wo"));
  ck_assert_ptr_eq(s21_strstr("test@89", "es"), strstr("test@89", "es"));
  ck_assert_ptr_eq(s21_strstr("check^21", "ck"), strstr("check^21", "ck"));
  ck_assert_ptr_eq(s21_strstr("suite%43", "ui"), strstr("suite%43", "ui"));
  ck_assert_ptr_eq(s21_strstr("abcdef", NULL), NULL);
  ck_assert_ptr_eq(s21_strstr("world", "qwerty"), s21_NULL);
  ck_assert_ptr_eq(s21_strstr("", "nonempty"), s21_NULL);
  ck_assert_ptr_eq(s21_strstr("notempty", ""), (char *)"notempty");
  ck_assert_ptr_eq(s21_strstr("Hello\nworld\0", "\n"),
                   strstr("Hello\nworld\0", "\n"));
  ck_assert_ptr_eq(s21_strstr("abc\0def", "\0"), strstr("abc\0def", "\0"));
}
END_TEST
START_TEST(test_s21_strtok) {
  char str[] = "Hello, world! This is a test string.";
  char delim[] = " ,!";
  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "Hello");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "world");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "This");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "is");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "a");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "test");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "string.");
  token = s21_strtok(NULL, delim);
  ck_assert_ptr_eq(token, NULL);
  char str1[] = "";
  token = s21_strtok(str1, delim);
  ck_assert_ptr_eq(token, NULL);
  char str2[] = "abc:def:ghi";
  token = s21_strtok(str2, ":");
  ck_assert_str_eq(token, "abc");
  token = s21_strtok(NULL, ":");
  ck_assert_str_eq(token, "def");
  token = s21_strtok(NULL, ":");
  ck_assert_str_eq(token, "ghi");
  token = s21_strtok(NULL, ":");
  ck_assert_ptr_eq(token, NULL);
  char str3[] = "Hello\nworld";
  token = s21_strtok(str3, "\n");
  ck_assert_str_eq(token, "Hello");
  token = s21_strtok(NULL, "\n");
  ck_assert_str_eq(token, "world");
}
END_TEST

START_TEST(test_s21_insert) {
  char src[] = "abcdef";
  char *result;
  result = s21_insert(src, "123", 3);
  ck_assert_str_eq(result, "abc123def");
  free(result);
  ck_assert_ptr_eq(s21_insert(src, "123", 10), NULL);
  result = s21_insert(src, "xyz", 0);
  ck_assert_str_eq(result, "xyzabcdef");
  free(result);
  result = s21_insert(src, "###", 5);
  ck_assert_str_eq(result, "abcde###f");
  free(result);
  result = s21_insert(src, "xyz", 2);
  ck_assert_str_eq(result, "abxyzcdef");
  free(result);
}
END_TEST

START_TEST(test_s21_sprintf_flags) {
  char str1[100];
  char str2[100];
  int val = 123;

  ck_assert_int_eq(s21_sprintf(str1, "%+d", val), sprintf(str2, "%+d", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "% d", val), sprintf(str2, "% d", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%05d", val), sprintf(str2, "%05d", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
  char str1[100];
  char str2[100];

  ck_assert_int_eq(s21_sprintf(str1, "%%"), sprintf(str2, "%%"));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "100%%"), sprintf(str2, "100%%"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_float_negative) {
  char str1[100];
  char str2[100];
  float val = -123.456f;

  ck_assert_int_eq(s21_sprintf(str1, "%f", val), sprintf(str2, "%f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%+f", val), sprintf(str2, "%+f", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// SPRINTF TESTS
START_TEST(test_s21_sprintf_integer) {
  char str1[100];
  char str2[100];
  int val = 123456;
  int negative = -123456;
  short shrt = 123;
  long lng = 123456789L;

  ck_assert_int_eq(s21_sprintf(str1, "%d", val), sprintf(str2, "%d", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%10d", val), sprintf(str2, "%10d", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%-10d", val),
                   sprintf(str2, "%-10d", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%d", negative),
                   sprintf(str2, "%d", negative));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%hd", shrt), sprintf(str2, "%hd", shrt));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%ld", lng), sprintf(str2, "%ld", lng));
  ck_assert_str_eq(str1, str2);

  char str[80];
  char str_origin[80];

  s21_sprintf(str, "%d", INT_MAX);
  sprintf(str_origin, "%d", INT_MAX);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(test_s21_sprintf_unsigned) {
  char str1[100];
  char str2[100];
  unsigned int val = 123456;
  unsigned short ushrt = 123;
  unsigned long ulng = 123456789UL;

  ck_assert_int_eq(s21_sprintf(str1, "%u", val), sprintf(str2, "%u", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%10u", val), sprintf(str2, "%10u", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%hu", ushrt),
                   sprintf(str2, "%hu", ushrt));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%lu", ulng), sprintf(str2, "%lu", ulng));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_float) {
  char str1[100];
  char str2[100];
  float val = 123.456f;
  double dbl = 123456.789;

  ck_assert_int_eq(s21_sprintf(str1, "%f", val), sprintf(str2, "%f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%.2f", val), sprintf(str2, "%.2f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%10.2f", val),
                   sprintf(str2, "%10.2f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%lf", dbl), sprintf(str2, "%lf", dbl));
  ck_assert_str_eq(str1, str2);
  char str[80];
  char str_origin[80];
  double pi = 3.141592653589793;
  float half = 0.5f;

  s21_sprintf(str, "%.2f", pi);
  sprintf(str_origin, "%.2f", pi);
  ck_assert_str_eq(str, str_origin);

  s21_sprintf(str, "%10.5f", pi);
  sprintf(str_origin, "%10.5f", pi);
  ck_assert_str_eq(str, str_origin);

  s21_sprintf(str, "%f", half);
  sprintf(str_origin, "%f", half);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(test_s21_sprintf_char) {
  char str1[100];
  char str2[100];
  char c = 'X';

  ck_assert_int_eq(s21_sprintf(str1, "%c", c), sprintf(str2, "%c", c));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%5c", c), sprintf(str2, "%5c", c));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_string) {
  char str1[100];
  char str2[100];
  char *test_str = "test string";

  ck_assert_int_eq(s21_sprintf(str1, "%s", test_str),
                   sprintf(str2, "%s", test_str));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%15s", test_str),
                   sprintf(str2, "%15s", test_str));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%.5s", test_str),
                   sprintf(str2, "%.5s", test_str));
  ck_assert_str_eq(str1, str2);

  char str[80];
  char str_origin[80];
  char empty_str[] = "";
  char long_str[] = "This is a very very very very very long string!";

  s21_sprintf(str, "%s", empty_str);
  sprintf(str_origin, "%s", empty_str);
  ck_assert_str_eq(str, str_origin);

  s21_sprintf(str, "%10s", long_str);
  sprintf(str_origin, "%10s", long_str);
  ck_assert_str_eq(str, str_origin);

  s21_sprintf(str, "%s", long_str);
  sprintf(str_origin, "%s", long_str);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(test_s21_sprintf_zero_value) {
  char str1[100], str2[100];

  int zero = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%d", zero), sprintf(str2, "%d", zero));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%.0d", zero),
                   sprintf(str2, "%.0d", zero));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_s21_sprintf_float_signs) {
  char str1[100], str2[100];
  float val = 123.456f;

  ck_assert_int_eq(s21_sprintf(str1, "%+f", val), sprintf(str2, "%+f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "% f", val), sprintf(str2, "% f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%10f", val), sprintf(str2, "%10f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%+10f", val),
                   sprintf(str2, "%+10f", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_float_left_justify) {
  char str1[100], str2[100];
  float val = 123.456f;

  ck_assert_int_eq(s21_sprintf(str1, "%-10f", val),
                   sprintf(str2, "%-10f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%+-10f", val),
                   sprintf(str2, "%+-10f", val));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%- 10f", val),
                   sprintf(str2, "%- 10f", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_float_zero) {
  char str1[100], str2[100];
  float val = 0.1f;
  ck_assert_int_eq(s21_sprintf(str1, "%05.0f", val),
                   sprintf(str2, "%05.0f", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_float_rounding) {
  char str1[100], str2[100];
  double val = 9.9999999;

  ck_assert_int_eq(s21_sprintf(str1, "%.1f", val), sprintf(str2, "%.1f", val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zeros) {
  char str1[100], str2[100];

  ck_assert_int_eq(s21_sprintf(str1, "%.5d", 42), sprintf(str2, "%.5d", 42));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_zero_padding_sign) {
  char str1[100], str2[100];

  ck_assert_int_eq(s21_sprintf(str1, "%05d", -42), sprintf(str2, "%05d", -42));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_left_justify) {
  char str1[100], str2[100];

  ck_assert_int_eq(s21_sprintf(str1, "%-10s", "left"),
                   sprintf(str2, "%-10s", "left"));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%-5c", 'x'), sprintf(str2, "%-5c", 'x'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_zero_pad_int) {
  char s21_buffer[256];
  char std_buffer[256];
  int s21_written = s21_sprintf(s21_buffer, "Zero Pad (int): %05d", 4);
  int std_written = sprintf(std_buffer, "Zero Pad (int): %05d", 4);
  ck_assert_str_eq(s21_buffer, std_buffer);
  ck_assert_int_eq(s21_written, std_written);

  int s21_written1 = s21_sprintf(s21_buffer, "%-5d", -4);
  int std_written1 = sprintf(std_buffer, "%-5d", -4);
  ck_assert_str_eq(s21_buffer, std_buffer);
  ck_assert_int_eq(s21_written1, std_written1);
}
END_TEST

START_TEST(test_sprintf_int_positive) {
  char s21_buf[100];
  char std_buf[100];
  int num = 123;
  s21_sprintf(s21_buf, "%d", num);
  sprintf(std_buf, "%d", num);
  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(test_sprintf_int_negative) {
  char s21_buf[100];
  char std_buf[100];
  int num = -456;
  s21_sprintf(s21_buf, "%d", num);
  sprintf(std_buf, "%d", num);
  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(test_sprintf_int_zero) {
  char s21_buf[100];
  char std_buf[100];
  int num = 0;
  s21_sprintf(s21_buf, "% d", num);
  sprintf(std_buf, "% d", num);
  ck_assert_str_eq(s21_buf, std_buf);
  int num1 = -0;
  s21_sprintf(s21_buf, "% d", num1);
  sprintf(std_buf, "% d", num1);
  ck_assert_str_eq(s21_buf, std_buf);
}
END_TEST

START_TEST(test_sscanf_d) {
  int d1, d2, s21_d1, s21_d2;
  const char *format = "%d %d";
  const char *str = "  123   -456";
  int ret_std = sscanf(str, format, &d1, &d2);
  int ret_s21 = s21_sscanf(str, format, &s21_d1, &s21_d2);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_int_eq(d1, s21_d1);
  ck_assert_int_eq(d2, s21_d2);
}
END_TEST

START_TEST(test_sscanf_i) {
  int i1, i2, i3, s21_i1, s21_i2, s21_i3;
  const char *format = "%i %i %i";
  const char *str = "123 0123 0x1A";
  int ret_std = sscanf(str, format, &i1, &i2, &i3);
  int ret_s21 = s21_sscanf(str, format, &s21_i1, &s21_i2, &s21_i3);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_int_eq(i1, s21_i1);
  ck_assert_int_eq(i2, s21_i2);
  ck_assert_int_eq(i3, s21_i3);
}
END_TEST

START_TEST(test_sscanf_c) {
  char c1, s21_c1;
  const char *str = " a";
  int ret_std = sscanf(str, "%c", &c1);
  int ret_s21 = s21_sscanf(str, "%c", &s21_c1);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_int_eq(c1, s21_c1);
  ck_assert_int_eq(c1, ' ');
}
END_TEST

START_TEST(test_sscanf_s) {
  char s1[100], s21_s1[100];
  const char *str = "  \n\t  HelloWorld howareyou";
  int ret_std = sscanf(str, "%s", s1);
  int ret_s21 = s21_sscanf(str, "%s", s21_s1);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_str_eq(s1, s21_s1);
  ck_assert_str_eq(s1, "HelloWorld");
}
END_TEST

START_TEST(test_sscanf_unsigned) {
  unsigned int u1, x1, o1, s21_u1, s21_x1, s21_o1;
  const char *str = "4294967295 1ff 777";
  const char *format = "%u %x %o";
  int ret_std = sscanf(str, format, &u1, &x1, &o1);
  int ret_s21 = s21_sscanf(str, format, &s21_u1, &s21_x1, &s21_o1);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_uint_eq(u1, s21_u1);
  ck_assert_uint_eq(x1, s21_x1);
  ck_assert_uint_eq(o1, s21_o1);
}
END_TEST

START_TEST(test_sscanf_float) {
  float f1, s21_f1;
  double d1, s21_d1;
  long double ld1, s21_ld1;
  const char *str = "1.23 -4.56e-2 7.89e+3";
  const char *format = "%f %lf %Lf";
  int ret_std = sscanf(str, format, &f1, &d1, &ld1);
  int ret_s21 = s21_sscanf(str, format, &s21_f1, &s21_d1, &s21_ld1);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_float_eq_tol(f1, s21_f1, 1e-6);
  ck_assert_double_eq_tol(d1, s21_d1, 1e-6);
  ck_assert_ldouble_eq_tol(ld1, s21_ld1, 1e-6);
}
END_TEST

START_TEST(test_sscanf_width) {
  int d1, d2, s21_d1, s21_d2;
  const char *str = "123456789";
  const char *format = "%3d%2d";
  sscanf(str, format, &d1, &d2);
  s21_sscanf(str, format, &s21_d1, &s21_d2);
  ck_assert_int_eq(d1, 123);
  ck_assert_int_eq(s21_d1, 123);
  ck_assert_int_eq(d2, 45);
  ck_assert_int_eq(s21_d2, 45);
}
END_TEST

START_TEST(test_sscanf_suppress) {
  char s1[100], s21_s1[100];
  int d1, s21_d1;
  const char *str = "123 abc 456";
  const char *format = "%*d %s %d";
  int ret_std = sscanf(str, format, s1, &d1);
  int ret_s21 = s21_sscanf(str, format, s21_s1, &s21_d1);
  ck_assert_int_eq(ret_std, 2);
  ck_assert_int_eq(ret_s21, 2);
  ck_assert_str_eq(s1, "abc");
  ck_assert_str_eq(s21_s1, "abc");
  ck_assert_int_eq(d1, 456);
  ck_assert_int_eq(s21_d1, 456);
}
END_TEST

START_TEST(test_sscanf_n) {
  int d1, n1, s21_d1, s21_n1;
  const char *str = "   123   abc";
  const char *format = "%d%n";
  int ret_std = sscanf(str, format, &d1, &n1);
  int ret_s21 = s21_sscanf(str, format, &s21_d1, &s21_n1);

  ck_assert_int_eq(ret_std, 1);
  ck_assert_int_eq(ret_s21, 1);

  ck_assert_int_eq(d1, 123);
  ck_assert_int_eq(s21_d1, 123);
  ck_assert_int_eq(n1, s21_n1);
  ck_assert_int_eq(n1, 6);
}
END_TEST

START_TEST(test_sscanf_pointer) {
  int x;
  char str[30];
  void *p_std = s21_NULL;
  void *p_s21 = s21_NULL;

  sprintf(str, "%p", &x);

  int ret_std = sscanf(str, "%p", &p_std);
  int ret_s21 = s21_sscanf(str, "%p", &p_s21);

  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_ptr_eq(p_std, p_s21);
  ck_assert_ptr_eq(p_std, &x);
}
END_TEST

int main(void) {
  int nf;

  Suite *s = suite_create("s21_string");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);
  tcase_add_test(tc_core, test_s21_memcpy);
  tcase_add_test(tc_core, test_s21_memset);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strncmp);
  tcase_add_test(tc_core, test_s21_strchr);
  tcase_add_test(tc_core, test_s21_strncpy);
  tcase_add_test(tc_core, test_s21_strncat);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strerror);
  tcase_add_test(tc_core, test_s21_to_upper);
  tcase_add_test(tc_core, test_s21_to_lower);
  tcase_add_test(tc_core, test_s21_trim);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_insert);

  tcase_add_test(tc_core, s21_memchr_test);
  tcase_add_test(tc_core, s21_memcmp_test);
  tcase_add_test(tc_core, s21_memcpy_test);
  tcase_add_test(tc_core, s21_memset_test);
  tcase_add_test(tc_core, s21_strlen_test);
  tcase_add_test(tc_core, s21_strncmp_test);
  tcase_add_test(tc_core, s21_strchr_test);
  tcase_add_test(tc_core, s21_strncpy_test);
  tcase_add_test(tc_core, s21_strncat_test);
  tcase_add_test(tc_core, s21_strcspn_test);
  tcase_add_test(tc_core, s21_strerror_test);
  tcase_add_test(tc_core, s21_to_upper_test);
  tcase_add_test(tc_core, s21_to_lower_test);
  tcase_add_test(tc_core, s21_trim_test);
  tcase_add_test(tc_core, s21_strpbrk_test);
  tcase_add_test(tc_core, s21_strrchr_test);
  tcase_add_test(tc_core, s21_strstr_test);
  tcase_add_test(tc_core, s21_strtok_test);
  tcase_add_test(tc_core, s21_insert_test);

  tcase_add_test(tc_core, test_s21_sprintf_integer);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned);
  tcase_add_test(tc_core, test_s21_sprintf_float);
  tcase_add_test(tc_core, test_s21_sprintf_char);
  tcase_add_test(tc_core, test_s21_sprintf_string);
  tcase_add_test(tc_core, test_s21_sprintf_flags);
  tcase_add_test(tc_core, test_s21_sprintf_percent);
  tcase_add_test(tc_core, test_s21_sprintf_float_negative);
  tcase_add_test(tc_core, test_s21_sprintf_zero_value);
  tcase_add_test(tc_core, test_s21_sprintf_float_signs);
  tcase_add_test(tc_core, test_s21_sprintf_float_zero);
  tcase_add_test(tc_core, test_s21_sprintf_float_rounding);
  tcase_add_test(tc_core, test_s21_sprintf_precision_zeros);
  tcase_add_test(tc_core, test_s21_sprintf_zero_padding_sign);
  tcase_add_test(tc_core, test_s21_sprintf_left_justify);
  tcase_add_test(tc_core, test_s21_sprintf_float_left_justify);
  tcase_add_test(tc_core, test_s21_sprintf_d_test);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_0);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_2);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_3);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_4);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_5);
  tcase_add_test(tc_core, test_s21_sprintf_d_test_6);
  tcase_add_test(tc_core, test_s21_sprintf_u_test);
  tcase_add_test(tc_core, test_s21_sprintf_s_test);
  tcase_add_test(tc_core, test_s21_sprintf_c_test);
  tcase_add_test(tc_core, test_s21_sprintf_test);
  tcase_add_test(tc_core, test_s21_sprintf_prc_test);
  tcase_add_test(tc_core, test_sprintf_zero_pad_int);
  tcase_add_test(tc_core, test_sprintf_int_zero);
  tcase_add_test(tc_core, test_sprintf_int_negative);
  tcase_add_test(tc_core, test_sprintf_int_positive);

  tcase_add_test(tc_core, test_sscanf_d);
  tcase_add_test(tc_core, test_sscanf_i);
  tcase_add_test(tc_core, test_sscanf_c);
  tcase_add_test(tc_core, test_sscanf_s);
  tcase_add_test(tc_core, test_sscanf_unsigned);
  tcase_add_test(tc_core, test_sscanf_float);
  tcase_add_test(tc_core, test_sscanf_width);
  tcase_add_test(tc_core, test_sscanf_suppress);
  tcase_add_test(tc_core, test_sscanf_n);
  tcase_add_test(tc_core, test_sscanf_pointer);

  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
