#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal ten, pow;
  s21_decimal buf;
  s21_tozero(&buf);
  s21_tozero(&ten);
  s21_tozero(&pow);
  pow.bits[0] = OneMask;
  s21_tozero(result);
  int status = 0;
  int sign = signmul(&value_1, &value_2);
  setSign(&value_1, 0);
  setSign(&value_2, 0);
  checking_max_pow(&value_1);
  checking_max_pow(&value_2);
  int scale1 = getScale(value_1);
  int scale2 = getScale(value_2);
  int scale_res = scale1 + scale2;
  int number_of_bits = getLastBit(value_1) + getLastBit(value_2) + 2;
  int flag_ten = multiply_decimal_by_ten_with_scale(value_1, value_2, result);
  if (flag_ten != -1) {
    status = flag_ten;
  } else if (number_of_bits > NUMBER_BITS_DECIMAL && scale_res != 0) {
    status = multiply_large_decimals(value_1, value_2, result);
  } else if (scale_res == 0 && number_of_bits > NUMBER_BITS_DECIMAL) {
    status = 1;
  } else {
    set_Scale(&value_1, 0);
    set_Scale(&value_2, 0);
    multiply_decimals_with_status(value_1, &status, result, value_2);
    set_Scale(result, scale_res);
    checking_max_pow(result);
  }
  if (sign == MINUS) {
    result = setSign(result, MINUS);
  }
  if (status == 1 && sign == MINUS) {
    status = 2;
  }
  return status;
}

int scale_pow(s21_decimal value) {
  s21_decimal pow, buff;
  s21_tozero(&buff);
  buff.bits[0] = 1;
  s21_tozero(&pow);
  pow.bits[0] = 10;
  int n = 0, status = 0;
  while (s21_is_less_or_equal(buff, value) && status == 0) {
    multiply_decimals_with_status(buff, &status, &buff, pow);
    n++;
  }
  n = n - 1;
  return n;
}

void multiply_decimals_with_status(s21_decimal value_1, int *status,
                                   s21_decimal *result, s21_decimal value_2) {
  s21_decimal res;
  s21_tozero(result);
  s21_decimal *buf = &value_2;
  int nul = 0, bit = 0;
  for (int i = 0; i < NUMBER_BITS_DECIMAL && *status == 0; i++) {
    bit = getBit(value_1, i);
    if (bit == 1) {
      shift_left(buf, i - nul, status);
      if (*status == 0) {
        res = *result;
        *status = s21_add(res, *buf, result);
        if (*status != 0) {
          *result = res;
        }
      }
      nul = i;
    }
  }
}

int signmul(s21_decimal *value_1, s21_decimal *value_2) {
  int sign1 = getSign(*value_1);
  int sign2 = getSign(*value_2);
  int sign = 0;
  if ((sign1 == 0 && sign2 == 1) || (sign1 == 1 && sign2 == 0)) {
    sign = 1;
  }
  value_1 = setSign(value_1, 0);
  value_2 = setSign(value_2, 0);
  return sign;
}

int multiply_large_decimals(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result) {
  int status = 0;
  int flag = 0, powsm;
  s21_decimal ten, pow;
  s21_tozero(&ten);
  s21_tozero(&pow);
  s21_tozero(result);
  int scale1 = getScale(value_1);
  int scale2 = getScale(value_2);
  set_Scale(&value_2, 0);
  set_Scale(&value_1, 0);
  s21_decimal small = value_1, big = value_2;
  if (s21_is_less(value_1, value_2) != 1) {  //<
    big = value_1;
    small = value_2;
    flag = scale1;
    scale1 = scale2;
    scale2 = flag;
    flag = 0;
  }
  ten.bits[0] = TenMask;
  pow.bits[0] = 1;
  powsm = scale_pow(big);
  for (int i = 0; i < powsm; i++) {
    multiply_decimals_with_status(pow, &flag, &pow, ten);
  }
  status = s21_decimal_complex_multiply(small, big, powsm, pow, scale1, scale2,
                                        result);
  return status;
}

int s21_decimal_complex_multiply(s21_decimal value_1, s21_decimal value_2,
                                 int powsm, s21_decimal pow, int scale1,
                                 int scale2, s21_decimal *result) {
  s21_decimal buf_value, mod, buf_res, ten, buffer;
  int status = 0;
  buf_value = value_1;
  s21_tozero(&ten);
  s21_tozero(result);
  s21_tozero(&buf_res);
  s21_tozero(&mod);
  ten.bits[0] = 10;
  int buf_powsm, local_scale1, flag, buf_scale = 0, buf_status = 0;
  for (int k = 0; k < powsm; k++) {
    value_1 = buf_value;
    buf_powsm = powsm - k;
    local_scale1 = scale1;
    flag = 0;
    mod = s21_mod(value_2, pow, &buf_res);
    s21_mod(pow, ten, &pow);
    value_2 = mod;
    if (buf_powsm - scale2 > 0) {
      while (buf_powsm - scale2 != 0 && local_scale1 != 0) {
        local_scale1 = local_scale1 - 1;
        buf_powsm = buf_powsm - 1;
      }
      for (int i = 0; i < buf_powsm - scale2 && flag == 0; i++) {
        multiply_decimals_with_status(buf_res, &flag, &buf_res, ten);
      }
      status = flag;
      buf_scale = 0;
    } else {
      buf_scale = scale2 - buf_powsm;
    }
    while (getLastBit(value_1) + getLastBit(buf_res) + 2 > 96 &&
           local_scale1 >= 0) {
      s21_mod(value_1, ten, &value_1);
      local_scale1 = local_scale1 - 1;
    }
    if (getLastBit(value_1) + getLastBit(buf_res) + 2 > 96) {
      status = 1;
    }
    multiply_decimals_with_status(value_1, &buf_status, &buffer, buf_res);
    if (buf_status != 0) {
      status = 1;
    }
    set_Scale(&buffer, local_scale1 + buf_scale);
    buf_status = s21_add(*result, buffer, result);
    if (buf_status != 0) {
      status = 1;
    }
    if (status != 0) {
      k = powsm;
    }
  }
  value_1 = buf_value;
  if (getLastBit(value_1) + getLastBit(buf_res) + 2 > NUMBER_BITS_DECIMAL) {
    s21_mod(value_1, ten, &value_1);
    scale1 = scale1 - 1;
  }
  multiply_decimals_with_status(value_1, &buf_status, &buffer, mod);
  if (buf_status != 0) {
    status = 1;
  }
  set_Scale(&buffer, scale1 + scale2);
  buf_status = s21_add(*result, buffer, result);
  if (buf_status != 0) {
    status = 1;
  }
  return status;
}

int multiply_decimal_by_ten_with_scale(s21_decimal value_1, s21_decimal value_2,
                                       s21_decimal *result) {
  int powsm = 0;
  int status = 0;
  s21_decimal pow, ten, one;
  s21_tozero(&one);
  one.bits[0] = 1;
  s21_tozero(&ten);
  ten.bits[0] = 10;
  int scale_res = getScale(value_1) + getScale(value_2);
  if (s21_is_equal(one, value_1)) {
    *result = value_2;
    set_Scale(result, scale_res);
  } else if (s21_is_equal(one, value_2)) {
    *result = value_1;
    set_Scale(result, scale_res);
  } else if (s21_decimal_ten_power_check(value_1, &pow, &powsm) &&
             s21_is_less_or_equal(ten, value_1)) {
    status = scale_and_multiply_by_ten(value_2, powsm, result);
  } else if (s21_decimal_ten_power_check(value_2, &pow, &powsm) &&
             s21_is_less_or_equal(ten, value_2)) {
    status = scale_and_multiply_by_ten(value_1, powsm, result);
  } else {
    status = -1;
  }
  return status;
}

int scale_and_multiply_by_ten(s21_decimal value, int powsm,
                              s21_decimal *result) {
  int status = 0;
  int scale = getScale(value);
  set_Scale(&value, 0);
  int scale_res = scale - powsm;
  s21_decimal ten;
  s21_tozero(&ten);
  ten.bits[0] = 10;
  *result = value;
  if (scale_res < 0) {
    while (scale_res != 0 && status == 0) {
      multiply_decimals_with_status(*result, &status, result, ten);
      scale_res++;
    }
  }
  if (status == 0) {
    set_Scale(result, scale_res);
  }
  return status;
}

int s21_decimal_ten_power_check(s21_decimal value, s21_decimal *pow,
                                int *powsm) {
  int status = 0;
  s21_decimal ten, mod;
  s21_tozero(&ten);
  s21_tozero(pow);
  s21_tozero(&mod);
  int scale = getScale(value);
  set_Scale(&value, 0);
  ten.bits[0] = 10;
  pow->bits[0] = 1;
  int flag = 0;
  *powsm = scale_pow(value);
  for (int i = 0; i < *powsm; i++) {
    multiply_decimals_with_status(*pow, &flag, pow, ten);
  }
  mod = s21_mod(value, *pow, &ten);
  s21_tozero(&ten);
  *powsm = *powsm - scale;
  if (s21_is_equal(mod, ten)) {
    status = 1;
  }
  return status;
}