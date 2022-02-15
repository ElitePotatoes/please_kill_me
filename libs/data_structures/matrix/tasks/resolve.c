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

//fourth
void impossibleMultiplication() {
    fprintf(stderr, "multiplication isn't possible");
    exit(1);
}
matrix mulMatrices(matrix const m1, matrix const m2) {
    if (m1.nCols != m2.nRows)
        impossibleMultiplication();

    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m2.nCols; ++j)
            for (size_t k = 0; k < m1.nCols; ++k)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];

    return m3;
}
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

bool task_fifth(matrix m) {}
bool task_sixth(matrix m1, matrix m2) {}
int task_seventh(matrix m) {}
int task_eighth(matrix m) {}