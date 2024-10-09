#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *res) {
  int sign = getSign(value);
  int scale = getScale(value), buf = 0;
  s21_decimal ten;
  s21_tozero(&ten);
  ten.bits[0] = 10;
  *res = value;
  set_Scale(res, 0);
  setSign(res, PLUS);
  for (int i = 0; i < scale; i++) {
    s21_mod(*res, ten, res);
  }
  if (sign == MINUS) {
    ten.bits[0] = 1;
    add_decimal_values(*res, ten, &buf, res);
  }
  setSign(res, sign);
  return 0;
}