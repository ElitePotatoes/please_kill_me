#include "unordered_array_set.h"

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create(const size_t capacity) {
    return (unordered_array_set) {malloc(capacity * sizeof(int)), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, const size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; ++i)
        unordered_array_set_insert(&set, a[i]);

    return set;
}

void unordered_array_set_print(unordered_array_set const set) {
    printf("{");
    for (size_t i = 0; i < set.size; ++i)
        printf("%d, ", set.data[i]);

    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

size_t unordered_array_set_in(unordered_array_set const *set, const int value) {
    return linearSearch(set->data, set->size, value);
}

bool unordered_array_set_isEqual(unordered_array_set const set1, unordered_array_set const set2) {
    if (set1.size != set2.size)
        return false;

    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);

    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set const *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t deleteIndex = unordered_array_set_in(set, value);
    if (set->size != deleteIndex) {
        deleteByPosUnsaveOrder(set->data, &set->size, deleteIndex);

        unordered_array_set_shrinkToFit(set);
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set const set1, unordered_array_set const set2) {
    unordered_array_set set3 = unordered_array_set_create(set1.capacity + set2.capacity);
    for (size_t i = 0; i < set1.size; ++i)
        append(set3.data, &set3.size, set1.data[i]);

    for (size_t i = 0; i < set2.size; ++i)
        if (unordered_array_set_in(&set1, set2.data[i]) == set1.size)
            append(set3.data, &set3.size, set2.data[i]);

    unordered_array_set_shrinkToFit(&set3);

    return set3;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set const set1, unordered_array_set const set2) {
    unordered_array_set set3 = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; ++i)
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size)
            append(set3.data, &set3.size, set1.data[i]);

    unordered_array_set_shrinkToFit(&set3);

    return set3;
}

unordered_array_set unordered_array_set_difference(unordered_array_set const set1, unordered_array_set const set2) {
    unordered_array_set set3 = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; ++i)
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append(set3.data, &set3.size, set1.data[i]);

    unordered_array_set_shrinkToFit(&set3);

    return set3;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set const set1, unordered_array_set const set2) {
    unordered_array_set setDifference1 = unordered_array_set_difference(set1, set2);
    unordered_array_set setDifference2 = unordered_array_set_difference(set2, set1);
    unordered_array_set setSymmetricDifference = unordered_array_set_union(setDifference1, setDifference2);

    unordered_array_set_delete(setDifference1);
    unordered_array_set_delete(setDifference2);

    return setSymmetricDifference;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_intersection(universumSet, set);
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}