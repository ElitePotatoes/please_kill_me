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

void test_task_second() {

}
void test_task_third() {

}
void test_task_fourth() {

}
void test_task_fifth() {

}
void test_task_sixth() {

}
void test_task_seventh() {

}
void test_task_eighth() {

}

void test_matrixTasks() {
    test_swapRowsWithMaxAndMinValue();
    test_task_second();
    test_task_third();
    test_task_fourth();
    test_task_fifth();
    test_task_sixth();
    test_task_seventh();
    test_task_eighth();
}