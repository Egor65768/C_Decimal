#include "test.h"

START_TEST(add_1) {
  s21_decimal _a, _b, _c;
  int number1 = -22111;
  int hu = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_2) {
  s21_decimal _a, _b, _c;
  int number1 = 22111;
  int hu = -612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_3) {
  s21_decimal _a, _b, _c;
  int number1 = -22111;
  int hu = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_4) {
  s21_decimal _a, _b, _c;
  int number1 = 22111;
  int hu = 612234;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_5) {
  s21_decimal _a, _b, _c;
  int number1 = 0;
  int hu = 0;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_6) {
  s21_decimal _a, _b, _c;
  int number1 = 123444;
  int hu = 0;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_7) {
  s21_decimal _a, _b, _c;
  int number1 = -10;
  int hu = 12344;
  int result;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  s21_add(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 + hu);
}
END_TEST

START_TEST(add_8) {
  s21_decimal _a, _b, _c;
  int number1 = 126;
  int hu = 12;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  set_Scale(&_a, 29);
  set_Scale(&_b, 28);
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], 24);
  ck_assert_int_eq(getScale(_c), 28);
}
END_TEST

START_TEST(add_9) {
  s21_decimal _a, _b, _c;
  int number1 = 136;
  int hu = 12;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(hu, &_b);
  set_Scale(&_a, 29);
  set_Scale(&_b, 28);
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], 26);
  ck_assert_int_eq(getScale(_c), 28);
}
END_TEST

START_TEST(add_10) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[0] = 1346;
  _b.bits[0] = 13;
  set_Scale(&_a, 30);
  set_Scale(&_b, 26);
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], 1313);
  ck_assert_int_eq(getScale(_c), 28);
}
END_TEST

START_TEST(add_11) {
  s21_decimal _a, _b, _c;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[3] = 0;
  s21_tozero(&_b);
  _b.bits[0] = 12;

  s21_add(_a, _b, &_c);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 1);
}
END_TEST

START_TEST(add_12) {
  s21_decimal _a, _b, _c;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[3] = 0;
  s21_tozero(&_b);
  _b.bits[0] = 1;

  s21_add(_a, _b, &_c);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 1);
}
END_TEST

START_TEST(add_13) {
  s21_decimal _a, _b, _c;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[3] = 0;
  s21_tozero(&_b);
  _b.bits[0] = 0;
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], U_MAX_INT);
  ck_assert_int_eq(_c.bits[1], U_MAX_INT);
  ck_assert_int_eq(_c.bits[2], U_MAX_INT);
}
END_TEST

START_TEST(add_14) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_b);
  s21_tozero(&_a);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 245;
  set_Scale(&_a, 55);
  set_Scale(&_b, 29);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], 103);
  ck_assert_int_eq(getScale(_c), 28);
}
END_TEST

START_TEST(add_15) {
  s21_decimal _a, _b, _c;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[3] = 0;
  s21_tozero(&_b);
  _b.bits[0] = 0;

  s21_add(_a, _b, &_c);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], U_MAX_INT);
  ck_assert_int_eq(_c.bits[1], U_MAX_INT);
  ck_assert_int_eq(_c.bits[2], U_MAX_INT);
}
END_TEST

START_TEST(add_16) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 5;
  _d.bits[2] = 0b11111111111111111111111111111111;
  _d.bits[1] = 0b11111111111111111111111111111111;
  _d.bits[0] = 0b11111111111111111111111111111010;
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_17) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 10;
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = U_MAX_INT;
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_18) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 123124;
  ck_assert_int_eq(s21_add(_a, _b, &_c), 1);
}
END_TEST

START_TEST(add_19) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 11;
  ck_assert_int_eq(s21_add(_a, _b, &_c), 1);
}
END_TEST

START_TEST(add_20) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 11;
  setSign(&_a, 1);
  setSign(&_b, 1);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 2);
}
END_TEST

START_TEST(add_21) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 10;
  setSign(&_a, 1);
  setSign(&_b, 1);
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = U_MAX_INT;
  setSign(&_d, 1);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_22) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 9;
  setSign(&_a, 1);
  setSign(&_b, 1);
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = 0b11111111111111111111111111111110;
  setSign(&_d, 1);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_23) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _a.bits[0] = 0b11111111111111111111111111110101;
  _b.bits[0] = 9;
  setSign(&_a, 1);
  setSign(&_b, 1);
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = 0b11111111111111111111111111111110;
  setSign(&_d, 1);
  ck_assert_int_eq(s21_add(_b, _a, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_24) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[1] = _a.bits[0] = U_MAX_INT;
  _a.bits[2] = 0b01111111111111111111111111111111;
  _b.bits[0] = 9;
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = 0b11111111111111111111111111111110;
  ck_assert_int_eq(s21_add(_a, _a, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_25) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  setSign(&_a, 1);
  setSign(&_b, 1);
  _a.bits[1] = _a.bits[0] = U_MAX_INT;
  _a.bits[2] = 0b01111111111111111111111111111111;
  _b.bits[0] = 9;
  _d.bits[2] = U_MAX_INT;
  _d.bits[1] = U_MAX_INT;
  _d.bits[0] = 0b11111111111111111111111111111110;
  setSign(&_d, 1);
  ck_assert_int_eq(s21_add(_a, _a, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_26) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  setSign(&_a, 1);
  setSign(&_b, 1);
  _a.bits[1] = _a.bits[0] = U_MAX_INT;
  _a.bits[2] = 0b01111111111111111111111111111111;
  _b.bits[0] = U_MAX_INT;
  ck_assert_int_eq(s21_add(_a, _a, &_c), 0);
}
END_TEST

START_TEST(add_27) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 0;
  set_Scale(&_a, 57);
  s21_add(_a, _b, &_c);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], 0);
  ck_assert_int_eq(_c.bits[1], 0);
  ck_assert_int_eq(_c.bits[2], 0);
}
END_TEST

START_TEST(add_28) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _b.bits[0] = _b.bits[0] - 1000;
  set_Scale(&_a, 29);
  s21_add(_a, _b, &_c);
}
END_TEST

START_TEST(add_29) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _d.bits[2] = _d.bits[1] = U_MAX_INT;
  _d.bits[0] = U_MAX_INT - 3;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _b.bits[0] = _b.bits[0] - 10;
  set_Scale(&_a, 28);
  set_Scale(&_d, 0);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// a = 7.9,228,162,514,264,337,593,543,950,335
// b = 79,228,162,514,264,337,593,543,950,325
// d = 79,228,162,514,264,337,593,543,950,332
// res = 79228162514264337593543950332.9228162514264337593543950325

START_TEST(add_30) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);

  _d.bits[2] = 0b11001101000000010011101010010;
  _d.bits[1] = 0b01010100011000001010101001100100;
  _d.bits[0] = 0b11000010111110000011011110110100;
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _b.bits[0] = _b.bits[0] - 10;
  set_Scale(&_a, 6);
  set_Scale(&_b, 3);
  set_Scale(&_d, 2);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// max =79228162514264337593543950335
//     79307390676778601931137494.28
// a = 79,228,162,514,264,337,593,543.950,335
// b = 79,228,162,514,264,337,593,543,950.325
// d = 79307390676778601931137494.2(8
//     79228162514264337593543950335
// 7.9307390676778601931137494275335

START_TEST(add_31) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011011;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010001010;
  _d.bits[2] = 0b10110010001100111101001000000101;
  _d.bits[1] = 0b10011111100010011001000111111100;
  _d.bits[0] = 0b10011001100110011001110000110110;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// max =79228162514264337593543950335

// res =55150978765690771352898346.0376
// otet=55150978765690771352898346.038

// a = 49228162514264337593543950.939 -3
// b = 5922816251426433759354395.0986 -4

// a = 49228162514264337593543950.939 -3
// b =  5922816251426433759354395.099 -3

START_TEST(add_32) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011011;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010001010;
  _d.bits[2] = 0b10110010001100111101001000000101;
  _d.bits[1] = 0b10011111100010011001000111111100;
  _d.bits[0] = 0b10011001100110011001110000110110;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_add(_b, _a, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_33) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _d.bits[2] = 0b11001100110011001100110011001;
  _d.bits[1] = 0b10011001100110011001100110011001;
  _d.bits[0] = 0b10011110010100101000011010011100;
  set_Scale(&_a, 26);
  set_Scale(&_b, 6);
  set_Scale(&_d, 5);
  ck_assert_int_eq(s21_add(_b, _a, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// max =79228162514264337593543950335
// a =792.28162514264337593543950335
// b =79228162514264337593543.950335
// res =7922816251426433759433623196 0 -6
// max =79228162514264337593543950335
// res=

START_TEST(add_34) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011011;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010000000;
  _d.bits[2] = 0b10110010001100111101001000000101;
  _d.bits[1] = 0b10011111100010011001000111111100;
  _d.bits[0] = 0b10011001100110011001110000110100;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// max =79228162514264337593543950335
//      551509787656907713528983460366

// res =55150978765690771352898346.0366
// otet=55150978765690771352898346.036

// a = 49228162514264337593543950.939-3
// b = 5922816251426433759354395.0976 -4

// a = 49228162514264337593543950.939 3
// b = 5922816251426433759354395.0976 4

// a = 49228162514264337593543950.939 -3
// b =  5922816251426433759354395.097 -3

START_TEST(add_35) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  // 10011111000100001001010011100101
  // 01000101100100001111100011011100
  // 11010000000000000000001001011010
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011010;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010000000;
  _d.bits[2] = 0b10110010001100111101001000000101;
  _d.bits[1] = 0b10011111100010011001000111111100;
  _d.bits[0] = 0b10011001100110011001110000110100;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// max =79228162514264337593543950335

// otet=55150978765690771352898346.026
//   55150978765690771352898346.035
// a = 49228162514264337593543950.938 -3
// b =  5922816251426433759354395.0976 -4

// a = 49228162514264337593543950.939 -3
// b =  5922816251426433759354395.097 -3

START_TEST(add_36) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  // 10011111000100001001010011100101
  // 01000101100100001111100011011100
  // 11010000000000000000001001011010
  _a.bits[2] = 0b10011111000100001001010011100101;
  _a.bits[1] = 0b01000101100100001111100011011100;
  _a.bits[0] = 0b11010000000000000000001001011011;
  _b.bits[2] = 0b10111111011000000110001101000011;
  _b.bits[1] = 0b10000011101101011111101100111101;
  _b.bits[0] = 0b11100000000000000000001010000000;
  _d.bits[2] = 0b10110010001100111101001000000101;
  _d.bits[1] = 0b10011111100010011001000111111100;
  _d.bits[0] = 0b10011001100110011001110000110100;
  set_Scale(&_a, 3);
  set_Scale(&_b, 4);
  set_Scale(&_d, 3);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// max =79228162514264337593543950335

// otet=55150978765690771352898346.036
//   55150978765690771352898346.035
// a = 49228162514264337593543950.939 -3
// b =  5922816251426433759354395.0976 -4

// a = 49228162514264337593543950.939 -3
// b =  5922816251426433759354395.097 -3

START_TEST(add_37) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  // 10011111000100001001010011100101
  // 01000101100100001111100011011100
  // 11010000000000000000001001011010
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;

  _b = _a;
  set_Scale(&_a, 12);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 1);
}
END_TEST

START_TEST(add_38) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  // 10100011110101110000101000
  // 11110101110000101000111101011100
  // 00101000111101011100001010001111
  // 79228170437080589019.9777096543950335
  // 7922817043708058901997770965( 43950335
  // 79228162514264337593543950335
  // 15845632502852867518708790067
  // 158456325028528675187087900668
  _a.bits[2] = 0b10100011110101110000101000;
  _a.bits[1] = 0b11110101110000101000111101011100;
  _a.bits[0] = 0b00101000111101011100001010001111;
  _b.bits[0] = _b.bits[1] = _b.bits[2] = U_MAX_INT;
  // 11001100110011001100111000100
  // 10001100101101110101110111111010
  // 10110010000011010101100011010101
  _d.bits[2] = 0b11001100110011001100111000100;
  _d.bits[1] = 0b10001100101101110101110111111010;
  _d.bits[0] = 0b10110010000011010101100011010101;
  set_Scale(&_a, 7);
  set_Scale(&_b, 16);
  set_Scale(&_d, 8);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_39) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  // 10100011110101110000101000
  // 11110101110000101000111101011100
  // 00101000111101011100001010001111
  // 79228170437080589019.9777096543950335
  // 7922817043708058901997770965( 43950335
  // 79228162514264337593543950335
  // 138456325028528675187087900672
  // 15845632502852867518708790067
  // 158456325028528675187087900668
  _b.bits[0] = _b.bits[1] = _b.bits[2] = U_MAX_INT;
  _a = _b;
  _a.bits[0] = _a.bits[0] - 1;
  _b.bits[0] = _b.bits[0] - 1;

  // 11001100110011001100111000100
  // 10001100101101110101110111111010
  // 10110010000011010101100011010101
  _d.bits[2] = 0b110011001100110011001100110011;
  _d.bits[1] = 0b00110011001100110011001100110011;
  _d.bits[0] = 0b00110011001100110011001100110010;
  set_Scale(&_a, 16);
  set_Scale(&_b, 16);
  set_Scale(&_d, 15);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_40) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b11011111101100000011000110100001;
  _a.bits[1] = 0b11000001110110101111110110011110;
  _a.bits[0] = 0b11110000000000000000000000000010;
  _b = _a;
  _b.bits[0] = _b.bits[0] - 4;
  _d.bits[2] = 0b101100101111001101011010111001;
  _d.bits[1] = 0b11110011100100100011001010111001;
  _d.bits[0] = 0b01100011001100110011001100110011;
  set_Scale(&_a, 16);
  set_Scale(&_b, 16);
  set_Scale(&_d, 15);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_41) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b11011111101100000011000110100001;
  _a.bits[1] = 0b11000001110110101111110110011110;
  _a.bits[0] = 0b11110000000000000000000000000010;
  _b = _a;
  _d.bits[2] = 0b101100101111001101011010111001;
  _d.bits[1] = 0b11110011100100100011001010111001;
  _d.bits[0] = 0b01100011001100110011001100110100;
  set_Scale(&_a, 16);
  set_Scale(&_b, 16);
  set_Scale(&_d, 15);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(add_42) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_d);
  _a.bits[0] = 1;
  _b.bits[0] = 1;
  _d.bits[0] = 9;
  set_Scale(&_d, 1);
  set_Scale(&_b, 1);
  setSign(&_b, 1);
  ck_assert_int_eq(s21_add(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("\033[45m-=s21_add=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, add_1);
  tcase_add_test(tc_core, add_2);
  tcase_add_test(tc_core, add_3);
  tcase_add_test(tc_core, add_4);
  tcase_add_test(tc_core, add_5);
  tcase_add_test(tc_core, add_6);
  tcase_add_test(tc_core, add_7);
  tcase_add_test(tc_core, add_8);
  tcase_add_test(tc_core, add_9);
  tcase_add_test(tc_core, add_10);
  tcase_add_test(tc_core, add_11);
  tcase_add_test(tc_core, add_12);
  tcase_add_test(tc_core, add_13);
  tcase_add_test(tc_core, add_14);
  tcase_add_test(tc_core, add_15);
  tcase_add_test(tc_core, add_16);
  tcase_add_test(tc_core, add_17);
  tcase_add_test(tc_core, add_18);
  tcase_add_test(tc_core, add_19);
  tcase_add_test(tc_core, add_20);
  tcase_add_test(tc_core, add_21);
  tcase_add_test(tc_core, add_22);
  tcase_add_test(tc_core, add_23);
  tcase_add_test(tc_core, add_24);
  tcase_add_test(tc_core, add_25);
  tcase_add_test(tc_core, add_26);
  tcase_add_test(tc_core, add_27);
  tcase_add_test(tc_core, add_28);
  tcase_add_test(tc_core, add_29);
  tcase_add_test(tc_core, add_30);
  tcase_add_test(tc_core, add_31);
  tcase_add_test(tc_core, add_32);
  tcase_add_test(tc_core, add_33);
  tcase_add_test(tc_core, add_34);
  tcase_add_test(tc_core, add_35);
  tcase_add_test(tc_core, add_36);
  tcase_add_test(tc_core, add_37);
  tcase_add_test(tc_core, add_38);
  tcase_add_test(tc_core, add_39);
  tcase_add_test(tc_core, add_40);
  tcase_add_test(tc_core, add_41);
  tcase_add_test(tc_core, add_42);
  suite_add_tcase(s, tc_core);

  return s;
}
