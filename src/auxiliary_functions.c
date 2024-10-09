#include "s21_decimal.h"

s21_decimal *setBit(s21_decimal *value, int pos_bit, int bit) {
  int elem = value->bits[pos_bit / NUMBER_BITS];
  int mask = 1u << (pos_bit % NUMBER_BITS);
  if (bit == 1) {
    value->bits[pos_bit / NUMBER_BITS] = elem | mask;
  } else if (bit == 0) {
    value->bits[pos_bit / NUMBER_BITS] = elem & (~mask);
  }
  return value;
}

int getBit(s21_decimal value, int bit) {
  int elem = value.bits[bit / NUMBER_BITS];
  int maska = 1u << (bit % NUMBER_BITS);
  return !!(elem & maska);
}

int getSign(s21_decimal value) { return getBit(value, NUMBER_BIT_SIGN); }

s21_decimal *setSign(s21_decimal *value, int bit) {
  return setBit(value, NUMBER_BIT_SIGN, bit);
}

int getScale(s21_decimal value) {
  int scale = value.bits[3] & ScaleMask;
  return scale >> 16;
}

s21_decimal *set_Scale(s21_decimal *value, int scale) {
  if (scale >= 0) {
    value->bits[3] = value->bits[3] & (~(ScaleMask));
    value->bits[3] = value->bits[3] | scale << 16;
  }
  return value;
}

int getLastBit(s21_decimal value) {
  int last = -1, bit = 0;
  for (int i = 0; i < NUMBER_BITS_DECIMAL; i++) {
    bit = getBit(value, i);
    if (bit == 1) {
      last = i;
    }
  }
  return last;
}

s21_decimal *shift_left(s21_decimal *value, int shift, int *status) {
  int size = getLastBit(*value) + 1 + shift;
  int lastbit_first_mantis, lastbit_second_mantis;
  if (size > NUMBER_BITS_DECIMAL) {
    *status = 1;
  } else {
    for (int i = 0; i < shift; i++) {
      lastbit_first_mantis = getBit(*value, NUMBER_LAST_BIT_FIRST_MANTISSA);
      lastbit_second_mantis = getBit(*value, NUMBER_LAST_BIT_SECOND_MANTISSA);
      for (int j = 0; j < 3; j++) {
        value->bits[j] = value->bits[j] << 1;
      }
      if (lastbit_first_mantis == 1) {
        value = setBit(value, NUMBER_BITS, 1);
      }
      if (lastbit_second_mantis == 1) {
        value = setBit(value, 2 * NUMBER_BITS, 1);
      }
    }
    *status = 0;
  }
  return value;
}

s21_decimal *shift_right(s21_decimal *value, int shift) {
  int firstbit1, firstbit2;
  for (int i = 0; i < shift; i++) {
    firstbit1 = getBit(*value, NUMBER_BITS);
    firstbit2 = getBit(*value, 64);
    for (int j = 0; j < 3; j++) {
      value->bits[j] = value->bits[j] >> 1;
    }
    if (firstbit1 == 1) {
      value = setBit(value, NUMBER_LAST_BIT_FIRST_MANTISSA, 1);
    }
    if (firstbit2 == 1) {
      value = setBit(value, NUMBER_LAST_BIT_SECOND_MANTISSA, 1);
    }
  }
  return value;
}

void reduction_common_denominator(s21_decimal *value_1, s21_decimal *value_2,
                                  int operation) {
  checking_max_pow(value_1);
  checking_max_pow(value_2);
  int scale1 = getScale(*value_1);
  int scale2 = getScale(*value_2);
  if (scale1 != scale2) {
    set_Scale(value_1, 0);
    set_Scale(value_2, 0);
  }
  if (scale1 > scale2) {
    scale_and_round_decimals(value_2, value_1, scale2, scale1, operation);
  } else if (scale1 < scale2) {
    scale_and_round_decimals(value_1, value_2, scale1, scale2, operation);
  }
}

void scale_and_round_decimals(s21_decimal *value_1, s21_decimal *value_2,
                              int scale1, int scale2, int operation) {
  s21_decimal res, ten;
  int flag_even = -1;
  int status = 0;
  int num = 0;
  s21_tozero(&ten);
  s21_tozero(&res);
  ten.bits[0] = 0b1010;
  res = *value_1;
  for (int i = 0; i < scale2 - scale1 && status == 0; i++) {
    status = s21_mul(res, ten, value_1);
    if (status == 0) {
      res = *value_1;
    } else {
      *value_1 = res;
      num = num - 1;
    }
    num = i;
  }
  if (status != 0) {
    if (operation == 1) {
      if (getBit(*value_1, 0) == 1) {
        flag_even = 1;
      } else {
        flag_even = 0;
      }
    } else if (operation == 2) {
      if (getBit(*value_1, 0) == 1) {
        flag_even = 2;
      } else {
        flag_even = 3;
      }
    }
    bank_round(*value_2, value_2, scale2 - scale1 - num, flag_even);
    scale2 = scale1 + num;
  }
  set_Scale(value_1, scale2);
  set_Scale(value_2, scale2);
}

void s21_tozero(s21_decimal *a) {
  a->bits[0] = a->bits[1] = a->bits[2] = a->bits[3] = 0;
}

void checking_max_pow(s21_decimal *value) {
  int scale = getScale(*value);
  if (scale > MAX_POW) {
    bank_round(*value, value, scale - MAX_POW, -1);
  }
}

void bank_round(s21_decimal value_1, s21_decimal *result, int round,
                int flag_add_even) {
  int flag_even = 0;
  // если нечетный то нуль
  //  flag_add_even нуль если четный
  int scale = getScale(value_1);
  set_Scale(&value_1, 0);
  s21_decimal mod, ten, five;
  s21_tozero(&ten);
  s21_tozero(&five);
  s21_tozero(result);
  *result = value_1;
  ten.bits[0] = TenMask;
  for (int i = 0; i < round; i++) {
    flag_even = 0;
    five.bits[0] = FiveMask;
    mod = s21_mod(*result, ten, result);
    scale = scale - 1;
    if (getBit(*result, 0) == 0) {
      flag_even = 1;
    }
    if (flag_add_even == 0 || flag_add_even == 1 || flag_add_even == -1 ||
        flag_add_even == -2) {
      if (s21_is_less_or_equal(five, mod) == 1 &&
          ((flag_even == 0 && flag_add_even == -1) ||
           (flag_add_even == 1 && i == round - 1 && flag_even == 1) ||
           (flag_add_even == 0 && i == round - 1 && flag_even == 0) ||
           flag_add_even == -2)) {
        five.bits[0] = OneMask;
        s21_add(*result, five, result);
      }
    } else {
      if (!(s21_is_less_or_equal(five, mod) != 1 &&
            ((flag_add_even == 2 && flag_even == 0) ||
             (flag_add_even == 3 && flag_even == 1)))) {
        five.bits[0] = OneMask;
        s21_add(*result, five, result);
      }
    }
  }
  set_Scale(result, scale);
}