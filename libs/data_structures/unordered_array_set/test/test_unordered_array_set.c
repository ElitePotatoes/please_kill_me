#include "test_unordered_array_set.h"

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {3, 1, 2, 4}, 4);
    int value = 4;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 3;
    assert(needRes == resSet);

    unordered_array_set_delete(set);
}
void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    int value = -5;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 3;
    assert(needRes == resSet);

    unordered_array_set_delete(set);
}
void test_unordered_array_set_in3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5, 3, 1, 0, 2, 4}, 9);
    int value = 0;
    size_t resSet = unordered_array_set_in(&set, value);
    size_t needRes = 6;
    assert(needRes == resSet);

    unordered_array_set_delete(set);
}
void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_insert1() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4}, 4);
    int value = -5;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4, -5}, 5);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);

}
void test_unordered_array_set_insert2() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4}, 4);
    int value = 5;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4, 5}, 5);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_insert3() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4}, 4);
    int value = -4;
    unordered_array_set_insert(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]){-1, -3, -2, -4}, 4);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
    test_unordered_array_set_insert3();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    int value = -5;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2}, 3);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_deleteElement2() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    int value = -3;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -5, -2}, 3);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_deleteElement3() {
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    int value = 3;
    unordered_array_set_deleteElement(&resSet, value);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    assert(unordered_array_set_isEqual(needRes, resSet));

    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
    test_unordered_array_set_deleteElement3();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5, 1, 2, 3}, 7);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, -2, -3}, 3);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_union3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5, 2, 3}, 6);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {0}, 0);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {-1}, 1);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_intersection3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -5, 3, 5, 2, 1, 6}, 9);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-9, 2, 3, 6}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {3, 2, 6}, 3);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {0, 3, 6}, 3);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {63, 3, 4, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {63, 5}, 2);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_difference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 1, -4, 5, 7, 9}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 3}, 5);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1}, 1);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {5, 6, 7, 1, 2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 3}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1, -4, 6, 2, 9, 3}, 6);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-4, -5, 5, 6, -2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-2, 6, 5, -5, -4}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {0}, 0);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 3, 5}, 3);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_complement(set, setUniverse);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1, 3, 5, 2, 4}, 5);
    assert (unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_complement2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_complement(set, setUniverse);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_complement3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {0}, 0);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resSet = unordered_array_set_complement(set, setUniverse);
    unordered_array_set needRes = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resSet, needRes));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(needRes);
}
void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}