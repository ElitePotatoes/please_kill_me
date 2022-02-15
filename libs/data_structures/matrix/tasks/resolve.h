#ifndef MAIN_C_RESOLVE_H
#define MAIN_C_RESOLVE_H

#include "../matrix.h"

//обменивает ряд матрицы m, имеющие минимальное и максимальное значения элементов.
void swapRowsWithMaxAndMinValue(matrix m);

//возвращает максимальное значение в массиве а размера size.
int getMax(const int a[], size_t size);

//сортирует ряды матрицы m по неубыванию наибольших элементов строк.
void sortRowsByMaxElements(matrix m);

//возвращает минимальное значение в массиве а размера size.
int getMin(const int a[], size_t size);

//сортирует столбцы матрицы m по неубыванию минимальных элементов столбцов.
void sortColsByMinElements(matrix m);

//возвращает матрицу, полученную перемножением матриц m1 и m2.
matrix mulMatrices(matrix m1, matrix m2);

//возводит в квадрат все элементы матрицы m, если она симметрична.
void getSquareOfMatrixIfSymmetric(matrix *m);

//возвращает сумму элементов массива а размера size.
long long getSum(const long long a[], size_t size);

//возвращает значение 'истина', если в массиве а размера size нет одинаковых элементов, иначе - 'ложь'.
bool isUnique(const int a[], size_t size);

//транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

#endif //MAIN_C_RESOLVE_H
