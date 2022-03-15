#include "random_generation_functions.h"

void generate_random_array(int *array, const size_t size) {
    srand(time(0));
    for (size_t i = 0; i < size; ++i)
        array[i] = rand() % 10000;
}

void generate_ordered_array(int *array, const size_t size) {
    for (size_t i = 0; i < size; ++i)
        array[i] = i;
}

void generate_ordered_back_array(int *array, const size_t size) {
    for (size_t i = 0; i < size; ++i)
        array[i] = size - i;
}