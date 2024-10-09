#ifndef TEST_H
#define TEST_H

#include <check.h>

#include "../s21_decimal.h"

#define U_MAX_INT 4294967295

Suite *test_add(void);
Suite *test_sub(void);
Suite *test_mod(void);
Suite *test_mul(void);
Suite *test_help_func(void);
Suite *test_div(void);
Suite *test_is_equal(void);
Suite *test_is_greater_or_equal(void);
Suite *test_is_greater(void);
Suite *test_is_less_or_equal(void);
Suite *test_is_less(void);
Suite *test_is_not_equal(void);
Suite *test_funck(void);
Suite *test_convert(void);

#endif
