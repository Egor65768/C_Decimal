#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_tozero(result);
  int status = 0;
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  int buf_bit = 0;
  int flag_sign = PLUS;
  int operation = 0;
  if (getScale(value_1) != getScale(value_2) || getScale(value_1) > 28) {
    if (sign1 == sign2) {
      operation = 1;
    } else {
      operation = 2;
    }
    reduction_common_denominator(&value_1, &value_2, operation);
  }
  if (sign1 == MINUS && sign2 == MINUS) {
    flag_sign = MINUS;
  } else if (sign1 == PLUS && sign2 == MINUS) {
    setSign(&value_2, PLUS);
    status = s21_sub(value_1, value_2, result);
    flag_sign = 4;
  } else if (sign1 == MINUS && sign2 == PLUS) {
    setSign(&value_1, PLUS);
    status = s21_sub(value_2, value_1, result);
    flag_sign = 4;
  }
  if (flag_sign != 4) {
    add_decimal_values(value_1, value_2, &buf_bit, result);
    if (buf_bit == 1 && getScale(value_1) > 0) {
      add_decimals_with_float_handling(&value_1, &value_2, result);
      buf_bit = 0;
    }
  }
  if (flag_sign == 1) {
    setSign(result, 1);
  }
  set_Scale(result, getScale(value_1));
  if (buf_bit == 1 && flag_sign == 0) {
    status = 1;
  } else if (buf_bit == 1 && flag_sign == 1) {
    status = 2;
  }
  return status;
}

void add_decimals_with_float_handling(s21_decimal* value_1,
                                      s21_decimal* value_2,
                                      s21_decimal* result) {
  s21_decimal ten, val1, val2;
  int buf_bit = 0, scale;
  scale = getScale(*value_1);
  set_Scale(value_1, 0);
  set_Scale(value_2, 0);
  s21_tozero(&ten);
  ten.bits[0] = TenMask;
  val1 = s21_mod(*value_1, ten, value_1);
  val2 = s21_mod(*value_2, ten, value_2);
  add_decimal_values(val1, val2, &buf_bit, result);
  if (s21_is_less_or_equal(ten, *result)) {
    ten.bits[0] = 1;
    add_decimal_values(*value_1, ten, &buf_bit, value_1);
    ten.bits[0] = 10;
    perform_decimal_subtraction(*result, ten, result);
  }
  ten.bits[0] = FiveMask;
  if (s21_is_less_or_equal(ten, *result) &&
      (getBit(*value_1, 0) != getBit(*value_2, 0))) {
    ten.bits[0] = 1;
    add_decimal_values(*value_1, ten, &buf_bit, value_1);
  }
  add_decimal_values(*value_1, *value_2, &buf_bit, result);
  set_Scale(value_1, scale - 1);
}

void add_decimal_values(s21_decimal value_1, s21_decimal value_2, int* buf_bit,
                        s21_decimal* result) {
  int bit1, bit2;
  for (int i = 0; i < NUMBER_BITS_DECIMAL; i++) {
    bit1 = getBit(value_1, i);
    bit2 = getBit(value_2, i);
    *buf_bit = *buf_bit + bit1 + bit2;
    if (*buf_bit == 0) {
      result = setBit(result, i, 0);
    } else if (*buf_bit == 1) {
      result = setBit(result, i, 1);
      *buf_bit = 0;
    } else if (*buf_bit == 2) {
      result = setBit(result, i, 0);
      *buf_bit = 1;
    } else if (*buf_bit == 3) {
      result = setBit(result, i, 1);
      *buf_bit = 1;
    }
  }
}
