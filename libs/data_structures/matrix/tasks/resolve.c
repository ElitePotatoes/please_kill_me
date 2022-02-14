#include "resolve.h"

void swapRowsWithMaxAndMinValue(matrix m) {
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    if (minIndex.rowIndex != maxIndex.rowIndex)
        swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

void task_second(matrix m) {}
void task_third(matrix m) {}
void task_fourth(matrix m) {}
bool task_fifth(matrix m) {}
bool task_sixth(matrix m1, matrix m2) {}
int task_seventh(matrix m) {}
int task_eighth(matrix m) {}
