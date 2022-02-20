#ifndef MAIN_C_RESOLVE_H
#define MAIN_C_RESOLVE_H

#include "../matrix.h"

//возвращает расстаояние до начала координат массива a размера size.
double getDistanceArray(const int a[], size_t size);

//сортирует строчки матрицы m по расстоянию от начала координат.
void sortByDistance(matrix m);

//компанатор переменных типа long long для qsort.
int cmp_long_long(const void *pa, const void *pb);

//возвращает количество классов эквивалентных индексов массива a размера size.
int countNUnique(long long a[], size_t size);

//возвращает количество классов эквивалентных строк матрицы m;
int countEqClassesByRowsSum(matrix m);

//возвращает количество элементов матрицы m, если они больше суммы остальных элементов своего столбца.
int getNSpecialElement(matrix m);

//заменяет предпоследнюю строку матрицы м первым из столбцов, в котором находится минимальный элемент матрицы.
void swapPenultimateRow(matrix m);

#endif //MAIN_C_RESOLVE_H
