#include "resolve.h"

/********************************************************* 9 **********************************************************/

double getDistanceArray(const int a[], const size_t size) {
    double distance = 0;
    for (size_t i = 0; i < size; ++i)
        distance += pow(a[i], 2);

    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *criteriaArray = (float *) malloc(sizeof(float) * m.nRows);
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 0; i < m.nRows - 1; ++i)
        for (size_t j = i + 1; j < m.nRows; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapRows(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(float));
            }

    free(criteriaArray);
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistanceArray);
}

/******************************************************** 10 **********************************************************/

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

int countNUnique(long long a[], const size_t size) {
    qsort(a, size, sizeof(long long), cmp_long_long);

    int counter = 1;
    for (size_t i = 1; i < size; ++i)
        if (a[i] != a[i - 1])
            counter++;

    return counter;
}

int countEqClassesByRowsSum(matrix const m) {
    long long criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = getSum(m.values[i], m.nCols);

    return countNUnique(criteriaArray, m.nRows);
}

/******************************************************** 11 **********************************************************/

int getNSpecialElement(matrix const m) {
    long long criteriaArray[m.nCols];
    int subArray[m.nRows];
    for (size_t j = 0; j < m.nCols; ++j) {
        for (size_t i = 0; i < m.nRows; ++i)
            subArray[i] = m.values[i][j];

        criteriaArray[j] = getSum(subArray, m.nRows);
    }

    int counter = 0;
    for (size_t j = 0; j < m.nCols; ++j)
        for (size_t i = 0; i < m.nRows; ++i)
            if (criteriaArray[j] - m.values[i][j] < criteriaArray[j])
                counter++;

    return counter;
}

/******************************************************** 12 **********************************************************/

position getLeftMin(matrix const m) {

}

void swapPenultimateRow(matrix m, const size_t n) {

}
