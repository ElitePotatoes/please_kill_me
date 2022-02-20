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