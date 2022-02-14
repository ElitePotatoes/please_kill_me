#include "../vector.h"

void test_pushBack_emptyVectorVer1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    assert(v.size == 1 && v.capacity == 1);

    deleteVector(&v);
}
void test_pushBack_emptyVectorVer2() {
    vector v = createVector(5);
    pushBack(&v, 1);
    assert(v.size == 1 && v.capacity == 5);

    deleteVector(&v);
}
void test_pushBack_nonEmptyVector() {
    vector v = (vector) {(int[]){1}, 1, 5};
    pushBack(&v, 2);
    assert(v.size == 2 && v.capacity == 5);

    deleteVector(&v);
}
void test_pushBack() {
    test_pushBack_emptyVectorVer1();
    test_pushBack_emptyVectorVer2();
    test_pushBack_nonEmptyVector();
}

void test_popBack_nonEmptyVector() {
    vector v = (vector) {(int[]){1}, 1, 1};
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVector(&v);
}
void test_popBack() {
    test_pushBack_nonEmptyVector();
}

void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]){1, 2, 3}, 3, 3};
    assert(*atVector(&v, 0) == 1);
    assert(*atVector(&v, 1) == 2);
    assert(*atVector(&v, 2) == 3);

    deleteVector(&v);
}
void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]){1, 2, 3}, 3, 3};
    assert(*atVector(&v, v.size - 1) == 3);

    deleteVector(&v);
}
void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]){1}, 1, 1};
    assert(*back(&v) == 1);

    deleteVector(&v);
}
void test_front_oneElementInVector() {
    vector v = (vector) {(int[]){1}, 1, 1};
    assert(*front(&v) == 1);

    deleteVector(&v);
}
void test_backAndFront() {
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

void tests_vector() {
    test_pushBack();
    test_popBack();
    test_atVector();
    test_backAndFront();
}