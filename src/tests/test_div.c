#include "test.h"

START_TEST(div_1) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 824842;
  _b.bits[0] = 13;

  _d.bits[2] = 0b11001101000001000001100111010000;
  _d.bits[1] = 0b00100100101101101111101111010001;
  _d.bits[0] = 0b00011001011000100111011000100111;
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// otv=63449384615384615384615384615(3846
//  63449.384615384615384615384615
// max=79228162514264337593543950335

START_TEST(div_2) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 824842;
  _b.bits[0] = 13;
  setSign(&_a, 1);
  _d.bits[2] = 0b11001101000001000001100111010000;
  _d.bits[1] = 0b00100100101101101111101111010001;
  _d.bits[0] = 0b00011001011000100111011000100111;
  set_Scale(&_d, 24);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_3) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 824842;
  _b.bits[0] = 13;
  setSign(&_a, 1);
  setSign(&_b, 1);
  _d.bits[2] = 0b11001101000001000001100111010000;
  _d.bits[1] = 0b00100100101101101111101111010001;
  _d.bits[0] = 0b00011001011000100111011000100111;
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_4) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 59;
  _b.bits[0] = 9;
  _d.bits[2] = 0b11010011110100100100100011011011;
  _d.bits[1] = 0b10010111011001000110010011101110;
  _d.bits[0] = 0b00010011100011100011100011100100;
  set_Scale(&_d, 28);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// max=79228162514264337593543950335

START_TEST(div_5) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 78946;
  _b.bits[0] = 3;
  _d.bits[2] = 0b1010101000001111000100010010110;
  _d.bits[1] = 0b01111011111010000001110110001110;
  _d.bits[0] = 0b10001011010101010101010101010101;
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// res=26315.33333333333333333333333
// max=79228162514264337593543950335

START_TEST(div_6) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 125456;
  _b.bits[0] = 3;
  _d.bits[2] = 0b10000111000111111001011100011110;
  _d.bits[1] = 0b10000101101110010011011100000001;
  _d.bits[0] = 0b01011010101010101010101010101010;
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// res=41818.666666666666666666666666666
// otv=41818666666666666666666666666 -24
// max=79228162514264337593543950335

START_TEST(div_7) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b1;
  _a.bits[1] = 0b00100111111011110101000101001000;
  _a.bits[0] = 0b01111111001010001010101001000110;
  _b.bits[0] = 0b11001000111001110011000110111;
  _d.bits[2] = 0b10100011100010011101001011011101;
  _d.bits[1] = 0b00101011101101001000100000110010;
  _d.bits[0] = 0b01110100000110111111110011010001;
  set_Scale(&_d, 18);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// a=21324352132435454534
// b=421324343
// res=50612675215.007585104096394449(25212878098
// otv=50612675215007585104096394449
// max=79228162514264337593543950335

START_TEST(div_8) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 1234523;
  _b.bits[0] = 0;
  ck_assert_int_eq(s21_div(_a, _b, &_c), 3);
}
END_TEST

START_TEST(div_9) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 0;
  _b.bits[0] = 1234;
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_10) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 954527;
  _b.bits[0] = 12;
  _d.bits[2] = 0b11001101100111011011111110100;
  _d.bits[1] = 0b01001010001111110110000110011001;
  _d.bits[0] = 0b11101100110010101010101010101010;
  set_Scale(&_d, 23);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}

START_TEST(div_11) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  _d.bits[0] = 1;
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}

END_TEST

START_TEST(div_12) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  set_Scale(&_b, 12);
  _d.bits[1] = 0b11101000;
  _d.bits[0] = 0b11010100101001010001000000000000;
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_13) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  set_Scale(&_b, 28);

  _d.bits[2] = 0b100000010011111100111001011110;
  _d.bits[1] = 0b00111110001001010000001001100001;
  _d.bits[0] = 0b00010000000000000000000000000000;

  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST
// otv=10000000000000000000000000000
// max=79228162514264337593543950335

START_TEST(div_14) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  set_Scale(&_b, 29);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 1);
}
END_TEST

START_TEST(div_15) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  setSign(&_a, 1);
  set_Scale(&_b, 29);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 2);
}
END_TEST

START_TEST(div_16) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  setSign(&_a, 1);
  set_Scale(&_b, 31);
  set_Scale(&_a, 2);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 2);
}
END_TEST

START_TEST(div_17) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = _a.bits[1] = _a.bits[2] = U_MAX_INT;
  _b = _a;
  setSign(&_a, 1);
  setSign(&_b, 1);
  set_Scale(&_b, 31);
  set_Scale(&_a, 2);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 1);
}
END_TEST

START_TEST(div_18) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 125;
  _b.bits[0] = 5;
  _d.bits[0] = 25;
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_19) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 125;
  _b.bits[0] = 5;
  _d.bits[0] = 25;
  set_Scale(&_a, 25);
  set_Scale(&_d, 25);
  setSign(&_b, 1);
  setSign(&_d, 1);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_20) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 0b01101001111101110100011011111110;
  _a.bits[1] = 0b1011010011011000100010;
  _b.bits[0] = 2156346;
  _d.bits[0] = 0b11100010111001101000011011000010;
  _d.bits[1] = 0b00101100100001111000010101011110;
  _d.bits[2] = 0b10111110101100001110011111011110;
  set_Scale(&_a, 4);
  set_Scale(&_b, 7);
  set_Scale(&_d, 16);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=12725895386580734 -4
// b=2156346 -7
// res=5901601777535.1144946126456514
// otv=59016017775351144946126456514(86357013
// max=79228162514264337593543950335

START_TEST(div_21) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b111;
  _a.bits[1] = 0b01111010000101011101000100100101;
  _a.bits[0] = 0b11011001100001111001111111100010;
  _b.bits[1] = 0b1001110011100;
  _b.bits[0] = 0b00011111010010101101010001100101;
  _d.bits[2] = 0b11001110101100011001011011010101;
  _d.bits[1] = 0b00011011000101111011110010111001;
  _d.bits[0] = 0b01011011000111100010011100001000;
  setSign(&_a, 1);
  setSign(&_d, 1);
  set_Scale(&_a, 12);
  set_Scale(&_b, 10);
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=137924375.923598532578
// b=2156.1260823653
// res=63968.604179350028135916513031611153150
// otv=63968.604179350028135916513032
// max=79228162514264337593543950335

START_TEST(div_22) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b1010110011;
  _a.bits[1] = 0b10011010011100001100110101000010;
  _a.bits[0] = 0b00111000011110010000101001111011;
  _b.bits[1] = 0b10;
  _b.bits[0] = 0b00100000001011001100001110100011;
  _d.bits[2] = 0b101101001001101111010110101000;
  _d.bits[1] = 0b00101100000100111001110000011011;
  _d.bits[0] = 0b00110011010100110000010001101011;
  setSign(&_a, 1);
  setSign(&_b, 1);
  set_Scale(&_a, 4);
  set_Scale(&_b, 7);
  set_Scale(&_d, 13);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=1275782877529683165.4523
// b=912.9739171
// res=1397392470512324.525040146954708658237088644
// otv=1397392470512324.5250401469547
// max=79228162514264337593543950335

START_TEST(div_23) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b10011111010010111111111101111101;
  _a.bits[1] = 0b01011111110011010011011001001100;
  _a.bits[0] = 0b01000001101111111111111111111111;
  _b.bits[2] = 0b11001101001100101111001110;
  _b.bits[1] = 0b10101111010100101010100100000001;
  _b.bits[0] = 0b11110000111101011100001010001111;
  _d.bits[2] = 0b10100000100010010011001110011101;
  _d.bits[1] = 0b00000001010011011100101000110101;
  _d.bits[0] = 0b10010110100010000011111010111000;
  set_Scale(&_a, 4);
  set_Scale(&_b, 7);
  set_Scale(&_d, 24);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=4929999251426433759354395.0335
// b=99228162514264337593.5439503
// res=49683.468145625814615957454519622850198995
// otv=49683.468145625814615957454520
// max=79228162514264337593543950335

START_TEST(div_24) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[2] = 0b11011;
  _a.bits[1] = 0b11100000110110011111001001011010;
  _a.bits[0] = 0b00100010101111111111111111111111;
  _b.bits[2] = 0b11001101001100101111001110;
  _b.bits[1] = 0b10101111010100101010100100000001;
  _b.bits[0] = 0b11110000111101011100001010001111;
  _d.bits[2] = 0b1000100100101110111;
  _d.bits[1] = 0b10111111001101100111100101111100;
  _d.bits[0] = 0b00110000100000111011111111011110;
  set_Scale(&_a, 4);
  set_Scale(&_b, 7);
  set_Scale(&_d, 28);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// a=51426433759354395.0335
// b=99228162514264337593.5439503
// res=0.0005182644972586456519524318(0335850463520990099
// otv=5182644972586456519524318
// max=79228162514264337593543950335

START_TEST(div_25) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 1;
  _b.bits[0] = 1000000;
  _d.bits[0] = 1;
  set_Scale(&_d, 6);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

// max=79228162514264337593543950335

START_TEST(div_26) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 1;
  _b.bits[0] = 3;
  _d.bits[2] = 0b1010110001010100010011001010;
  _d.bits[1] = 0b00010100101101110000000011001011;
  _d.bits[0] = 0b00000101010101010101010101010101;
  set_Scale(&_d, 28);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
  ck_assert_int_eq(_c.bits[0], _d.bits[0]);
  ck_assert_int_eq(_c.bits[1], _d.bits[1]);
  ck_assert_int_eq(_c.bits[2], _d.bits[2]);
  ck_assert_int_eq(_c.bits[3], _d.bits[3]);
}
END_TEST

START_TEST(div_27) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 13454365;
  _b.bits[0] = 3;
  set_Scale(&_b, 23);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 1);
}
END_TEST

START_TEST(div_28) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 13454365;
  _b.bits[0] = 3;
  set_Scale(&_b, 22);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 0);
}
END_TEST

START_TEST(div_29) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 13454365;
  _b.bits[0] = 3;
  setSign(&_b, 1);
  set_Scale(&_b, 23);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 2);
}
END_TEST

START_TEST(div_30) {
  s21_decimal _a, _b, _c, _d;
  s21_tozero(&_a);
  s21_tozero(&_b);
  s21_tozero(&_c);
  s21_tozero(&_d);
  _a.bits[0] = 13454365;
  _b.bits[0] = 3;
  setSign(&_b, 1);
  setSign(&_a, 1);
  set_Scale(&_b, 23);
  ck_assert_int_eq(s21_div(_a, _b, &_c), 1);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=s21_div=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, div_1);
  tcase_add_test(tc_core, div_2);
  tcase_add_test(tc_core, div_3);
  tcase_add_test(tc_core, div_4);
  tcase_add_test(tc_core, div_5);
  tcase_add_test(tc_core, div_6);
  tcase_add_test(tc_core, div_7);
  tcase_add_test(tc_core, div_8);
  tcase_add_test(tc_core, div_9);
  tcase_add_test(tc_core, div_10);
  tcase_add_test(tc_core, div_11);
  tcase_add_test(tc_core, div_12);
  tcase_add_test(tc_core, div_13);
  tcase_add_test(tc_core, div_14);
  tcase_add_test(tc_core, div_15);
  tcase_add_test(tc_core, div_16);
  tcase_add_test(tc_core, div_17);
  tcase_add_test(tc_core, div_18);
  tcase_add_test(tc_core, div_19);
  tcase_add_test(tc_core, div_20);
  tcase_add_test(tc_core, div_21);
  tcase_add_test(tc_core, div_22);
  tcase_add_test(tc_core, div_23);
  tcase_add_test(tc_core, div_24);
  tcase_add_test(tc_core, div_25);
  tcase_add_test(tc_core, div_26);
  tcase_add_test(tc_core, div_27);
  tcase_add_test(tc_core, div_28);
  tcase_add_test(tc_core, div_29);
  tcase_add_test(tc_core, div_30);
  suite_add_tcase(s, tc_core);

  return s;
}
