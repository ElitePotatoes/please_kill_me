#ifndef MAIN_C_FRACTION_H
#define MAIN_C_FRACTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <memory.h>
#include <assert.h>

#include "C:\Users\elite\CLionProjects\main\libs\algorithms\algorithm.h"

typedef struct fraction {
    int numerator;      //числитель
    int denumerator;    //знаменатель
} fraction;

//ввод структуры fraction.
void inputFraction(fraction *f);

//ввод массива структуры fraction.
void inputFractions(fraction f[], size_t size);

//вывод структуры fraction.
void outputFraction(fraction f);

//вывод массива структуры fraction.
void outputFractions(fraction f[], size_t size);

//возвращает наибольший общий делитель для переменных a и b.
int gcd(int a, int b);

//возвращает наибольшее общее кратное для переменных a и b.
int lcm(int a, int b);

//сокращает дробь f на наибольший общий делитель.
void simpleFraction(fraction *f);

//возвращает дробь, полученная перемножением дробей f1 и f2 и сокращением её на наибольший общий делитель.
fraction mulFractions(fraction f1, fraction f2);

//обменивает значения числителя и знаменятеля дроби f.
void swapElementsOfFraction(fraction *f);

//возвращает дробь, полученная делением дробей f1 и f2 и сокращением её на наибольший общий делитель.
fraction divFraction(fraction f1, fraction f2);

//возвращает дробь, полученная сложением дробей f1 и f2 и сокращением её на наибольший общий делитель.
fraction addFraction(fraction f1, fraction f2);

//возвращает дробь, полученная вычитанием дробей f1 и f2 и сокращением её на наибольший общий делитель.
fraction subFraction(fraction f1, fraction f2);

//возвращает дробь, полученную путём сложения всех дробей массива f размера size.
fraction sumFractions(const fraction f[], size_t size);

#endif //MAIN_C_FRACTION_H
