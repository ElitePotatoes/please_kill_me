#include "test_ordered_array.h"

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set setDifference1 = ordered_array_set_difference(set1, set2);
    ordered_array_set setDifference2 = ordered_array_set_difference(set2, set1);
    ordered_array_set setSymmetricDifference = ordered_array_set_union(setDifference1, setDifference2);

    ordered_array_set_delete(setDifference1);
    ordered_array_set_delete(setDifference2);

    return setSymmetricDifference;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return ordered_array_set_union(set, universumSet);
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

void test_ordered_array_set_in1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    int value = 1;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 0;
    printf("%d", resSet);
    printf("%d", needRes);

    assert(needRes == resSet);

    ordered_array_set_delete(set);
}
void test_ordered_array_set_in2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -1;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 3;
    assert(needRes == resSet);

    ordered_array_set_delete(set);
}
void test_ordered_array_set_in3() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 0, 1, 2, 3, 4}, 9);
    int value = 0;
    size_t resSet = ordered_array_set_in(&set, value);
    size_t needRes = 4;
    assert(needRes == resSet);

    ordered_array_set_delete(set);
}
void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
}

void test_ordered_array_set_isSubset1() {
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 1;
    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}
void test_ordered_array_set_isSubset2() {
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {1, 2, 3, 6}, 4);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 0;
    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}
void test_ordered_array_set_isSubset3() {
    ordered_array_set subSet = ordered_array_set_create_from_array((int[]) {0}, 0);
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0},0);
    bool resSet = ordered_array_set_isSubset(subSet, set);
    bool needRes = 0;
    assert(needRes == resSet);

    ordered_array_set_delete(subSet);
    ordered_array_set_delete(set);
}
void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
}

void test_ordered_array_set_insert1() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-4, -3, -2, -1}, 5);
    int value = -5;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-1, -3, -2, -4, -5}, 5);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_insert2() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {1, 3, 2, 4}, 5);
    int value = 0;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){0, 1, 2, 3, 4}, 5);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_insert3() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-4, -3, -2, -1}, 4);
    int value = -4;
    ordered_array_set_insert(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-4, -3, -2, -1}, 4);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
    test_ordered_array_set_insert3();
}

void test_ordered_array_set_deleteElement1() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -5;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-3, -2, -1}, 3);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_deleteElement2() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = -3;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-5, -2, -1}, 3);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_deleteElement3() {
    ordered_array_set resSet = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    int value = 3;
    ordered_array_set_deleteElement(&resSet, value);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]){-5, -3, -2, -1}, 4);
    assert(ordered_array_set_isEqual(needRes, resSet));

    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
    test_ordered_array_set_deleteElement3();
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 1, 2, 3}, 7);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_union2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-3, -2, -1}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_union3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 2, 3}, 6);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
}

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0}, 0);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_intersection2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {-1}, 1);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_intersection3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -3, -2, -1, 1, 2, 3, 5, 6}, 9);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-9, 2, 3, 6}, 4);
    ordered_array_set resSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {2, 3, 6}, 3);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
}

void test_ordered_array_set_difference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 5}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0, 3, 6}, 3);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_difference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 63}, 4);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {5, 63}, 2);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_difference3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-4, 1, 3, 5, 7, 9}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 3, 5, 7, 9}, 5);
    ordered_array_set resSet = ordered_array_set_difference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1}, 1);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
}

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 5, 6, 7}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-4, 3, 5, 7, 9}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, -4, 6, 2, 9, 3}, 6);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_symmetricDifference3() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {-5, -4, -2, 5, 6}, 5);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {-5, -4, -2, 5, 6}, 5);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {0}, 0);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
    test_ordered_array_set_symmetricDifference3();
}

void test_ordered_array_set_complement1() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 3, 5}, 3);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5},5);
    ordered_array_set resSet = ordered_array_set_complement(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_complement2() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5},5);
    ordered_array_set resSet = ordered_array_set_complement(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_complement3() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {0},0);
    ordered_array_set setUniverse = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet = ordered_array_set_complement(set, setUniverse);
    ordered_array_set needRes = ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(ordered_array_set_isEqual(resSet, needRes));

    ordered_array_set_delete(set);
    ordered_array_set_delete(setUniverse);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(needRes);
}
void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
}

void test_ordered_array_set() {
    test_ordered_array_set_in();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}