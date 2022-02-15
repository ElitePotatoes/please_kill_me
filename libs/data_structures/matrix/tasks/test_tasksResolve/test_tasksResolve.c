#include "test_tasksResolve.h"

//first
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

//second
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

//third
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

void test_task_fourth() {}
void test_task_fifth() {}
void test_task_sixth() {}
void test_task_seventh() {}
void test_task_eighth() {}

void test_matrixTasks() {
    test_swapRowsWithMaxAndMinValue();
    //test_sortRowsByMaxElements();
    //test_sortColsByMinElements();
    test_task_fourth();
    test_task_fifth();
    test_task_sixth();
    test_task_seventh();
    test_task_eighth();
}