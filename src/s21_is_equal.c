#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  if (getSign(value_1) == getSign(value_2)) {
    reduction_common_denominator(&value_1, &value_2, -1);

    for (int i = 4 * NUMBER_BITS - 1; i >= 0; i--) {
      if (getBit(value_1, i) != getBit(value_2, i)) {
        result = 0;
        break;
      }
      result = 1;
    }
  }
  return result;
}
