#include "test_vector_void.h"

void test_vector_void_full_verOne() {
    size_t n ;
    scanf ("%zd", &n) ;

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n ; i ++) {
        int x;
        scanf("%d", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n ; i++) {
        int x;
        getVectorValueV(&v, i, &x);

        printf("%d ", x);
    }
}

void test_vector_void_full_verTwo() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV (0, sizeof(float));
    for (int i = 0; i < n ; i++) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i ++) {
        float x ;
        getVectorValueV(&v, i, &x) ;

        printf("%f ", x);
    }
}

void tests_vector_void() {
    test_vector_void_full_verOne();
    test_vector_void_full_verTwo();
}