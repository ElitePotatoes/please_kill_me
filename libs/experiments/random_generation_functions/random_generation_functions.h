#ifndef MAIN_C_RANDOM_GENERATION_FUNCTIONS_H
#define MAIN_C_RANDOM_GENERATION_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Генерирует случайную последовательность элементов в массиве array размера size.
void generate_random_array(int *array, size_t size);

//Генерирует возрастающую последовательность элементов в массиве array размера size.
void generate_ordered_array(int *array, size_t size);

//Генерирует убывающую последовательность элементов в массиве array размера size.
void generate_ordered_back_array(int *array, size_t size);

#endif //MAIN_C_RANDOM_GENERATION_FUNCTIONS_H