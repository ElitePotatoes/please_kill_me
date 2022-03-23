#ifndef MAIN_C_EXPERIMENTS_H
#define MAIN_C_EXPERIMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../../algorithms/array/array.h"
#include "../sort_functions/sort_functions.h"
#include "../random_generation_functions/random_generation_functions.h"

//макрофункция, измеряющая количество времени работы функции code и записывающая результат в параметр time.
#define TIME_TEST(functions, time) {                \
    clock_t start_time = clock();                   \
                                                    \
    functions                                       \
                                                    \
    clock_t end_time = clock();                     \
    clock_t sort_time = end_time - start_time;      \
    time = (double) sort_time /  CLOCKS_PER_SEC;    \
}

//макрофункция, определяющая размер массива а.
#define ARRAY_SIZE(array) sizeof(array) / sizeof(array[0])

//функция сортировки.
typedef struct sort_function {
    void (*sort) (int *a, size_t size); //указатель на функцию сортировки.
    char name[64];                      //имя сортировки, используемое при выводе.
} sort_function;

//функция "рандомной" генерации.
typedef struct generation_function {
    void (*generate) (int *a, size_t size); //указатель на функцию генерацию последовательности.
    char name[64];                          //имя сортировки, используемое при выводе.
} generation_function;

void check_time(void (*sort_func)(int *, size_t),
                void (*generate_func)(int *, size_t),
                size_t size, char *experiment_name);

void time_experiment();

#endif //MAIN_C_EXPERIMENTS_H