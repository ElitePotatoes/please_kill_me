#ifndef MAIN_C_MATRIX_H
#define MAIN_C_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <assert.h>

#include "C:/Users/elite/CLionProjects/main/libs/algorithms/algorithm.h"
#include "C:/Users/elite/CLionProjects/main/libs/algorithms/array/array.h"

typedef struct matrix {
    int **values;   //элементы матрицы
    int nRows;      //количество рядов
    int nCols;      //количество столбцов
} matrix;

typedef struct position {
    int rowIndex;   //индекс элемента в ряду
    int colIndex;   //индекс элемента в столбце
} position;

//возвращает матрицу размером nRows на nCols.
matrix getMemMatrix(int nRows, int nCols);

//возвращает указатель на нулевую матрицу, создавая массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

//освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix m);

//освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

//ввод матрицы m.
void inputMatrix(matrix m);

//ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m.
void outputMatrix(matrix m);

//вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

//обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

//обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swapColumns(matrix m, int j1, int j2);

//выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria применяемой для строк.
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

//выполняет сортировку вставками столбцов матрицы m по неубыванию значения функции criteria применяемой для столбцов.
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

//возвращает значение ’истина’, если матрица m является квадратной, иначе - 'ложь'.
bool isSquareMatrix(matrix m);

//возвращает значение ’истина’, если матрицы m1 и m2 равны, иначе - 'ложь'.
bool twoMatricesEqual(matrix m1, matrix m2);

//возвращает значение ’истина’, если матрица m является единичной, иначе - 'ложь'.
bool isEMatrix(matrix m);

//возвращает значение ’истина’, если матрица m является симметричной, иначе - 'ложь'.
bool isSymmetricMatrix(matrix m);

//транспонирует квадратную матрицу m.
void transposeSquareMatrix(matrix m);

//возвращает позицию первого вхождения минимального элемента матрицы m.
position getMinValuePos(matrix m);

//возвращает позицию первого вхождения максимального элемента матрицы m.
position getMaxValuePos(matrix m);

//возвращает матрицу, размера nRows на nCols, построенного из элементов массива a, размещенную в динамической памяти.
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

//возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных в динамической памяти,
//построенных из элементов массива a.
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

//обменивает ряд матрицы m, имеющие минимальное и максимальное значения элементов.
void swapRowsWithMaxAndMinValue(matrix m);

//сортирует ряды матрицы m по неубыванию наибольших элементов строк.
void sortRowsByMaxElements(matrix m);

//сортирует столбцы матрицы m по неубыванию минимальных элементов столбцов.
void sortColsByMinElements(matrix m);

//возвращает матрицу, полученную перемножением матриц m1 и m2.
matrix mulMatrices(matrix m1, matrix m2);

//возводит в квадрат матрицу m, если она симметрична.
void getSquareOfMatrixIfSymmetric(matrix *m);

//транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

//возвращает значение 'истина', если матрицы m1 и m2 взаимнообратные, иначе - 'ложь'.
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//возвращает максимальное значение элемента в диагонали, начинающиеся с индексов indexRow и indexCol, матрицы m.
int getMaxDiagonalElement(matrix m, size_t indexRow, size_t indexCol);

//возвращает сумму максимальных элементов всех псевдодиагоналей данной матрицы m.
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//возвращает минимальное значенита элемент матрицы m в области, образованной пирамидой выше максимального элемента.
int getMinInArea(matrix m);

#endif //MAIN_C_MATRIX_H