#include "test.h"

START_TEST(sub_1) {
  s21_decimal _a, _b, _c;
  int number1 = -22111;
  int number2 = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_2) {
  s21_decimal _a, _b, _c;
  int number1 = 22111;
  int number2 = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_3) {
  s21_decimal _a, _b, _c;
  int number1 = -22111;
  int number2 = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_4) {
  s21_decimal _a, _b, _c;
  int number1 = 22111;
  int number2 = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_5) {
  s21_decimal _a, _b, _c;
  int number1 = 0;
  int number2 = 0;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_6) {
  s21_decimal _a, _b, _c;
  int number1 = 123444;
  int number2 = 0;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_7) {
  s21_decimal _a, _b, _c;
  int number1 = -10;
  int number2 = 12344;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal _a, _b, _c;
  int number1 = -112340;
  int number2 = 12344;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal _a, _b, _c;
  int number1 = -1111110;
  int number2 = -12344;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal _a, _b, _c;
  int number1 = -110;
  int number2 = -12344;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  s21_sub(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 - number2);
}
END_TEST

START_TEST(sub_11) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 10;
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111111111111111110101;
  s21_sub(_a, _b, &_c);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_12) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1;
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111111111111111111110;
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_13) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 10;
  setSign(&_a, 1);
  setSign(&_b, 1);
  setSign(&_d, 1);
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111111111111111110101;
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_14) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 10;
  setSign(&_a, 1);
  setSign(&_b, 0);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 2);
}
END_TEST

START_TEST(sub_15) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 10;
  setSign(&_a, 1);
  setSign(&_b, 0);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 2);
}
END_TEST

START_TEST(sub_16) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 123450;
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111100001110111000101;
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_17) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 123450;
  setSign(&_a, 1);
  setSign(&_b, 1);
  setSign(&_d, 1);
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111100001110111000101;
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_18) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 123450;
  setSign(&_a, 0);
  setSign(&_b, 1);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 1);
}
END_TEST

START_TEST(sub_19) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001010111;
  _b.bits[2] = 0b111110001000010010100111001010;
  _b.bits[1] = 0b10001011001000011111000110111001;
  _b.bits[0] = 0b10100000000000000000001001111110;
  _d.bits[2] = 0b10011000110110100001000010110111;
  _d.bits[1] = 0b01101010110110100110000010110000;
  _d.bits[0] = 0b10100110011001100110100001111110;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a = 49228162514264337593543950.935
// b = 1922816251426433759354395.0974
// res = 47305346262837903834189555.8376
// otv = 47305346262837903834189555.838
//  max =.79228162514264337593543950335
//       47305346262837903834189555.836

START_TEST(sub_20) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);

  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001010110;
  _b.bits[2] = 0b111110001000010010100111001010;
  _b.bits[1] = 0b10001011001000011111000110111001;
  _b.bits[0] = 0b10100000000000000000001001111110;
  _d.bits[2] = 0b10011000110110100001000010110111;
  _d.bits[1] = 0b01101010110110100110000010110000;
  _d.bits[0] = 0b10100110011001100110100001111100;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a = 49228162514264337593543950.934
// b = 1922816251426433759354395.0974
// res = 47305346262837903834189555.8366
// otv = 47305346262837903834189555.836
//  max =.79228162514264337593543950335

START_TEST(sub_21) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001010110;
  _b.bits[2] = 0b111110001000010010100111001010;
  _b.bits[1] = 0b10001011001000011111000110111001;
  _b.bits[0] = 0b10100000000000000000001001110100;
  _d.bits[2] = 0b10011000110110100001000010110111;
  _d.bits[1] = 0b01101010110110100110000010110000;
  _d.bits[0] = 0b10100110011001100110100001111110;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a = 49228162514264337593543950.934
// b = 1922816251426433759354395.0964
// res = 47305346262837903834189555.8376
// otv = 47305346262837903834189555.838
//  max =.79228162514264337593543950335

START_TEST(sub_22) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001010111;
  _b.bits[2] = 0b111110001000010010100111001010;
  _b.bits[1] = 0b10001011001000011111000110111001;
  _b.bits[0] = 0b10100000000000000000001001110100;
  _d.bits[2] = 0b10011000110110100001000010110111;
  _d.bits[1] = 0b01101010110110100110000010110000;
  _d.bits[0] = 0b10100110011001100110100001111110;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a = 49228162514264337593543950.935
// b = 1922816251426433759354395.0964
// otv = 47305346262837903834189555.838
//  max =.79228162514264337593543950335

START_TEST(sub_23) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[2] = _a.bits[1] = _a.bits[0] = U_MAX_INT;
  _b = _a;
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111011011111110001;
  _d.bits[0] = 0b01000001100001000110001010100110;
  set_Scale(&_a, 6);
  set_Scale(&_b, 21);
  set_Scale(&_d, 6);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a = 79228162514264337593543.950335
// b = 79228162.514264337593543950335
// res = 79228162514264258365381.436070662406456049665
// otv = 79228162514264258365381.436070
//  max =.79228162514264337593543950335

START_TEST(sub_24) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[2] = _a.bits[1] = _a.bits[0] = U_MAX_INT;
  _b = _a;
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(sub_25) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = 1;
  set_Scale(&_a, 1);
  _b.bits[0] = 1;
  _d.bits[0] = 11;
  set_Scale(&_d, 1);
  setSign(&_b, 1);
  ck_assert_int_eq(s21_sub(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=s21_sub=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sub_1);
  tcase_add_test(tc_core, sub_2);
  tcase_add_test(tc_core, sub_3);
  tcase_add_test(tc_core, sub_4);
  tcase_add_test(tc_core, sub_5);
  tcase_add_test(tc_core, sub_6);
  tcase_add_test(tc_core, sub_7);
  tcase_add_test(tc_core, sub_8);
  tcase_add_test(tc_core, sub_9);
  tcase_add_test(tc_core, sub_10);
  tcase_add_test(tc_core, sub_11);
  tcase_add_test(tc_core, sub_12);
  tcase_add_test(tc_core, sub_13);
  tcase_add_test(tc_core, sub_14);
  tcase_add_test(tc_core, sub_15);
  tcase_add_test(tc_core, sub_16);
  tcase_add_test(tc_core, sub_17);
  tcase_add_test(tc_core, sub_18);
  tcase_add_test(tc_core, sub_19);
  tcase_add_test(tc_core, sub_20);
  tcase_add_test(tc_core, sub_21);
  tcase_add_test(tc_core, sub_22);
  tcase_add_test(tc_core, sub_23);
  tcase_add_test(tc_core, sub_24);
  tcase_add_test(tc_core, sub_25);
  suite_add_tcase(s, tc_core);

  return s;
}
