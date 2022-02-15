#ifndef MAIN_C_RESOLVE_H
#define MAIN_C_RESOLVE_H

#include "../matrix.h"

//first
void swapRowsWithMaxAndMinValue(matrix m);

//second
int getMax(const int a[], size_t size);
void sortRowsByMaxElements(matrix m);

//third
int getMin(const int a[], size_t size);
void sortColsByMinElements(matrix m);

//fourth
void impossibleMultiplication();
matrix mulMatrices(matrix m1, matrix m2);
void getSquareOfMatrixIfSymmetric(matrix *m);

bool task_fifth(matrix m);
bool task_sixth(matrix m1, matrix m2);
int task_seventh(matrix m);
int task_eighth(matrix m);

#endif //MAIN_C_RESOLVE_H
