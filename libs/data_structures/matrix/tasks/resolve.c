#include "resolve.h"

/********************************************************* 1 **********************************************************/

void swapRowsWithMaxAndMinValue(matrix m) {
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    if (minIndex.rowIndex != maxIndex.rowIndex)
        swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

/********************************************************* 2 **********************************************************/

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

/********************************************************* 3 **********************************************************/

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

/********************************************************* 4 **********************************************************/

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

/********************************************************* 5 **********************************************************/

long long getSum(const long long a[], const size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += a[i];

    return sum;
}

bool isUnique(const int a[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i; j < size; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = getSum(m.values[i], m.nCols);

    if (isUnique(criteriaArray, m.nRows))
        transposeSquareMatrix(m);
}

/********************************************************* 6 **********************************************************/

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {}

/********************************************************* 7 **********************************************************/

int max(int a, int b) {}
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {}

/********************************************************* 8 **********************************************************/

int getMinInArea(matrix m) {}