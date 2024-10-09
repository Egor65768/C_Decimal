#include "s21_decimal.h"

s21_decimal s21_mod(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  s21_decimal buf, mod;
  int status = 0;
  s21_tozero(result);
  s21_tozero(&mod);
  s21_tozero(&buf);
  s21_decimal buf_decimal_one;
  int sign_res = PLUS, sign_mod = PLUS;
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  if ((sign1 == PLUS && sign2 == MINUS) || (sign1 == MINUS && sign2 == PLUS)) {
    sign_res = MINUS;
  }
  if ((sign1 == MINUS && sign2 == MINUS) || (sign1 == MINUS && sign2 == PLUS)) {
    sign_mod = MINUS;
  }
  setSign(&value_1, PLUS);
  setSign(&value_2, PLUS);
  while (s21_is_less_or_equal(value_2, value_1)) {
    s21_tozero(&buf_decimal_one);
    setBit(&buf_decimal_one, 0, 1);
    process_small_numbers(&buf, value_1, &buf_decimal_one, &status, value_2);
    s21_add(*result, buf_decimal_one, result);
    multiply_decimals_with_status(value_2, &status, &buf, buf_decimal_one);
    s21_sub(value_1, buf, &value_1);
  }
  if (sign_res == MINUS) {
    setSign(result, MINUS);
  }
  if (sign_mod == MINUS) {
    setSign(&value_1, MINUS);
  }
  return value_1;
}

void process_small_numbers(s21_decimal *buf, s21_decimal value_1,
                           s21_decimal *buf_decimal_one, int *status,
                           s21_decimal value_2) {
  short flag_start = 0;
  int flag_overflow = 0;
  s21_tozero(buf);
  *status = 0;
  while (s21_is_less_or_equal(*buf, value_1) && flag_overflow == 0 &&
         *status == 0) {
    if (flag_start != 0) {
      buf_decimal_one = shift_left(buf_decimal_one, 1, status);
    }
    if (flag_overflow == 0 && *status == 0) {
      multiply_decimals_with_status(value_2, &flag_overflow, buf,
                                    *buf_decimal_one);
    }
    flag_start = 1;
  }
  buf_decimal_one = shift_right(buf_decimal_one, 1);
  *status = 0;
}
