#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *res) {
  int sign = getSign(value);
  if (value.bits[0] != 0 || value.bits[1] != 0 || value.bits[2] != 0) {
    if (sign == PLUS) {
      sign = MINUS;
    } else {
      sign = PLUS;
    }
  }
  setSign(res, sign);
  return 0;
}