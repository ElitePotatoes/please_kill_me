#include "test_tasksResolve.h"

void test_swapRowsWithMaxAndMinValue_standart() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {7, 8, 9,
                                                     4, 5, 6,
                                                     1, 2, 3}, 3, 3);

    swapRowsWithMaxAndMinValue(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_swapRowsWithMaxAndMinValue_twoElementsInSameRow() {
    matrix readM = createMatrixFromArray((int[]) {5, 10, 15,
                                                     -1, 7, 30,
                                                     2, 3, 4}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {5, 10, 15,
                                                     -1, 7, 30,
                                                     2, 3, 4}, 3, 3);

    swapRowsWithMaxAndMinValue(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_swapRowsWithMaxAndMinValue() {
    test_swapRowsWithMaxAndMinValue_standart();
    test_swapRowsWithMaxAndMinValue_twoElementsInSameRow();
}

void test_sortRowsByMaxElements_standart() {
    matrix readM = createMatrixFromArray((int[]) {7, 1, 2,
                                                     1, 8, 1,
                                                     3, 2, 3}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {3, 2, 3,
                                                     7, 1, 2,
                                                     1, 8, 1}, 3, 3);
    sortRowsByMaxElements(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_sortRowsByMaxElements() {
    test_sortRowsByMaxElements_standart();
}

void test_sortColsByMinElements_standart() {
    matrix readM = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                     2, 5, 1, 8, 2, 7,
                                                     6, 1, 4, 4, 8, 3}, 3, 6);
    matrix needM = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                     5, 1, 2, 2, 7, 8,
                                                     1, 4, 6, 8, 3, 4}, 3, 6);
    sortColsByMinElements(readM);
    outputMatrix(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_sortColsByMinElements() {
    test_sortColsByMinElements_standart();
}

void test_getSquareOfMatrixIfSymmetric_standart() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                     2, 1, 4,
                                                     3, 4, 1}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {14, 16, 14,
                                                     16, 21, 14,
                                                     14, 14, 26}, 3, 3);
    getSquareOfMatrixIfSymmetric(&readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_standart();
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1, 2,
                                                  1, 8, 1,
                                                  3, 1, 3},3, 3);
    matrix m2 = createMatrixFromArray((int[]) {7, 1, 2,
                                                  1, 8, 1,
                                                  3, 1, 3},3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1, 1,
                                                  1, 8, 1,
                                                  3, 1, 3},3, 3);
    matrix m2 = createMatrixFromArray((int[]) {7, 1, 3,
                                                  1, 8, 1,
                                                  1, 1, 3},3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(twoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}
void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum();
}

void test_isMutuallyInverseMatrices_right() {
    matrix readM1 = createMatrixFromArray((int[]) {2, 5, 7,
                                                      6, 3, 4,
                                                      5, -2, -3}, 3, 3);
    matrix readM2 = createMatrixFromArray((int[]) {1, -1, 1,
                                                    -38, 41, -34,
                                                     27, -29, 24}, 3, 3);
    assert(isMutuallyInverseMatrices(readM1, readM2) == true);

    freeMemMatrix(readM1);
    freeMemMatrix(readM2);
}
void test_isMutuallyInverseMatrices_false() {
    matrix readM1 = createMatrixFromArray((int[]) {2, 5, 7,
                                                      6, 3, 4,
                                                      5, -2, -3}, 3, 3);
    matrix readM2 = createMatrixFromArray((int[]) {2, -1, 1,
                                                    -38, 41, -34,
                                                     27, -29, 24}, 3, 3);
    assert(isMutuallyInverseMatrices(readM1, readM2) == false);

    freeMemMatrix(readM2);
    freeMemMatrix(readM1);
}
void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_right();
    test_isMutuallyInverseMatrices_false();
}

void test_findSumOfMaxesOfPseudoDiagonal_standart() {
    matrix readM = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                                     1, 3, 6, 3,
                                                     3, 2, 1, 2}, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(readM) == 20);

    freeMemMatrix(readM);
}
void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_standart();
}

void test_getMinInArea_standart1() {
    matrix readM = createMatrixFromArray((int []) {10, 7, 5, 6,
                                                       3, 11, 8, 9,
                                                       4, 1, 12, 2}, 3, 4);
    assert(getMinInArea(readM) == 5);

    freeMemMatrix(readM);
}
void test_getMinInArea_standart2() {
    matrix readM = createMatrixFromArray((int []) {6, 8, 9, 2,
                                                      7, 12, 3, 4,
                                                      10, 11, 5, 1}, 3, 4);
    assert(getMinInArea(readM) == 6);

    freeMemMatrix(readM);
}
void test_getMinInArea_standart3() {
    matrix readM = createMatrixFromArray((int []) {10, 7, 5, 0,
                                                   3, 11, 8, 9,
                                                   4, 1, 12, 2}, 3, 4);
    assert(getMinInArea(readM) == 0);

    freeMemMatrix(readM);
}
void test_getMinInArea_minIndex00() {
    matrix readM = createMatrixFromArray((int []) {30, 8, 9, 2,
                                                      7, 12, 3, 4,
                                                     10, 11, 5, 1}, 3, 4);
    assert(getMinInArea(readM) == 30);

    freeMemMatrix(readM);
}
void test_getMinInArea() {
    test_getMinInArea_standart1();
    test_getMinInArea_standart2();
    test_getMinInArea_standart3();
    test_getMinInArea_minIndex00();
}

void test_matrixTasks() {
    test_swapRowsWithMaxAndMinValue();
    test_sortRowsByMaxElements();
    test_sortColsByMinElements();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
}