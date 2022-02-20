#include "test_tasksResolve.h"

void test_sortByDistance_standart() {
    matrix readM = createMatrixFromArray((int []) {4, 4, 4,
                                                      0, 0, 0,
                                                      1, 2, 3}, 3, 3);
    matrix needM = createMatrixFromArray((int []) {0, 0, 0,
                                                   1, 2, 3,
                                                   4, 4, 4}, 3, 3);
    sortByDistance(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
}
void test_sortByDistance() {
    test_sortByDistance_standart();
}

void test_countEqClassesByRowsSum_standart() {
    matrix readM = createMatrixFromArray((int []) {7, 1,
                                                   2, 7,
                                                   5, 4,
                                                   4, 3,
                                                   1, 6,
                                                   8, 0}, 6, 2);
    assert(countEqClassesByRowsSum(readM) == 3);

    freeMemMatrix(readM);
}
void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_standart();
}

void test_getNSpecialElement_standart() {
    matrix readM = createMatrixFromArray((int []) {3, 5, 5, 4,
                                                   2, 3, 6, 7,
                                                   12, 2, 1, 2}, 3, 4);
    assert(getNSpecialElement(readM) == 2);

    freeMemMatrix(readM);
}
void test_getNSpecialElement() {}

void test_swapPenultimateRow_standart() {
    matrix readM = createMatrixFromArray((int []) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 1}, 3, 3);
    matrix needM = createMatrixFromArray((int []) {1, 2, 3,
                                                   1, 4, 7,
                                                   7, 8, 1}, 3, 3);
    swapPenultimateRow(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_swapPenultimateRow() {
    test_swapPenultimateRow_standart();
}

void test_countNonDescendingRowsMatrices_standart() {
    matrix *readMs = createArrayOfMatrixFromArray((int[]) {7, 1,
                                                                 1, 1,

                                                                 1, 6,
                                                                 2, 2,

                                                                 5, 4,
                                                                 2, 3,

                                                                 1, 3,
                                                                 7, 9}, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(readMs, 4) == 2);

    freeMemMatrices(readMs, 4);
}
void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_standart();
}

void test_matrixTasks() {
    test_sortByDistance();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
}