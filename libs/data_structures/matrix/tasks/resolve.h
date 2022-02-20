#ifndef MAIN_C_RESOLVE_H
#define MAIN_C_RESOLVE_H

#include "../matrix.h"

//возвращает расстаояние до начала координат массива a размера size.
double getDistanceArray(const int a[], size_t size);

//сортирует строчки матрицы m по расстоянию от начала координат.
void sortByDistance(matrix m);

#endif //MAIN_C_RESOLVE_H
