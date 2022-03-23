#ifndef MAIN_C_SORT_FUNCTIONS_H
#define MAIN_C_SORT_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "../../algorithms/algorithm.h"
#include "../../algorithms/array/array.h"

//сортировка обменом "пузырьковая".
//bad: n^2
//average: n^2
//best: n
void bubble_sort(int *array, size_t size);

//сортировка перемешиванием "шейкерная".
//bad: n^2
//average: n^2
//best: n
void shaker_sort(int *array, size_t size);

//сортировка расчёской.
//bad: n^2
//average: n^2
//best: n * log(n)
void comb_sort(int *array, size_t size);

//сортировка выбором.
//bad: n^2
//average: n^2
//best: n^2
void selection_sort(int *array, size_t size);

//сортировка вставками.
//bad: n^2
//average: n^2
//best: n
void intersection_sort(int *array, size_t size);

//сортировка Шелла.
//bad: n^2
//average: n * (log(n))^2
//best: n
void shell_sort(int *array, size_t size);

//пирамидальная сортировка.
//bad: n * log n
//average: n * log(n)
//best: n * log n
void heap_sort(int *array, size_t size);

//сортировка подсчётом [бесполезная].
//bad: n + k
//average: n + k
//best: n
void count_sort(int *array, size_t size);

//цифровая сортировка.
//bad: w * n
//average: w * n
//best: w * n
void radix_sort(int *array, size_t size);

//сортировка слиянием.
//bad: n * log(n)
//average: n * log(n)
//best: n * log(n)
void merge_sort(int *array, size_t size);

//быстрая сортировка.
//bad: n^2
//average: n * log(n)
//best: n
void qsort_int(int *array, size_t size);

#endif //MAIN_C_SORT_FUNCTIONS_H