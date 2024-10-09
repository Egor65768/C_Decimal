#include <check.h>

#include "test.h"

START_TEST(checking_max_pow_1) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 31);
  _a.bits[0] = 1234567;
  //   1234.567
  //   1234.56
  //   1234.6
  //   1234
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 1234);
}
END_TEST

START_TEST(checking_max_pow_2) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 29);
  _a.bits[0] = 1234567;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 123456);
}
END_TEST

START_TEST(checking_max_pow_3) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 29);
  _a.bits[0] = 1234557;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 123456);
}
END_TEST

START_TEST(checking_max_pow_4) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 29);
  _a.bits[0] = 1234554;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 123455);
}
END_TEST

START_TEST(checking_max_pow_5) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 29);
  _a.bits[0] = 1234555;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 123456);
}
END_TEST

START_TEST(checking_max_pow_6) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 56);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 8);
}
END_TEST

START_TEST(checking_max_pow_7) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 55);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 79);
}
END_TEST

START_TEST(checking_max_pow_8) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 29);
  _a.bits[0] = 19999;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 2000);
}
END_TEST

START_TEST(checking_max_pow_9) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 32);
  _a.bits[0] = 79228;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 8);
}
END_TEST

START_TEST(checking_max_pow_10) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 32);
  _a.bits[0] = 78228;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 8);
}
END_TEST

START_TEST(checking_max_pow_11) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 32);
  _a.bits[0] = 68228;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 6);
}
END_TEST

START_TEST(checking_max_pow_12) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 32);
  _a.bits[0] = 38228;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 4);
}
END_TEST

START_TEST(checking_max_pow_13) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  set_Scale(&_a, 32);
  _a.bits[0] = 38228;
  checking_max_pow(&_a);
  ck_assert_int_eq(getScale(_a), 28);
  ck_assert_int_eq(_a.bits[0], 4);
}
END_TEST

START_TEST(reduction_common_denominator_1) {
  s21_decimal _a, _b, ares, bres;
  s21_tozero(&ares);
  s21_tozero(&bres);
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  ares = _a;
  bres.bits[2] = 0b1000011000110;
  bres.bits[1] = 0b11110111101000001011010111101101;
  bres.bits[0] = 0b10001101001101101011010011000111;
  _b.bits[0] = _b.bits[1] = _b.bits[2] = U_MAX_INT;
  set_Scale(&_a, 6);
  set_Scale(&_b, 12);
  reduction_common_denominator(&_a, &_b, 1);
  ck_assert_int_eq(getScale(_a), 6);
  ck_assert_int_eq(getScale(_b), 6);
  ck_assert_int_eq(_b.bits[0], bres.bits[0]);
  ck_assert_int_eq(_b.bits[1], bres.bits[1]);
  ck_assert_int_eq(_b.bits[2], bres.bits[2]);
  ck_assert_int_eq(_a.bits[0], ares.bits[0]);
  ck_assert_int_eq(_a.bits[1], ares.bits[1]);
  ck_assert_int_eq(_a.bits[2], ares.bits[2]);
}
END_TEST

START_TEST(reduction_common_denominator_2) {
  s21_decimal _a, _b, ares, bres;
  s21_tozero(&ares);
  s21_tozero(&bres);
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = _b.bits[1] = _b.bits[2] = U_MAX_INT;
  bres = _b;
  ares.bits[0] = 79;
  set_Scale(&_a, 28);
  set_Scale(&_b, 1);
  reduction_common_denominator(&_a, &_b, 1);
  ck_assert_int_eq(getScale(_a), 1);
  ck_assert_int_eq(getScale(_b), 1);
  ck_assert_int_eq(_b.bits[0], bres.bits[0]);
  ck_assert_int_eq(_b.bits[1], bres.bits[1]);
  ck_assert_int_eq(_b.bits[2], bres.bits[2]);
  ck_assert_int_eq(_a.bits[0], ares.bits[0]);
  ck_assert_int_eq(_a.bits[1], ares.bits[1]);
  ck_assert_int_eq(_a.bits[2], ares.bits[2]);
}
END_TEST

START_TEST(reduction_common_denominator_3) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _d.bits[2] = 0b10100100000000001111101110;
  _d.bits[1] = 0b10100010000010011010101010100011;
  _d.bits[0] = 0b10101101000110001101001001011110;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _b.bits[0] = _b.bits[0] - 10;
  set_Scale(&_a, 6);
  set_Scale(&_b, 3);
  reduction_common_denominator(&_a, &_b, 1);
  ck_assert_int_eq(getScale(_a), 3);
  ck_assert_int_eq(getScale(_b), 3);
}
END_TEST

START_TEST(reduction_common_denominator_4) {
  s21_decimal _a, _b;
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011011;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010001010;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  reduction_common_denominator(&_a, &_b, 1);
  ck_assert_int_eq(getScale(_a), 3);
  ck_assert_int_eq(getScale(_b), 3);
}
END_TEST

Suite *test_help_func(void) {
  Suite *s = suite_create("\033[45m-=s21_help_func=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, checking_max_pow_1);
  tcase_add_test(tc_core, checking_max_pow_2);
  tcase_add_test(tc_core, checking_max_pow_3);
  tcase_add_test(tc_core, checking_max_pow_4);
  tcase_add_test(tc_core, checking_max_pow_5);
  tcase_add_test(tc_core, checking_max_pow_6);
  tcase_add_test(tc_core, checking_max_pow_7);
  tcase_add_test(tc_core, checking_max_pow_8);
  tcase_add_test(tc_core, checking_max_pow_9);
  tcase_add_test(tc_core, checking_max_pow_10);
  tcase_add_test(tc_core, checking_max_pow_11);
  tcase_add_test(tc_core, checking_max_pow_12);
  tcase_add_test(tc_core, checking_max_pow_13);
  tcase_add_test(tc_core, reduction_common_denominator_1);
  tcase_add_test(tc_core, reduction_common_denominator_2);
  tcase_add_test(tc_core, reduction_common_denominator_3);
  tcase_add_test(tc_core, reduction_common_denominator_4);
  suite_add_tcase(s, tc_core);

  return s;
}
