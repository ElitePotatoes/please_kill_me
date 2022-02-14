#include "ordered_array_set.h"

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *)realloc(a->data, sizeof(int) *a->size);
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(capacity *sizeof(int)), 0, capacity};
}

ordered_array_set ordered_array_set_create_from_array(const int a[], size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; ++i)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);

    return set;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; ++i)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}\n");
    else
        printf("\b\b}\n");
}

size_t ordered_array_set_in(ordered_array_set set[], int value) {
    return binarySearch(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    return memcmp(set1.data, set2.data, sizeof(int) *set1.size) == 0;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    return ordered_array_set_isEqual(subset, ordered_array_set_intersection(set, subset));
}

void ordered_array_set_isAbleAppend(ordered_array_set set[]) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set set[], int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        set->data = (int *) realloc(set->data, (set->size + 1) * sizeof(int));
        append(set->data, &set->size, value);
        ordered_array_set_shrinkToFit(set);

        qsort(set->data, set->size, sizeof(int) *set->size, compare_ints);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t deleteIndex = ordered_array_set_in(set, value);
    if (set->size != deleteIndex) {
        deleteByPosSaveOrder(set->data, &set->size, deleteIndex);
        ordered_array_set_shrinkToFit(set);
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.capacity + set2.capacity);

    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size) {
        if (set1.data[set1Read] < set2.data[set2Read])
            append(set3.data, &set3.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            append(set3.data, &set3.size, set2.data[set2Read++]);
        else {
            append(set3.data, &set3.size, set1.data[set1Read++]);
            set2Read++;
        }
    }
    while (set1Read < set1.size)
        append(set3.data, &set3.size, set1.data[set1Read++]);
    while (set2Read < set2.size)
        append(set3.data, &set3.size, set2.data[set2Read++]);

    ordered_array_set_shrinkToFit(&set3);

    return set3;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.capacity);

    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size)
        if (set1.data[set1Read] < set2.data[set2Read])
            set1Read++;
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            append(set3.data, &set3.size, set1.data[set1Read++]);
            set2Read++;
        }

    ordered_array_set_shrinkToFit(&set3);

    return set3;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.capacity);

    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size)
        if (set1.data[set1Read] < set2.data[set2Read])
            append(set3.data, &set3.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            set1Read++;
            set2Read++;
        }

    while (set1Read < set1.size)
        append(set3.data, &set3.size, set1.data[set1Read++]);

    ordered_array_set_shrinkToFit(&set3);

    return set3;
}