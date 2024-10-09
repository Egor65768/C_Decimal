#include <stdio.h>

#include "test.h"
#define UINT_MAX 4294967295

START_TEST(mulmul_1) {
  s21_decimal _a, _b, _c;
  int number1 = -22111;
  int number2 = 234;
  int result;
  int status;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  status = s21_mul(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 * number2);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_2) {
  s21_decimal _a, _b, _c;
  int number1 = -111;
  int number2 = -12234;
  int result;
  int status;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  status = s21_mul(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 * number2);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_3) {
  s21_decimal _a, _b, _c;
  int number1 = 22111;
  int number2 = -234;
  int result;
  int status;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  status = s21_mul(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 * number2);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_4) {
  s21_decimal _a, _b, _c;
  int number1 = 0;
  int number2 = 234;
  int result;
  int status;
  s21_from_int_to_decimal(number1, &_a);
  s21_from_int_to_decimal(number2, &_b);
  status = s21_mul(_a, _b, &_c);
  s21_from_decimal_to_int(_c, &result);
  ck_assert_int_eq(result, number1 * number2);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_5) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  _d.bits[0] = 0b00000000000000000000000000000001;
  _d.bits[1] = 0b11111111111111111111111111111110;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_6) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  setSign(&_a, 1);
  setSign(&_d, 1);
  _d.bits[0] = 0b00000000000000000000000000000001;
  _d.bits[1] = 0b11111111111111111111111111111110;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_7) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  setSign(&_a, 1);
  setSign(&_b, 1);
  _d.bits[0] = 0b00000000000000000000000000000001;
  _d.bits[1] = 0b11111111111111111111111111111110;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_8) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  _a.bits[1] = 123456;
  _b.bits[1] = 2345;
  _d.bits[0] = 0b00000000000000000000000000000001;
  _d.bits[1] = 0b11111111111111100001010010010101;
  _d.bits[2] = 0b10001010000110110011110101001;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mulmul_9) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 0b10001010111011000000100101110011;
  _a.bits[1] = 0b01110101100011000101010001000001;
  _a.bits[2] = 0b11010001101101110001;
  _b.bits[0] = 1234;
  _d.bits[2] = 0b111111001011100100100011101000;
  _d.bits[1] = 0b10011110011011100010001111101111;
  _d.bits[0] = 0b10100101110001011000110001010110;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mulmul_10) {
  s21_decimal _a, _b, _c, _d;
  int status;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 0b10001010111011000000100101110011;
  _a.bits[1] = 0b01110101100011000101010001000001;
  _a.bits[2] = 0b11010001101101110001;
  _b.bits[0] = 12345;
  status = s21_mul(_a, _b, &_c);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(mulmul_11) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 12345;
  set_Scale(&_a, 12);
  set_Scale(&_b, 3);
  set_Scale(&_d, 10);
  _d.bits[2] = 0b11111100110100110101101010000;
  _d.bits[1] = 0b10110000111100100111101110110010;
  _d.bits[0] = 0b11111110110001010110110101011100;
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// 1956238406209581915636123886272
// max =79228162514264337593543950335
// otv =9780716662385932475923000668 10
// 19553510507894505604385180758

START_TEST(mulmul_12) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 5827834;
  set_Scale(&_a, 3);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 1);
}
END_TEST

START_TEST(mulmul_13) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 924;
  set_Scale(&_a, 2);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 1);
}
END_TEST

START_TEST(mulmul_14) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 924;
  setSign(&_b, 1);
  set_Scale(&_a, 2);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(mulmul_15) {
  s21_decimal _a, _b, _c;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1000;
  setSign(&_b, 1);
  set_Scale(&_a, 2);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(ten_1) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1000;
  setSign(&_b, 1);
  set_Scale(&_a, 5);
  set_Scale(&_b, 0);
  _d = _a;
  set_Scale(&_d, 2);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(ten_2) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1000000;
  set_Scale(&_a, 5);
  set_Scale(&_b, 3);
  _d = _a;
  set_Scale(&_d, 2);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(ten_3) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = U_MAX_INT;
  _b.bits[0] = 100000000;
  set_Scale(&_a, 3);
  set_Scale(&_b, 2);
  _d.bits[1] = 0b1111100111;
  _d.bits[0] = 0b11111111111111111111110000011000;
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(ten_4) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 100000000;
  set_Scale(&_a, 3);
  set_Scale(&_b, 2);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 1);
}
END_TEST

START_TEST(ten_5) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 100000000;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 2);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(ten_6) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _d = _a;
  _b.bits[0] = 1;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 2);

  setSign(&_d, 1);
  set_Scale(&_d, 5);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(ten_7) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _d = _a;
  _b.bits[0] = 1;
  setSign(&_a, 1);
  setSign(&_b, 1);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(ten_8) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _d = _a;
  _b.bits[0] = 1;
  setSign(&_a, 1);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(perepoln_1) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1001;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(perepoln_2) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 1000;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
}
END_TEST

START_TEST(perepoln_3) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b.bits[0] = 999;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 0);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
}
END_TEST

START_TEST(perepoln_4) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  _b.bits[1] = U_MAX_INT / 2;
  setSign(&_a, 1);
  set_Scale(&_a, 3);
  set_Scale(&_b, 3);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(perepoln_5) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = U_MAX_INT;
  _b.bits[0] = U_MAX_INT;
  _b.bits[1] = U_MAX_INT / 2;
  setSign(&_a, 1);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 2);
}
END_TEST

START_TEST(perepoln_6) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b110000010;
  _a.bits[1] = 0b01011010000011110101000011000110;
  _a.bits[0] = 0b10101110110110011011101110000011;
  _b.bits[1] = 0b1000111111111001101;
  _b.bits[0] = 0b01001111011010111000000011001011;
  _d.bits[2] = 0b11101001010011101111110111111;
  _d.bits[1] = 0b11000101101011111010011001000011;
  _d.bits[0] = 0b00111001110101001000001101011100;

  setSign(&_a, 1);
  setSign(&_d, 1);
  set_Scale(&_a, 9);
  set_Scale(&_b, 4);
  set_Scale(&_d, 4);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=7126932706854.218349443
// b=126641968431.1243
//   79228162514264337593543950335
//   902568786872179175264803.3117 747687649

START_TEST(perepoln_7) {
  s21_decimal _a, _b, _c, _d;

  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[1] = 0b111111010011000011010011;
  _a.bits[0] = 0b10001001111100011011101110000011;
  _b.bits[1] = 0b1000111111111001101;
  _b.bits[0] = 0b01001111011010111000000011001011;
  _d.bits[2] = 0b11101001010011001110101101110;
  _d.bits[1] = 0b11111001110101110001011000100100;
  _d.bits[0] = 0b00011011111110110110110000101111;

  setSign(&_a, 1);
  setSign(&_d, 1);
  set_Scale(&_a, 9);
  set_Scale(&_b, 4);
  set_Scale(&_d, 9);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=7126932706854.218349443
// b=126641968431.1243
//   79228162514264337593543950335
//   9025374702105747811.311774768
//   902537470210574781131177476.87649 7649

START_TEST(perepoln_8) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[1] = 0b111111010011000011010011;
  _a.bits[0] = 0b10001001111100011011101110000011;
  _b.bits[1] = 0b1000111111111001101;
  _b.bits[0] = 0b01001111011010111000000011001011;
  _d.bits[2] = 0b11101001010011001110101101110;
  _d.bits[1] = 0b11111001110101110001011000100100;
  _d.bits[0] = 0b00011011111110110110110000101111;

  setSign(&_a, 1);
  setSign(&_d, 1);
  set_Scale(&_a, 1);
  set_Scale(&_b, 4);
  set_Scale(&_d, 1);
  ck_assert_int_eq(s21_mul(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("\033[45m-=s21_mul=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, mul_1);
  tcase_add_test(tc_core, mul_2);
  tcase_add_test(tc_core, mul_3);
  tcase_add_test(tc_core, mul_4);
  tcase_add_test(tc_core, mul_5);
  tcase_add_test(tc_core, mul_6);
  tcase_add_test(tc_core, mul_7);
  tcase_add_test(tc_core, mulmul_1);
  tcase_add_test(tc_core, mulmul_2);
  tcase_add_test(tc_core, mulmul_3);
  tcase_add_test(tc_core, mulmul_4);
  tcase_add_test(tc_core, mulmul_5);
  tcase_add_test(tc_core, mulmul_6);
  tcase_add_test(tc_core, mulmul_7);
  tcase_add_test(tc_core, mulmul_8);
  tcase_add_test(tc_core, mulmul_9);
  tcase_add_test(tc_core, mulmul_10);
  tcase_add_test(tc_core, mulmul_11);
  tcase_add_test(tc_core, mulmul_12);
  tcase_add_test(tc_core, mulmul_13);
  tcase_add_test(tc_core, mulmul_14);
  tcase_add_test(tc_core, mulmul_15);
  tcase_add_test(tc_core, ten_1);
  tcase_add_test(tc_core, ten_2);
  tcase_add_test(tc_core, ten_3);
  tcase_add_test(tc_core, ten_4);
  tcase_add_test(tc_core, ten_5);
  tcase_add_test(tc_core, ten_6);
  tcase_add_test(tc_core, ten_7);
  tcase_add_test(tc_core, ten_8);
  tcase_add_test(tc_core, perepoln_1);
  tcase_add_test(tc_core, perepoln_2);
  tcase_add_test(tc_core, perepoln_3);
  tcase_add_test(tc_core, perepoln_4);
  tcase_add_test(tc_core, perepoln_5);
  tcase_add_test(tc_core, perepoln_6);
  tcase_add_test(tc_core, perepoln_7);
  tcase_add_test(tc_core, perepoln_8);
  suite_add_tcase(s, tc_core);

  return s;
}
