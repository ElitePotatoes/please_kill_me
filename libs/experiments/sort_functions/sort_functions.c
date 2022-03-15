#include "sort_functions.h"

void bubble_sort(int *array, const size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = size - 1; j > i; --j)
            if (array[j - 1] > array[j])
                swapVoid(&array[j - 1], &array[j], sizeof(int));
}


void shaker_sort(int *array, const size_t size) {
    size_t left = 0;
    size_t right = size - 1;
    bool change = true;
    while (left < right && change) {
        change = false;
        for (size_t i = 0; i < right; ++i) {
            if (array[i] > array[i + 1]) {
                swapVoid(&array[i], &array[i + 1], sizeof(int));
                change = true;
            }
        }

        right--;
        for (size_t i = right; i > left; --i) {
            if (array[i] < array[i - 1]) {
                swapVoid(&array[i], &array[i - 1], sizeof(int));
                change = true;
            }
        }

        left++;
    }
}


void comb_sort(int *array, const size_t size) {
    size_t step = size;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;

        swapped = false;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (array[i] > array[j]) {
                swapVoid(&array[i], &array[j], sizeof(int));
                swapped = true;
            }
    }
}


void selection_sort(int *array, const size_t size) {
    size_t min_index;
    for (size_t i = 0; i < size - 1; ++i) {
        min_index = i;
        for (size_t j = i + 1; j < size; ++j)
            min_index = array[j] >= array[min_index] ? j : min_index;

        if (array[i] != array[min_index])
            swapVoid(&array[i], &array[min_index], sizeof(int));
    }
}


void intersection_sort(int *array, const size_t size) {
    for (size_t i = 1; i < size; ++i)
        for (size_t j = i; j > 0 && array[j] > array[j - 1]; --j)
            swapVoid(&array[j], &array[j - 1], sizeof(int));
}


void shell_sort(int *array, const size_t size) {
    for (size_t step = size / 2; step > 0; step /= 2) {
        int temp;
        for (size_t i = step; i < size; i++) {
            temp = array[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (temp < array[j - step])
                    array[j] = array[j - step];
                else
                    break;
            }

            array[j] = temp;
        }
    }
}


void insert_heap(int *array, size_t *size, const int value) {
    array[*(size)++] = value;
    size_t child_index = *size - 1;
    size_t parent_index = (child_index - 1) / 2;
    while (array[child_index] < array[parent_index] && child_index != 0) {
        swapVoid(&array[child_index], &array[parent_index], sizeof(int));
        child_index = parent_index;
        parent_index = (child_index - 1) / 2;
    }
}

bool has_left_child(const size_t parentIndex, const size_t size) {
    return 2 * parentIndex + 1 < size;
}

bool has_right_child(const size_t parentIndex, const size_t size) {
    return 2 * parentIndex + 2 < size;
}

size_t get_left_child_index(const size_t parentIndex) {
    return 2 * parentIndex + 1;
}

size_t get_min_child_index(const int *array, const size_t size, const size_t parent_index) {
    size_t min_child_index = get_left_child_index(parent_index);
    size_t right_child_index = min_child_index + 1;
    if (has_right_child(parent_index, size))
        if (array[right_child_index] < array[min_child_index])
            min_child_index = right_child_index;

    return min_child_index;
}

void remove_min_heap(int *array, size_t *size) {
    *size -= 1;
    swapVoid(&array[0], &array[*size], sizeof(int));
    size_t parent_index = 0;
    while (has_left_child(parent_index, *size)) {
        size_t min_child_index = get_min_child_index(array, *size, parent_index);
        if (array[min_child_index] < array[parent_index]) {
            swapVoid(&array[min_child_index], &array[parent_index], sizeof(int));
            parent_index = min_child_index;
        }
        else
            break;
    }
}

void heap_sort(int *array, const size_t size) {
    size_t heap_size = 0;
    while (heap_size != size)
        insert_heap(array, &heap_size, array[heap_size]);
    while (heap_size)
        remove_min_heap(array, &heap_size);
}


void count_sort(int *array, const size_t size) {
    int min, max;
    get_min_max(array, size, &min, &max);

    int k = max - min + 1;
    int *buffer = (int *) malloc(sizeof(int) * k);
    for (size_t i = 0; i < size; ++i)
        buffer[array[i] - min]++;

    size_t ind = 0;
    for (size_t i = 0; i < k; ++i) {
        int x = buffer[i];
        for (size_t j = 0; j < x; ++j)
            array[ind++] = min + i;
    }

    free(buffer);
}


/*void bucket_sort(int *array, const size_t size) {
    int max = array[0];
    int min = array[0];
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > max)
            max = array[i];
        else if (array[i] < min)
            min = array[i];
    }

    int range = max - min;
    for (size_t i = 0; i < size; ++i) {

    }
}*/


/*int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort_(int *array, int *size) {
    int byte = 8;
    int k = (32 + byte - 1) / byte;
    int M = 1 << byte;
    int sz = size - array;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = array; j < size; j++)
            c[digit(*j, i, byte, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = size - 1; j >= array; j--)
            b[--c[digit(*j, i, byte, M)]] = *j;

        int cur = 0;
        for (int *j = array; j < size; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void radix_sort(int *array, const size_t size) {
    radixSort_(array, array + size);
}*/


void merge(const int *arrayA, const size_t sizeA, const int *arrayB, const size_t sizeB, int *buffer) {
    size_t i = 0;
    size_t j = 0;
    while (i < sizeA || j < sizeB) {
        if (j == sizeB || i < sizeA && arrayA[i] < arrayB[j]) {
            buffer[i + j] = arrayA[i];
            i++;
        }
        else {
            buffer[i + j] = arrayB[j];
            j++;
        }
    }
}

void merge_sort_(int *array, const size_t left, const size_t right, const int *buffer) {
    size_t n = right - left;
    if (n <= 1)
        return;

    size_t middle = (left + right) / 2;
    merge_sort_(array, left, middle, buffer);
    merge_sort_(array, middle, right, buffer);

    merge(array + left, middle - left, array + middle, right - middle, buffer);
    memcpy(array + left, buffer, sizeof(int) * n);
}

void merge_sort(int *array, const size_t size) {
    int *buffer = (int *) malloc(sizeof(int) * size);
    merge_sort_(array, 0, size, buffer);

    free(buffer);
}


int compare_int(const void *a, const void *b) {
    int arg1 = *(int *) a;
    int arg2 = *(int *) b;
    if (arg1 < arg2) {
        return -1;
    }
    if (arg1 > arg2) {
        return 1;
    }

    return 0;
}

void qsort_int(int *array, const size_t size) {
    qsort(array, size, sizeof(int), compare_int);
}