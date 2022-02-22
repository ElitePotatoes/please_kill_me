#include "test_matrix.h"

void test_swapRows_standartMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6}, 2, 3);
    matrix needM = createMatrixFromArray((int[]) {4, 5, 6,
                                                  1, 2, 3}, 2, 3);
    swapRows(readM, 0, 1);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_swapRows() {
    test_swapRows_standartMatrix();
}

void test_swapColumns_standartMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6}, 2, 3);
    matrix needM = createMatrixFromArray((int[]) {2, 1, 3,
                                                  5, 4, 6}, 2, 3);
    swapColumns(readM, 0, 1);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_swapColumns() {
    test_swapColumns_standartMatrix();
}

void test_insertionSortRowsMatrixByRowCriteria_SumArrays() {
    matrix readM = createMatrixFromArray((int[]) {1, 1, 1,
                                                  0, 0, 0,
                                                  2, 2, 2}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {0, 0, 0,
                                                  1, 1, 1,
                                                  2, 2, 2}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(readM, getSum);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_SumArrays();
}

void test_insertionSortColsMatrixByColCriteria_SumArrays() {
    matrix readM = createMatrixFromArray((int[]) {1, 0, 2,
                                                  1, 0, 2,
                                                  1, 0, 2}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {0, 1, 2,
                                                  0, 1, 2,
                                                  0, 1, 2}, 3, 3);
    insertionSortColsMatrixByColCriteria(readM, getSum);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_SumArrays();
}

void test_isSquareMatrix_trueSquareMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);
    assert(isSquareMatrix(readM));

    freeMemMatrix(readM);
}
void test_isSquareMatrix_nonSquareMatrixBySize() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6}, 2, 3);
    assert(!isSquareMatrix(readM));

    freeMemMatrix(readM);
}
void test_isSquareMatrix() {
    test_isSquareMatrix_trueSquareMatrix();
    test_isSquareMatrix_nonSquareMatrixBySize();
}

void test_twoMatricesEqual_equalMatrices() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix needM = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_twoMatricesEqual_nonEqualMatricesBySize() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix needM = createMatrixFromArray((int[]) {1, 2, 3, 4}, 1, 4);
    assert(!twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_twoMatricesEqual_nonEqualMatricesByValue() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);
    matrix needM = createMatrixFromArray((int[]) {4, 2, 3}, 1, 3);
    assert(!twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_twoMatricesEqual() {
    test_twoMatricesEqual_equalMatrices();
    test_twoMatricesEqual_nonEqualMatricesBySize();
    test_twoMatricesEqual_nonEqualMatricesByValue();
}

void test_isEMatrix_trueEMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 0,
                                                  0, 1}, 2, 2);
    assert(isEMatrix(readM));

    freeMemMatrix(readM);
}
void test_isEMatrix_nonEMatrixBySize() {
    matrix readM = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0}, 2, 3);
    assert(!isEMatrix(readM));

    freeMemMatrix(readM);
}
void test_isEMatrix_nonEMatrixByValue() {
    matrix readM = createMatrixFromArray((int[]) {1, 2,
                                                  0, 1}, 2, 2);
    assert(!isEMatrix(readM));

    freeMemMatrix(readM);
}
void test_isEMatrix() {
    test_isEMatrix_trueEMatrix();
    test_isEMatrix_nonEMatrixBySize();
    test_isEMatrix_nonEMatrixByValue();
}

void test_isEMatrix_trueSymmetricMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 5, 6,
                                                  3, 6, 9}, 3, 3);
    assert(isSymmetricMatrix(readM));

    freeMemMatrix(readM);
}
void test_isEMatrix_nonSymmetricMatrixBySize() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 5, 6}, 2, 3);
    assert(!isSymmetricMatrix(readM));

    freeMemMatrix(readM);
}
void test_isEMatrix_nonSymmetricMatrixByValue() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 5, 6,
                                                  3, 10, 9}, 3, 3);
    assert(!isSymmetricMatrix(readM));

    freeMemMatrix(readM);
}
void test_isSymmetricMatrix() {
    test_isEMatrix_trueSymmetricMatrix();
    test_isEMatrix_nonSymmetricMatrixBySize();
    test_isEMatrix_nonSymmetricMatrixByValue();
}

void test_transposeSquareMatrix_standartMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9}, 3, 3);
    transposeSquareMatrix(readM);
    assert(twoMatricesEqual(readM, needM));

    freeMemMatrix(readM);
    freeMemMatrix(needM);
}
void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_standartMatrix();
}

void test_getMinValuePos_standartMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6}, 2, 3);
    position minIndex = getMinValuePos(readM);
    assert(minIndex.rowIndex == 0 && minIndex.colIndex == 0);

    freeMemMatrix(readM);
}
void test_getMinValuePos() {
    test_getMinValuePos_standartMatrix();
}

void test_getMaxValuePos_standartMatrix() {
    matrix readM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6}, 2, 3);
    position maxIndex = getMaxValuePos(readM);
    assert(maxIndex.rowIndex == 1 && maxIndex.colIndex == 2);

    freeMemMatrix(readM);
}
void test_getMaxValuePos() {
    test_getMaxValuePos_standartMatrix();
}

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
                                                   8, 0,
                                                   4, 4}, 7, 2);
    assert(countEqClassesByRowsSum(readM) == 3);

    freeMemMatrix(readM);
}
void test_countEqClassesByRowsSum_standart2() {
    matrix readM = createMatrixFromArray((int []) {0,
                                                   0,
                                                   0,
                                                   1,
                                                   3,
                                                   10,
                                                   10}, 7, 1);
    assert(countEqClassesByRowsSum(readM) == 2);

    freeMemMatrix(readM);
}
void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_standart();
    test_countEqClassesByRowsSum_standart2();
}

void test_getNSpecialElement_standart() {
    matrix readM = createMatrixFromArray((int []) {3, 5, 5, 4,
                                                      2, 3, 6, 7,
                                                     12, 2, 1, 2}, 3, 4);
    assert(getNSpecialElement(readM) == 2);

    freeMemMatrix(readM);
}
void test_getNSpecialElement() {
    test_getNSpecialElement_standart();
}

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

void test_matrix() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_swapRowsWithMaxAndMinValue();
    test_sortRowsByMaxElements();
    test_sortColsByMinElements();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    //test_getMinInArea();
    test_sortByDistance();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
}