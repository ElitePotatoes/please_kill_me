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
}