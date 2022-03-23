#include "sort_functions.h"

void bubble_sort(int *array, size_t n) {
    long long countComparison = 0;
    for (size_t i = 0; i < n - 1; ++i) {
        countComparison++;
        for (size_t j = n - 1; j > i; --j) {
            countComparison++;
            if (array[j - 1] > array[j])
                swap(&array[j - 1], &array[j]);
        }

    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void shaker_sort(int *array, const size_t size) {
    size_t left = 0;
    size_t right = size - 1;
    bool swapped = true;
    long long countComparison = 0;
    while (right - left > 0 && swapped) {
        swapped = false;
        for (size_t i = left; i < right; ++i) {
            countComparison++;
            if (array[i] > array[i + 1]) {
                swapVoid(&array[i], &array[i + 1], sizeof(int));
                swapped = true;
            }
        }

        right--;
        for (size_t i = right; i > left; --i) {
            countComparison++;
            if (array[i] < array[i - 1]) {
                swapVoid(&array[i], &array[i - 1], sizeof(int));
                swapped = true;
            }
        }

        left++;
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void comb_sort(int *array, const size_t size) {
    size_t step = size;
    bool swapped = true;
    long long countComparison = 0;
    while (step > 1 || swapped) {
        if (step > 1) {
            countComparison++;
            step /= 1.24733;
        }

        swapped = false;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j) {
            countComparison++;
            if (array[i] > array[j]) {
                countComparison++;
                swapVoid(&array[i], &array[j], sizeof(int));
                swapped = true;
            }
        }
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void selection_sort(int *array, const size_t size) {
    size_t min_index;
    long long countComparison = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        min_index = i;
        for (size_t j = i + 1; j < size; ++j) {
            countComparison++;
            min_index = array[j] < array[min_index] ? j : min_index;
        }

        if (i != min_index)
            swapVoid(&array[i], &array[min_index], sizeof(int));
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void intersection_sort(int *array, const size_t size) {
    long long countComparison = 0;
    for (size_t i = 1; i < size; i++) {
        size_t j = i;
        int readElement = array[i];
        countComparison++;
        while (j > 0 && readElement < array[j - 1]) {
            countComparison++;
            array[j] = array[j - 1];
            j--;
        }

        array[j] = readElement;
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void shell_sort(int *array, const size_t size) {
    long long countComparison = 0;
    for (size_t step = size / 2; step > 0; step /= 2) {
        int temp;
        countComparison++;
        for (size_t i = step; i < size; i++) {
            countComparison++;
            temp = array[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                countComparison++;
                if (temp < array[j - step]) {
                    countComparison++;
                    array[j] = array[j - step];
                }
                else
                    break;
            }

            array[j] = temp;
        }
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void heapify(int *array, const size_t size, const size_t index, long long countComparison) {
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    if (left < size && array[left] > array[largest]) {
        countComparison += 2;
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        countComparison += 2;
        largest = right;
    }

    if (largest != index) {
        countComparison++;
        swap(&array[index], &array[largest]);
        heapify(array, size, largest, countComparison);
    }
}

void heap_sort(int *array, const size_t size) {
    long long countComparison = 0;
    for (size_t i = size / 2 - 1; i >= 0; --i) {
        countComparison++;
        heapify(array, size, i, countComparison);
    }

    for (size_t i = size - 1; i >= 0; --i) {
        countComparison++;
        swap(&array[0], &array[i]);
        heapify(array, i, 0, countComparison);
    }

    printf("Coint of comparison: %lld\n", countComparison);
}


void count_sort(int *array, const size_t size) {
    int min, max;
    long long countComparison = 0;
    get_min_maxS(array, size, &min, &max, countComparison);

    int k = max - min + 1;
    int *buffer = (int *) calloc(k, sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        countComparison++;
        buffer[array[i] - min]++;
    }

    size_t ind = 0;
    for (size_t i = 0; i < k; ++i) {
        countComparison++;
        int x = buffer[i];
        for (size_t j = 0; j < x; ++j) {
            countComparison++;
            array[ind++] = min + i;
        }
    }

    printf("Coint of comparison: %lld\n", countComparison);

    free(buffer);
}


static void get_prefix_sum(int *array, const size_t size, long long countComparison) {
    int prev = array[0];
    *array = 0;
    for (size_t i = 1; i < size; i++) {
        countComparison++;
        int t = array[i];
        array[i] = prev + array[i - 1];
        prev = t;
    }
}

void radix_sort(int *array, const size_t size) {
    int *buffer = (int *) calloc(size, sizeof(int));
    long long countComparison = 0;

    const int STEP = 8;
    const int MASK = 0b11111111;
    for (int byte = 0; byte < sizeof(int); ++byte) {
        countComparison++;
        int values[UCHAR_MAX + 1] = {0};
        for (size_t i = 0; i < size; ++i) {
            int curByte;
            countComparison += 2;
            if (byte + 1 == sizeof(int))
                curByte = ((array[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                curByte = (array[i] >> (byte * STEP)) & MASK;

            values[curByte]++;
        }

        get_prefix_sum(values, UCHAR_MAX + 1, countComparison);

        for (size_t i = 0; i < size; ++i) {
            int curByte;
            countComparison += 2;
            if (byte + 1 == sizeof(int))
                curByte = ((array[i] >> (byte * STEP)) + CHAR_MAX + 1) & MASK;
            else
                curByte = (array[i] >> (byte * STEP)) & MASK;

            buffer[values[curByte]++] = array[i];
        }

        memcpy(array, buffer, sizeof(int) * size);
    }

    printf("Coint of comparison: %lld\n", countComparison);

    free(buffer);
}


void merge(const int *arrayA, const size_t sizeA, const int *arrayB, const size_t sizeB, int *buffer, long long countComparison) {
    size_t i = 0;
    size_t j = 0;
    while (i < sizeA || j < sizeB) {
        countComparison += 2;
        if (j == sizeB || i < sizeA && arrayA[i] < arrayB[j]) {
            countComparison += 2;
            buffer[i + j] = arrayA[i];
            i++;
        }
        else {
            buffer[i + j] = arrayB[j];
            j++;
        }
    }
}

void merge_sort_(int *array, const size_t left, const size_t right, int *buffer, long long countComparison) {
    size_t n = right - left;
    if (n <= 1) {
        countComparison++;
        return;
    }

    size_t middle = (left + right) / 2;
    merge_sort_(array, left, middle, buffer, countComparison);
    merge_sort_(array, middle, right, buffer, countComparison);

    merge(array + left, middle - left, array + middle, right - middle, buffer, countComparison);
    memcpy(array + left, buffer, sizeof(int) * n);
}

void merge_sort(int *array, const size_t size) {
    int *buffer = (int *) malloc(sizeof(int) * size);
    long long countComparison = 0;
    merge_sort_(array, 0, size, buffer, countComparison);

    printf("Coint of comparison: %lld\n", countComparison);

    free(buffer);
}

void qsort_ass(int *array, const size_t size) {
    size_t left = 0;
    size_t right = size - 1;
    size_t middle = (right - left) / 2;
    long long countComparison = 0;
    do {
        countComparison++;
        while (array[left] < array[middle]) {
            countComparison++;
            left++;
        }
        while (array[right] > array[middle]) {
            countComparison++;
            right--;
        }

        if (left <= right) {
            countComparison++;
            swapVoid(&array[left], &array[right], sizeof(int));

            left++;
            right--;
        }
    } while (left <= right);

    if (right > 0) {
        countComparison++;
        qsort_int(array, right + 1);
    }
    if (left < size) {
        countComparison++;
        qsort_int(&array[left], size - left);
    }

    printf("Coint of comparison: %lld\n", countComparison);
}

int cmp_int(const void *pa, const void *pb) {
    int arg1 = *(const int *) pa;
    int arg2 = *(const int *) pb;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

void qsort_int(int *array, const size_t size) {
    qsort(array, size, sizeof(int), cmp_int);
}