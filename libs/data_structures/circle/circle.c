#include "circle.h"

void inputCircle(circle *a) {
    inputPoint(&a->center);

    scanf("%lf", &a->r);
}

void inputCircles(circle a[], size_t size) {
    for (size_t i = 0; i < size; ++i)
        inputCircle(&a[i]);
}

void outputCircle(circle a) {
    outputPoint(a.center);

    printf("%lf", a.r);
}

void outputCircles(circle a[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        outputCircle(a[i]);
}

bool hasOneOuterIntersection(circle c1, circle c2) {
    return (getDistance_(c1.center, c2.center) - c1.r + c2.r) < DBL_EPSILON;
}

void decreasingCirclesByRadius(circle c[], const size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (size_t j = i + 1; j < size; ++j)
            if (c[i].r > c[maxIndex].r)
                swapVoid(&c[i], &c[maxIndex], sizeof(double));
    }
}

bool isInnerCircle(circle c1, circle c2) {
    return getDistance_(c1.center, c2.center) < c1.r - c2.r;
}

int countingInnerCircles(const circle c[], const size_t size, const size_t index) {
    int counter = 0;
    for (size_t i = index + 1; i < size; ++i)
        if (isInnerCircle(c[index], c[i]))
            counter++;

    return counter;
}

circle getCircleWithMaxCircles(const circle c[], const size_t size) {
    int minIndex = 0;
    int maxCircles = 0;
    for (size_t i = 0; i < size; ++i) {
        int nowCircles = countingInnerCircles(c, size, i);
        if (nowCircles > maxCircles) {
            maxCircles = nowCircles;
            minIndex = i;
        }
    }

    return c[minIndex];
}
