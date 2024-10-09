#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal* res) {
  int sign = getSign(value);
  int scale = getScale(value);
  s21_decimal ten;
  s21_tozero(&ten);
  ten.bits[0] = 10;
  *res = value;
  set_Scale(res, 0);
  setSign(res, PLUS);
  for (int i = 0; i < scale; i++) {
    s21_mod(*res, ten, res);
  }
  if (res->bits[0] == 0 && res->bits[1] == 0 && res->bits[2] == 0) {
    sign = PLUS;
  }
  setSign(res, sign);
  return 0;
}