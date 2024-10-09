#include "test.h"

START_TEST(mod_1) {
  s21_decimal _a, _b, _c, _d;
  int number1 = -22111;
  int number2 = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  _d = s21_mod(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 / number2);
  s21_from_decimal_to_int(_d, &result);
  ck_assert_int_eq(result, number1 % number2);
}
END_TEST

START_TEST(mod_2) {
  s21_decimal _a, _b, _c, _d;
  int number1 = 22111;
  int number2 = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  _d = s21_mod(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 / number2);
  s21_from_decimal_to_int(_d, &result);
  ck_assert_int_eq(result, number1 % number2);
}
END_TEST

START_TEST(mod_3) {
  s21_decimal _a, _b, _c, _d;
  int number1 = 22111;
  int number2 = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  _d = s21_mod(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 / number2);
  s21_from_decimal_to_int(_d, &result);
  ck_assert_int_eq(result, number1 % number2);
}
END_TEST

START_TEST(mod_4) {
  s21_decimal _a, _b, _c, _d;
  int number1 = -22111;
  int number2 = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  _d = s21_mod(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 / number2);
  s21_from_decimal_to_int(_d, &result);
  ck_assert_int_eq(result, number1 % number2);
}
END_TEST

START_TEST(mod_5) {
  s21_decimal _a, _b, _c, _d, mod;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 0b1010;
  mod = s21_mod(_a, _b, &_c);
  _d.bits[2] = 0b00011001100110011001100110011001;
  _d.bits[1] = 0b10011001100110011001100110011001;
  _d.bits[0] = 0b10011001100110011001100110011001;
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  s21_tozero(&_d);
  _d.bits[0] = 5;
  ck_assert_int_eq(mod.bits[0], _d.bits[0]);
  ck_assert_int_eq(mod.bits[1], _d.bits[1]);
  ck_assert_int_eq(mod.bits[2], _d.bits[2]);
  ck_assert_int_eq(mod.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(mod_6) {
  s21_decimal _a, _b, _c, _d, mod;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 2321;
  mod = s21_mod(_a, _b, &_c);
  _d.bits[2] = 0b111000011110001110001;
  _d.bits[1] = 0b01100010101101110101000001101000;
  _d.bits[0] = 0b00011110111000100001110000000011;

  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  s21_tozero(&_d);
  _d.bits[0] = 2252;
  ck_assert_int_eq(mod.bits[0], _d.bits[0]);
  ck_assert_int_eq(mod.bits[1], _d.bits[1]);
  ck_assert_int_eq(mod.bits[2], _d.bits[2]);
  ck_assert_int_eq(mod.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(mod_7) {
  s21_decimal _a, _b, _c, _d;
  s21_decimal mod;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  mod = s21_mod(_a, _b, &_c);
  _d.bits[0] = 1;
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  s21_tozero(&_d);
  ck_assert_int_eq(mod.bits[0], _d.bits[0]);
  ck_assert_int_eq(mod.bits[1], _d.bits[1]);
  ck_assert_int_eq(mod.bits[2], _d.bits[3]);
}
END_TEST

Suite *test_mod(void) {
  Suite *s = suite_create("\033[45m-=s21_mod=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, mod_1);
  tcase_add_test(tc_core, mod_2);
  tcase_add_test(tc_core, mod_3);
  tcase_add_test(tc_core, mod_4);
  tcase_add_test(tc_core, mod_5);
  tcase_add_test(tc_core, mod_6);
  tcase_add_test(tc_core, mod_7);

  suite_add_tcase(s, tc_core);

  return s;
}
