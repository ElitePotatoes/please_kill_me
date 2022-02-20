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

//возвращает значение 'истина', если все элементы массива a размера size расположены по возрастанию, иначе - 'ложь'.
bool isNonDescendingSorted(const int a[], size_t size);

//возвращает значение 'истина', если строки упорядочены по возрастанию элементов, иначе - 'ложь'.
bool hasAllNonDescendingRows(matrix m);

//возвращает количество матриц, строки которых упорядочены по возрастанию элементов, в массиве ms размера nMatrix.
int countNonDescendingRowsMatrices(matrix ms[], size_t nMatrix);

#endif //MAIN_C_RESOLVE_H
