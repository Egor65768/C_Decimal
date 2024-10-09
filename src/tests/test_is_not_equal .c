#include "test.h"

START_TEST(test_is_not_equal_1) {
  s21_decimal _a, _b;
  int number1 = -22111;
  int number2 = -612234;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_2) {
  s21_decimal _a, _b;
  int number1 = 22111;
  int number2 = 612234;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_3) {
  s21_decimal _a, _b;
  int number1 = 22111;
  int number2 = 22111;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 0);
}
END_TEST

START_TEST(test_is_not_equal_4) {
  s21_decimal _a, _b;
  int number1 = -22111;
  int number2 = 22111;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_5) {
  s21_decimal _a, _b;
  int number1 = 22111;
  int number2 = -22111;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_6) {
  s21_decimal _a, _b;
  int number1 = 1;
  int number2 = 1000000;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_7) {
  s21_decimal _a, _b;
  int number1 = 1000000;
  int number2 = 1;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_8) {
  s21_decimal _a, _b;
  int number1 = 1000000000;
  int number2 = 999999999;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_9) {
  s21_decimal _a, _b;
  int number1 = 999999999;
  int number2 = 1000000000;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_10) {
  s21_decimal _a, _b;
  int number1 = 2147483647;
  int number2 = -2147483647;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_11) {
  s21_decimal _a, _b;
  int number1 = -2147483647;
  int number2 = 2147483647;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 1);
}
END_TEST

START_TEST(test_is_not_equal_12) {
  s21_decimal _a, _b;
  int number1 = 2147483647;
  int number2 = 2147483647;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 0);
}
END_TEST

Suite *test_is_not_equal(void) {
  Suite *s = suite_create("\033[45m-=s21_is_not_equal=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_is_not_equal_1);
  tcase_add_test(tc_core, test_is_not_equal_2);
  tcase_add_test(tc_core, test_is_not_equal_3);
  tcase_add_test(tc_core, test_is_not_equal_4);
  tcase_add_test(tc_core, test_is_not_equal_5);
  tcase_add_test(tc_core, test_is_not_equal_6);
  tcase_add_test(tc_core, test_is_not_equal_7);
  tcase_add_test(tc_core, test_is_not_equal_8);
  tcase_add_test(tc_core, test_is_not_equal_9);
  tcase_add_test(tc_core, test_is_not_equal_10);
  tcase_add_test(tc_core, test_is_not_equal_11);
  tcase_add_test(tc_core, test_is_not_equal_12);
  suite_add_tcase(s, tc_core);

  return s;
}
