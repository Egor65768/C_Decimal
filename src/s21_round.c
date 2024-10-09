#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *res) {
  int scale = getScale(value);
  int sign = getSign(value);
  setSign(&value, PLUS);
  bank_round(value, res, scale, -2);
  setSign(res, sign);
  return 0;
}