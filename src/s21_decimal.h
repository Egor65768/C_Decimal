#ifndef _SRC_S21_DECIMAL_H
#define _SRC_S21_DECIMAL_H
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_MAX_UINT 4294967295
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define ScaleMask 0b11111111 << 16
#define TenMask 0b1010
#define FiveMask 0b101
#define OneMask 0b1

#define NUMBER_LAST_BIT_FIRST_MANTISSA 31
#define NUMBER_LAST_BIT_SECOND_MANTISSA 63
#define NUMBER_BITS 32
#define NUMBER_BITS_DECIMAL 96
#define NUMBER_BIT_SIGN 127
#define MAX_POW 28

#define PLUS 0
#define MINUS 1

typedef struct {
  unsigned int bits[4];
} s21_decimal;

/*
ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
*/

// узнать бит
int getBit(s21_decimal value, int bit);

// поменять бит
s21_decimal *setBit(s21_decimal *value, int pos_bit, int bit);

// проверяет знак 0 - это плюс 1 - это минус
int getSign(s21_decimal value);

// замена знака
s21_decimal *setSign(s21_decimal *value, int bit);

// возвращает номер последнего единичного бита
int getLastBit(s21_decimal value);

// перемещает биты влево на shift (изменяет status на 1 если переполнен децимал)
s21_decimal *shift_left(s21_decimal *value, int shift, int *status);

// перемещает биты в право
s21_decimal *shift_right(s21_decimal *value, int shift);

// возвращает знак произведения 0 - это плюс 1 - это минус
int signmul(s21_decimal *value_1, s21_decimal *value_2);

// возвращает масштаб
int getScale(s21_decimal value);

// меняет масштаб(надо переправерить)
s21_decimal *set_Scale(s21_decimal *value, int scale);

/*
привод к общему знаменателю и округляет с учетом того какой
результат должен получится после банковского округления
*/
void reduction_common_denominator(
    s21_decimal *value_1, s21_decimal *value_2,
    int operation);  // операция 1 сложение операция 2 вычитание

void scale_and_round_decimals(s21_decimal *value_1, s21_decimal *value_2,
                              int scale1, int scale2, int operation);
// обнуляет децимал
void s21_tozero(s21_decimal *a);

// банковское округление
void bank_round(s21_decimal value_1, s21_decimal *result, int round,
                int flag_add_even);

// проверка что степень числа не превышает 28, если превышает то изменяю степень
void checking_max_pow(s21_decimal *value);

/*
СЛОЖЕНИЕ
*/
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void add_decimal_values(s21_decimal value_1, s21_decimal value_2, int *buf,
                        s21_decimal *result);

void add_decimals_with_float_handling(s21_decimal *value_1,
                                      s21_decimal *value_2,
                                      s21_decimal *result);

/*
ДЕЛЕНИЕ
*/
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void scale_up_for_division(s21_decimal *mod, s21_decimal value_2,
                           int *res_scale, int *flag, s21_decimal *result,
                           s21_decimal ten, s21_decimal *buf_res);

void scale_and_finalize_division(int res_scale, int flag, s21_decimal buf_res,
                                 int sign, int *status, s21_decimal *result);

int round_division_result(s21_decimal mod, s21_decimal res,
                          s21_decimal value_2);

/*
РАЗНОСТЬ
*/
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void perform_decimal_subtraction(s21_decimal val1, s21_decimal val2,
                                 s21_decimal *result);

/*
УМНОЖЕНИЕ
*/
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void multiply_decimals_with_status(s21_decimal value_1, int *status,
                                   s21_decimal *result, s21_decimal value_2);

int scale_pow(s21_decimal value);

int multiply_large_decimals(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result);

int s21_decimal_complex_multiply(s21_decimal value_1, s21_decimal value_2,
                                 int powsm, s21_decimal pow, int scale1,
                                 int scale2, s21_decimal *result);

// Возвращает единицу если число кратно десяти
int s21_decimal_ten_power_check(s21_decimal value, s21_decimal *pow,
                                int *powsm);

int multiply_decimal_by_ten_with_scale(s21_decimal value_1, s21_decimal value_2,
                                       s21_decimal *result);

int scale_and_multiply_by_ten(s21_decimal value, int powsm,
                              s21_decimal *result);

/*
ДЕЛЕНИЕ С ОСТАТКОМ, ВОЗВРАЩАЕТ ОСТАТОК process_small_numbers
*/

s21_decimal s21_mod(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);

void process_small_numbers(s21_decimal *buff, s21_decimal value_1,
                           s21_decimal *buff_one, int *status,
                           s21_decimal value_2);

/*
ОПЕРАТОРЫ СРАВНЕНИЯ
*/
// меньше
int s21_is_less(s21_decimal value_1, s21_decimal value_2);

// меньше или равно
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

// больше
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);

// больше или или равно
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

// равно
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);

// не равно
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

/*
ПРЕОБРАЗОВАТЕЛЛИ
*/
int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*
ДРУГИЕ ФУНКЦИИ
*/
// Округляет указанное Decimal число до ближайшего целого числа в сторону
// отрицательной бесконечности.
int s21_floor(s21_decimal value, s21_decimal *res);

// Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal value, s21_decimal *res);

// Возвращает целые цифры указанного Decimal числа
int s21_truncate(s21_decimal value, s21_decimal *res);

// Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal *res);

#endif