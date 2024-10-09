#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_decimal zero, mod, res, ten, buf_res;
  s21_tozero(&buf_res);
  s21_tozero(result);
  s21_tozero(&zero);
  s21_tozero(&res);
  s21_tozero(&ten);
  ten.bits[0] = TenMask;
  int res_scale = getScale(value_1) - getScale(value_2);
  int status = 0;
  int buf_bit = 0;
  int sign = PLUS;

  if ((getSign(value_1) == MINUS && getSign(value_2) == PLUS) ||
      (getSign(value_1) == PLUS && getSign(value_2) == MINUS)) {
    sign = MINUS;
  }
  setSign(&value_1, PLUS);
  setSign(&value_2, PLUS);
  set_Scale(&value_1, 0);
  set_Scale(&value_2, 0);
  if (s21_is_equal(zero, value_2)) {
    status = 3;
  } else {
    mod = s21_mod(value_1, value_2, &res);
    add_decimal_values(*result, res, &status, result);
    buf_res = *result;
    while (s21_is_equal(zero, mod) != 1 && res_scale < MAX_POW &&
           buf_bit == 0) {
      scale_up_for_division(&mod, value_2, &res_scale, &buf_bit, result, ten,
                            &buf_res);
      mod = s21_mod(mod, value_2, &res);
      if (buf_bit == 0) {
        add_decimal_values(*result, res, &buf_bit, result);
      }
      if (buf_bit == 0) {
        buf_res = *result;
      }
      if (buf_bit != 0 || res_scale == 28) {
        if (round_division_result(mod, res, value_2) == 1 &&
            getBit(buf_res, 0) == 1) {
          ten.bits[0] = 1;
          buf_bit = 0;
          add_decimal_values(buf_res, ten, &buf_bit, &buf_res);
          buf_bit = 1;
        }
      }
    }
    scale_and_finalize_division(res_scale, buf_bit, buf_res, sign, &status,
                                result);
  }
  if (sign == MINUS) {
    setSign(result, MINUS);
  }
  return status;
}

void scale_and_finalize_division(int res_scale, int buf_bit,
                                 s21_decimal buf_res, int sign, int* status,
                                 s21_decimal* result) {
  s21_decimal ten;
  s21_tozero(&ten);
  if (res_scale < 0 && buf_bit == 0) {
    while (res_scale != 0 && buf_bit == 0) {
      ten.bits[0] = TenMask;
      multiply_decimals_with_status(ten, &buf_bit, &buf_res, buf_res);
      if (buf_bit == 0) {
        res_scale++;
      }
    }
  }
  if (res_scale < 0 && sign == 0) {
    *status = 1;
  } else if (res_scale < 0 && sign == 1) {
    *status = 2;
  } else {
    *result = buf_res;
    result = set_Scale(result, res_scale);
  }
}

int round_division_result(s21_decimal mod, s21_decimal res,
                          s21_decimal value_2) {
  s21_decimal result, ten, trash;
  s21_tozero(&ten);
  ten.bits[0] = TenMask;
  int res_scale = 0;
  int status = 0;
  s21_tozero(&result);
  add_decimal_values(result, res, &status, &result);
  for (int i = 0; i < 2; i++) {
    scale_up_for_division(&mod, value_2, &res_scale, &status, &result, ten,
                          &trash);
    mod = s21_mod(mod, value_2, &res);
    add_decimal_values(result, res, &status, &result);
  }
  bank_round(result, &result, 2, -1);
  ten.bits[0] = FiveMask;
  if (s21_is_less_or_equal(ten, result) == 1) {
    status = 1;
  } else {
    status = 0;
  }
  return status;
}

void scale_up_for_division(s21_decimal* mod, s21_decimal value_2,
                           int* res_scale, int* buf_bit, s21_decimal* result,
                           s21_decimal ten, s21_decimal* buf_res) {
  while (s21_is_less(*mod, value_2) && *res_scale < 28 && *buf_bit == 0) {
    multiply_decimals_with_status(ten, buf_bit, mod, *mod);
    multiply_decimals_with_status(ten, buf_bit, result, *result);
    if (*buf_bit == 0) {
      *buf_res = *result;
      *res_scale = *res_scale + 1;
    }
  }
}