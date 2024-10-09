#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  if (getSign(value_1) != getSign(value_2)) {
    if (getSign(value_1) == MINUS && getSign(value_2) == PLUS) {
      result = 1;
    } else if (getSign(value_1) == PLUS && getSign(value_2) == MINUS) {
      result = 0;
    }
  } else {
    reduction_common_denominator(&value_1, &value_2, -1);

    for (int i = 4 * NUMBER_BITS - 1; i >= 0 && result == 0; i--) {
      if (getSign(value_1) == PLUS && getBit(value_1, i) < getBit(value_2, i)) {
        result = 1;
      } else if (getSign(value_1) == PLUS &&
                 getBit(value_1, i) > getBit(value_2, i)) {
        result = 0;
        break;
      } else if (getSign(value_1) == MINUS &&
                 getBit(value_1, i) > getBit(value_2, i)) {
        result = 1;
      } else if (getSign(value_1) == MINUS &&
                 getBit(value_1, i) < getBit(value_2, i)) {
        result = 0;
        break;
      }
    }
  }

  return result;
}
