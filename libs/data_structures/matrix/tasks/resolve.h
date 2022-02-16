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

//возводит в квадрат матрицу m, если она симметрична.
void getSquareOfMatrixIfSymmetric(matrix *m);

//возвращает сумму элементов массива а размера size.
long long getSum(const int a[], size_t size);

//возвращает значение 'истина', если в массиве а размера size нет одинаковых элементов, иначе - 'ложь'.
bool isUnique(const int a[], size_t size);

//транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//возвращает значение 'истина', если матрицы m1 и m2 взаимнообратные.
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//возвращает максимальное значение элемента в диагонали, начинающиеся с индексов indexRow и indexCol, матрицы m.
int getMaxDiagonalElement(matrix m, size_t indexRow, size_t indexCol);

//возвращает сумму максимальных элементов всех псевдодиагоналей данной матрицы m.
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//возвращает минимальное значенита элемент матрицы m в области, образованной пирамидой выше максимального элемента.
int getMinInArea(matrix m);

#endif //MAIN_C_RESOLVE_H
