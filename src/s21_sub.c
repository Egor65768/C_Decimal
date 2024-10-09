#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_tozero(result);
  int status = 0;
  int buf_bit = 0;
  int operation = 0;
  if (getScale(value_1) != getScale(value_2) || getScale(value_1) > 28) {
    if (getSign(value_1) == getSign(value_2)) {
      operation = 2;
    } else {
      operation = 1;
    }
    reduction_common_denominator(&value_1, &value_2, operation);
  }
  s21_decimal val1 = value_1, val2 = value_2;
  int falg_sign = PLUS;
  int sign1 = getSign(val1);
  int sign2 = getSign(val2);
  if (sign1 == PLUS && sign2 == PLUS) {
    if (s21_is_less(value_1, value_2)) {
      val1 = value_2;
      val2 = value_1;
      falg_sign = MINUS;
    }
    perform_decimal_subtraction(val1, val2, result);
  } else if (sign1 == MINUS && sign2 == PLUS) {
    add_decimal_values(value_1, value_2, &buf_bit, result);
    falg_sign = MINUS;
    if (buf_bit > 0) {
      status = 2;
    }
  } else if (sign1 == PLUS && sign2 == MINUS) {
    add_decimal_values(value_1, value_2, &buf_bit, result);
    if (buf_bit > 0) {
      status = 1;
    }
  } else if (sign1 == MINUS && sign2 == MINUS) {
    val1 = value_2;
    val2 = value_1;
    setSign(&val1, PLUS);
    setSign(&val2, PLUS);
    if (s21_is_less(val1, val2)) {
      val1 = value_1;
      val2 = value_2;
      falg_sign = MINUS;
    }
    perform_decimal_subtraction(val1, val2, result);
  }
  if (falg_sign == MINUS) {
    setSign(result, MINUS);
  }
  set_Scale(result, getScale(value_1));
  return status;
}

void perform_decimal_subtraction(s21_decimal val1, s21_decimal val2,
                                 s21_decimal* result) {
  int bit1 = 0, bit2 = 0, buf_bit = 0;
  for (int i = 0; i < NUMBER_BITS_DECIMAL; i++) {
    bit1 = getBit(val1, i);
    bit2 = getBit(val2, i);
    if (bit1 - bit2 < 0) {
      for (int j = i; j < NUMBER_BITS_DECIMAL; j++) {
        buf_bit = getBit(val1, j);
        if (buf_bit == 1) {
          setBit(&val1, j, 0);
          for (int k = j - 1; k >= i; k = k - 1) {
            setBit(&val1, k, 1);
          }
          j = NUMBER_BITS_DECIMAL;
        }
      }
      bit1 = getBit(val1, i);
      buf_bit = 1;
    }
    buf_bit = buf_bit + bit1 - bit2;
    result = setBit(result, i, buf_bit);
    buf_bit = 0;
  }
}