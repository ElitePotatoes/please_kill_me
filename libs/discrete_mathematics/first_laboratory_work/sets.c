#include "sets.h"

#define MAX_SIZE_ARRAY_FOR_TESTS 10

void unordered_array_set_union(const int a[], const size_t sizeA,
                               const int b[], const size_t sizeB,
                               int c[], size_t *sizeC) {
    for (size_t i = 0; i < sizeA; ++i) {
        c[i] = a[i];
        (*sizeC)++;
    }

    for (size_t i = 0; i < sizeB; ++i) {
        bool isUnique = true;
        for (size_t j = 0; j < sizeA; ++j) {
            if (b[i] == a[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            c[*sizeC] = b[i];
            (*sizeC)++;
        }
    }
}

void unordered_array_set_intersection(const int a[], const size_t sizeA,
                                      const int b[], const size_t sizeB,
                                      int c[], size_t *sizeC) {
    for (size_t i = 0; i < sizeA; ++i)
        for (size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                c[*sizeC] = a[i];
                (*sizeC)++;
                break;
            }
}

void unordered_array_set_difference(const int a[], const size_t sizeA,
                                    const int b[], const size_t sizeB,
                                    int c[], size_t *sizeC) {
    for (size_t i = 0; i < sizeA; ++i) {
        bool isUnique = true;
        for (size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                isUnique = false;
                break;
            }

        if (isUnique) {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }
    }
}

void unordered_array_set_symmetricDifference(const int a[], const size_t sizeA,
                                             const int b[], const size_t sizeB,
                                             int c[], size_t *sizeC) {
    for (size_t i = 0; i < sizeA; ++i) {
        bool isUnique = true;
        for (size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                isUnique = false;
                break;
            }

        if (isUnique) {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }
    }

    for (size_t i = 0; i < sizeB; ++i) {
        bool isUnique = true;
        for (size_t j = 0; j < sizeA; ++j)
            if (b[i] == a[j]) {
                isUnique = false;
                break;
            }

        if (isUnique) {
            c[*sizeC] = b[i];
            (*sizeC)++;
        }
    }
}

bool unordered_array_set_isSimilar(const int a[], const size_t sizeA,
                                   const int b[], const size_t sizeB) {
    int counter = -1;
    for (size_t i = 0; i < sizeA; ++i) {
        for (size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                counter++;
                break;
            }

        if (counter != i)
            return false;
    }

    return true;
}

bool unordered_array_set_isEqual(const int a[], const size_t sizeA,
                                 const int b[], const size_t sizeB) {
    if (sizeA != sizeB)
        return false;

    int counter = 0;
    for (size_t i = 0; i < sizeA; ++i)
        for (size_t j = 0; j < sizeB; ++j)
            if (a[i] == b[j]) {
                counter++;
                break;
            }

    return counter == sizeA;
}

bool unordered_array_set_isDifferent(const int a[], const size_t sizeA,
                                     const int b[], const size_t sizeB) {
    for (int i = 0; i < sizeA; ++i)
        for (int j = 0; j < sizeB; ++j)
            if (a[i] == b[j])
                return false;

    return true;
}

void ordered_array_set_union(const int a[], const size_t sizeA,
                             const int b[], const size_t sizeB,
                             int c[], size_t *sizeC) {
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] == b[j]){
            c[*sizeC] = a[i];
            (*sizeC)++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            c[*sizeC] = a[i];
            (*sizeC)++;
            i++;
        }
        else {
            c[*sizeC] = b[j];
            (*sizeC)++;
            j++;
        }
    }

    if (i == sizeA)
        for (size_t k = j; k < sizeB; ++k) {
            c[*sizeC] = b[k];
            (*sizeC)++;
        }
    else if (j == sizeB)
        for (size_t k = i; k < sizeA; ++k) {
            c[*sizeC] = a[k];
            (*sizeC)++;
        }
}

void ordered_array_set_intersection(const int a[], const size_t sizeA,
                                    const int b[], const size_t sizeB,
                                    int c[], size_t *sizeC) {
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] == b[j]) {
            c[*sizeC] = a[i];
            i++;
            j++;
            (*sizeC)++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
}

void ordered_array_set_difference(const int a[], const size_t sizeA,
                                  const int b[], const size_t sizeB,
                                  int c[], size_t *sizeC) {
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] == b[j]){
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            c[*sizeC] = a[i];
            i++;
            (*sizeC)++;
        }
        else
            j++;
    }

    if (j == sizeB)
        for (int k = i; k < sizeA; ++k) {
            c[*sizeC] = a[k];
            (*sizeC)++;
        }
}

void ordered_array_set_symmetricDifference(const int a[], const size_t sizeA,
                                           const int b[], const size_t sizeB,
                                           int c[], size_t *sizeC) {
    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            c[*sizeC] = a[i];
            i++;
            (*sizeC)++;
        }
        else {
            c[*sizeC] = b[j];
            j++;
            (*sizeC)++;
        }
    }

    if (i == sizeA)
        for (int k = j; k < sizeB; ++k) {
            c[*sizeC] = b[k];
            (*sizeC)++;
        }
    else if (j == sizeB)
        for (int k = i; k < sizeA; ++k) {
            c[*sizeC] = a[k];
            (*sizeC)++;
        }
}

bool ordered_array_set_isEqual(const int a[], const size_t sizeA,
                               const int b[], const size_t sizeB) {
    if (sizeA != sizeB)
        return false;

    int i = 0;
    int j = 0;
    while (i < sizeA && j < sizeB) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }
        else
            return false;
    }

    return true;
}

void test_unordered_array_set_union() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    unordered_array_set_union(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {2, 3, 4, 5, 1};
    int sizeCheck = 5;

    assert(unordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_unordered_array_set_intersection() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    unordered_array_set_intersection(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {2, 3};
    int sizeCheck = 2;

    assert(unordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_unordered_array_set_difference() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    unordered_array_set_difference(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {4, 5};
    int sizeCheck = 2;

    assert(unordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_unordered_array_set_symmetricDifference() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    unordered_array_set_symmetricDifference(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {4, 5, 1};
    int sizeCheck = 3;

    assert(unordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_unordered_array_set_isSimilar() {
    size_t sizeA = 3;
    int a[] = {1, 3, 5};

    size_t sizeB = 5;
    int b[] = {1, 2, 3, 4, 5};

    assert(unordered_array_set_isSimilar(a, sizeA, b, sizeB));
}
void test_unordered_array_set_isEqual() {
    size_t sizeA = 3;
    int a[] = {1, 2, 3};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    assert(unordered_array_set_isEqual(a, sizeA, b, sizeB));
}
void test_unordered_array_set_isDifferent() {
    size_t sizeA = 3;
    int a[] = {1, 2, 3};

    size_t sizeB = 3;
    int b[] = {4, 6, 5};

    assert(unordered_array_set_isDifferent(a, sizeA, b, sizeB));
}
void test_unordered_array_set() {
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_isSimilar();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_isDifferent();
}

void test_ordered_array_set_union() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    ordered_array_set_union(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {1, 2, 3, 4, 5};
    int sizeCheck = 5;

    assert(ordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_ordered_array_set_intersection() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    ordered_array_set_intersection(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {2, 3};
    int sizeCheck = 2;

    assert(ordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_ordered_array_set_difference() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    ordered_array_set_difference(a, sizeA, b, sizeB, c, &sizeC);

    int check[] = {4, 5};
    int sizeCheck = 2;

    assert(ordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_ordered_array_set_symmetricDifference() {
    size_t sizeA = 4;
    int a[] = {2, 3, 4, 5};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    size_t sizeC = 0;
    int c[MAX_SIZE_ARRAY_FOR_TESTS];

    ordered_array_set_symmetricDifference(a, sizeA, b, sizeB, c, &sizeC);

    int check[MAX_SIZE_ARRAY_FOR_TESTS] = {1, 4, 5};
    int sizeCheck = 3;

    assert(ordered_array_set_isEqual(c, sizeC, check, sizeCheck));
}
void test_ordered_array_set_isEqual() {
    size_t sizeA = 3;
    int a[] = {1, 2, 3};

    size_t sizeB = 3;
    int b[] = {1, 2, 3};

    assert(ordered_array_set_isEqual(a, sizeA, b, sizeB));
}
void test_ordered_array_set() {
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_isEqual();
}

void test_set() {
    test_unordered_array_set();
    test_ordered_array_set();
}