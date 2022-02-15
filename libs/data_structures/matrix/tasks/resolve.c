#include "resolve.h"

//first
void swapRowsWithMaxAndMinValue(matrix m) {
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    if (minIndex.rowIndex != maxIndex.rowIndex)
        swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

//second
int getMax(const int a[], const size_t size) {
    int maxValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] > maxValue)
            maxValue = a[i];

    return maxValue;
}
void sortRowsByMaxElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//third
int getMin(const int a[], const size_t size) {
    int minValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] < minValue)
            minValue = a[i];

    return minValue;
}
void sortColsByMinElements(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void task_fourth(matrix m) {}
bool task_fifth(matrix m) {}
bool task_sixth(matrix m1, matrix m2) {}
int task_seventh(matrix m) {}
int task_eighth(matrix m) {}