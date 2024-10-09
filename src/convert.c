#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 1;
  if (dst) {
    error = 0;
    s21_tozero(dst);
    dst->bits[0] = abs(src);
    if (src < 0) setSign(dst, MINUS);
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 1;
  if (src.bits[1] == 0 && src.bits[2] == 0) {
    *dst = src.bits[0];
    if (getSign(src)) {
      *dst *= -1;
    }
    *dst /= (int)pow(10, getScale(src));
    error = 0;
  }
  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 1;
  if (dst != NULL) {
    int scale = getScale(src);
    long double tmp = 0;
    for (int i = 0; i < NUMBER_BITS_DECIMAL; i++) {
      tmp += pow(2, i) * getBit(src, i);
    }
    while (scale > 0) {
      tmp /= 10;
      scale--;
    }
    if (getSign(src) == 1) {
      tmp *= -1.0;
    }
    *dst = tmp;
    error = 0;
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if ((src != src) || fabs(src) > MAX_DECIMAL || src == (1.0 / 0.0) ||
      src == -(1.0 / 0.0) || !dst) {
    error = 1;
  }
  if (!error) {
    s21_tozero(dst);
    int sign = PLUS;
    if (src < 0) {
      sign = MINUS;
      src = fabs(src);
    }
    int temp = (int)src;
    int scale = 0;
    while (src - ((float)temp / (int)(pow(10, scale))) != 0) {
      scale++;
      temp = src * (int)(pow(10, scale));
    }
    s21_from_int_to_decimal(temp, dst);
    if (sign) setSign(dst, MINUS);
    set_Scale(dst, scale);
  }
  return error;
}
