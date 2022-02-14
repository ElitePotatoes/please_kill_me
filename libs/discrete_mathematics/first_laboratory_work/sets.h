#ifndef MAIN_C_SETS_H
#define MAIN_C_SETS_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void unordered_array_set_union(const int a[], size_t sizeA,
                               const int b[], size_t sizeB,
                               int c[], size_t *sizeC);

void unordered_array_set_intersection(const int a[], size_t sizeA,
                                      const int b[], size_t sizeB,
                                      int c[], size_t *sizeC);

void unordered_array_set_difference(const int a[], size_t sizeA,
                                    const int b[], size_t sizeB,
                                    int c[], size_t *sizeC);

void unordered_array_set_symmetricDifference(const int a[], size_t sizeA,
                                             const int b[], size_t sizeB,
                                             int c[], size_t *sizeC);

bool unordered_array_set_isSimilar(const int a[], size_t sizeA,
                                   const int b[], size_t sizeB);

bool unordered_array_set_isEqual(const int a[], size_t sizeA,
                                 const int b[], size_t sizeB);

bool unordered_array_set_isDifferent(const int a[], size_t sizeA,
                                     const int b[], size_t sizeB);

void ordered_array_set_union(const int a[], size_t sizeA,
                             const int b[], size_t sizeB,
                             int c[], size_t *sizeC);

void ordered_array_set_intersection(const int a[], size_t sizeA,
                                    const int b[], size_t sizeB,
                                    int c[], size_t *sizeC);

void ordered_array_set_difference(const int a[], size_t sizeA,
                                  const int b[], size_t sizeB,
                                  int c[], size_t *sizeC);

void ordered_array_set_symmetricDifference(const int a[], size_t sizeA,
                                           const int b[], size_t sizeB,
                                           int c[], size_t *sizeC);

bool ordered_array_set_isEqual(const int a[], size_t sizeA,
                               const int b[], size_t sizeB);

void test_set();

#endif //MAIN_C_SETS_H
