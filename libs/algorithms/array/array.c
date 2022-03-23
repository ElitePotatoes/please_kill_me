#include <stdio.h>
#include <limits.h>
#include <assert.h>

#include "array.h"
#include "C:\Users\elite\CLionProjects\main\libs\algorithms\algorithm.h"

void inputArray(int a[], const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void output_array(const int *array, const size_t size) {
    printf("{");

    for (size_t i = 0; i < size; i++)
        printf("%d, ", array[i]);

    printf("\b\b}\n");
}

void append(int a[], size_t *size, const int value) {
    a[*size] = value;
    (*size)++;
}

void insert(int a[], size_t *n, const size_t pos, const int value) {
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];

        a[pos] = value;
    }
    else {
        (*n)++;
        a[pos] = value;
    }
}

void deleteByPosSaveOrder(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i] = a[i + 1];

    (*n)--;
}

void deleteByPosUnsaveOrder(int a[], size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}


int any(const int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;

    return 0;
}

int all(const int *a, size_t n, int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;

    return 1;
}

int countIf(const int a[], const size_t n, int (*predicate)(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);

    return count;
}

void deleteIf(int a[], size_t *const n, int (*deletePredicate)(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;

    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }

    *n = iWrite;
}

void forEach(const int *source, int *dest, const size_t n, const int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}


int linearSearch(const int a[], const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int binarySearch(const int a[], const size_t size, const int x) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] > x)
            right = middle - 1;
        else if (a[middle] < x)
            left = middle + 1;
        else
            return a[middle];
    }

    return size;
}

int binarySearchMoreOrEqual(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;

    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }

    return right;
}


void increasingSort(int a[], const size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] < a[minIndex])
                minIndex = j;

        if (minIndex != i)
            swap(&a[i], &a[minIndex]);
    }
}

void decreasingSort(int a[], const size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] > a[minIndex])
                minIndex = j;

        if (minIndex != i)
            swap(&a[i], &a[minIndex]);
    }
}

void insertionSort(int *a, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

int getMax(const int a[], const size_t size) {
    int maxValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] > maxValue)
            maxValue = a[i];

    return maxValue;
}

int getMin(const int a[], const size_t size) {
    int minValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] < minValue)
            minValue = a[i];

    return minValue;
}

long long getSum(const int a[], const size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += a[i];

    return sum;
}

bool isUnique(const int a[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i + 1; j < size - 1; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

bool is_ordered(const int *array, const size_t size) {
    if (size > 1)
        for (size_t i = 0; i < size - 1; ++i)
            if (array[i] > array [i + 1])
                return false;

    return true;
}

int countNUnique(long long a[], const size_t size) {
    qsort(a, size, sizeof(long long), cmp_long_long);

    int counter = 0;
    for (size_t i = 0; i < size - 1; ++i)
        if (a[i] == a[i + 1] && a[i] != a[i - 1]
            || a[i] != a[i - 1] && a[i] != a[i + 1] && i != 0)
            counter++;

    return counter;
}

bool isNonDescendingSorted(const int a[], const size_t size) {
    for (size_t i = 1; i < size; ++i)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

int countValues(const int a[], const size_t size, const int value) {
    int counter = 0;
    for (size_t i = 0; i < size; ++i)
        if (a[i] == value)
            counter++;

    return counter;
}


int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

void shuffle_array(int *array, const size_t size) {
    for (size_t i = 0; i < size; ++i)
        swapVoid(&array[i], &array[(rand() % size)], sizeof(int));
}

void get_min_maxS(const int *array, const size_t size, int *min, int *max, long long countComparison) {
    *min = array[0];
    *max = array[0];
    for (size_t i = 1; i < size; ++i) {
        if (array[i] < *min)
            *min = array[i];
        else if (array[i] > *max)
            *max = array[i];

        countComparison += 3;
    }
}