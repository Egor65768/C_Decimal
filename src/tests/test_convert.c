#include "test.h"

START_TEST(decimal_to_float_0) {
  s21_decimal _a;
  _a.bits[3] = 0b10000000011111111110000000000000;
  _a.bits[2] = 0b00000000000000000000000000000000;
  _a.bits[1] = 0b00000000000000000000000000000000;
  _a.bits[0] = 0b00000000000000000000000000000001;
  float toFloat = 0.0;
  int s21_ret = s21_from_decimal_to_float(_a, &toFloat);
  ck_assert_int_eq(s21_ret, 0);
}
END_TEST

START_TEST(float_to_decimal_0) {
  s21_decimal _a;

  float src = -1.1;
  int s21_ret = s21_from_float_to_decimal(src, &_a);
  ck_assert_int_eq(s21_ret, 0);
  //   s21_decimal _b;
  //   _a.bits[3] = 00000000000000010000000000000000;
  //   _a.bits[2] = 0b000000000000000000000000000000;
  //   _a.bits[1] = 0b000000000000000000000000000000;
  //   _a.bits[0] = 0b000000000000000000000000001101;
}
END_TEST

START_TEST(float_to_decimal_1) {
  s21_decimal _a;

  float src = INFINITY;
  int s21_ret = s21_from_float_to_decimal(src, &_a);
  ck_assert_int_eq(s21_ret, 1);

  //   s21_decimal _b;
  //   _a.bits[3] = 00000000000000010000000000000000;
  //   _a.bits[2] = 0b000000000000000000000000000000;
  //   _a.bits[1] = 0b000000000000000000000000000000;
  //   _a.bits[0] = 0b000000000000000000000000001101;
}
END_TEST

START_TEST(test_from_float_to_decimal_1) {
  float original = 4.66, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_2) {
  float original = -4.66, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_3) {
  float original = 13.4564564564564564564564564564566456, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq_tol(original, transformed, 0.00001);
}
END_TEST

START_TEST(test_from_float_to_decimal_4) {
  float original = -13.4564564564564564564564564564566456, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq_tol(original, transformed, 0.00001);
}
END_TEST

START_TEST(test_from_float_to_decimal_5) {
  float original = 79.32, transformed = 0;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_6) {
  float original = 0, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_7) {
  float original = 25.1, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_1) {
  int original = 134523, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_2) {
  int original = -1383286;
  int transformed;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_3) {
  int original = 0;
  int transformed;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_4) {
  int original = 2147483647;
  int transformed;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_int_to_decimal_5) {
  int original = -2147483648;
  int transformed;
  s21_decimal decimal_1 = {0};
  s21_from_int_to_decimal(original, &decimal_1);
  s21_from_decimal_to_int(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

START_TEST(test_from_float_to_decimal_8) {
  float original = 19.2314, transformed = -1;
  s21_decimal decimal_1 = {0};
  s21_from_float_to_decimal(original, &decimal_1);
  s21_from_decimal_to_float(decimal_1, &transformed);
  ck_assert_float_eq(original, transformed);
}
END_TEST

Suite *test_convert(void) {
  Suite *s = suite_create("\033[45m-=s21_convert=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, decimal_to_float_0);
  tcase_add_test(tc_core, float_to_decimal_0);
  tcase_add_test(tc_core, float_to_decimal_1);
  tcase_add_test(tc_core, test_from_float_to_decimal_1);
  tcase_add_test(tc_core, test_from_float_to_decimal_2);
  tcase_add_test(tc_core, test_from_float_to_decimal_3);
  tcase_add_test(tc_core, test_from_float_to_decimal_4);
  tcase_add_test(tc_core, test_from_float_to_decimal_5);
  tcase_add_test(tc_core, test_from_float_to_decimal_6);
  tcase_add_test(tc_core, test_from_float_to_decimal_7);
  tcase_add_test(tc_core, test_from_float_to_decimal_8);
  tcase_add_test(tc_core, test_from_int_to_decimal_1);
  tcase_add_test(tc_core, test_from_int_to_decimal_2);
  tcase_add_test(tc_core, test_from_int_to_decimal_3);
  tcase_add_test(tc_core, test_from_int_to_decimal_4);
  tcase_add_test(tc_core, test_from_int_to_decimal_5);

  suite_add_tcase(s, tc_core);

  return s;
}
