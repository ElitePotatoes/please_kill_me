#include "algorithm.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *b = *a;
    *a = tmp;
}

void swapVoid(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; ++i) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;

        pa++;
        pb++;
    }
}


int max2(const int a, const int b) {
    return a >= b ? a : b;
}

int max3(const int a, const int b, const int c) {
    return max2(max2(a, b), c);
}

int min2(const int a, const int b) {
    return a >= b ? a : b;
}

int min3(const int a, const int b, const int c) {
    return min2(min2(a, b), c);
}


void sort2(int *a, int *b) {
    if (*a > *b)
        swap(a, b);
}

void sort3(int *a, int *b, int *c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}


double getDistance(int x1, int y1, int x2, int y2) {
    int deltaX = x2 - x1;
    int deltaY = y2 - y1;
    double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    return distance;
}

void solveX2(double a, double b, double c) {
    long long D = pow(b, 2) - 4 * a * c;

    double sqrtD = sqrt(D);
    if (D > 0) {
        double x1 = (-b - sqrtD) / (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);
        printf("%lf\n %lf", x1, x2);
    }
    else if (D == 0) {
        double x = (-b / (2 * a));
        printf("%lf", x);
    }
    else
        printf("Действительных корней нет");
}

int trueTriangle(int *a, int *b, int *c) {
    sort3(a, b, c);
    return *c <= *a + *b;
}

int getTriangleTypeLength(int *a, int *b, int *c) {
    if (!trueTriangle(a, b, c))
        return -1;
    else {
        int diagonal = pow((double)*c, 2);
        int sumAnotherSides = pow((double)*a, 2) + pow((double)*b, 2);
        return diagonal > sumAnotherSides ? 2 : diagonal - sumAnotherSides == 0 ? 1 : 0;
    }
}


int isDigit(char x) {
    return (x >= '0' && x <= '9');
}

int isPrimeViaSqrtSteps2(int x) {
    int d = 1;
    int maxD = sqrt(x);
    if (x == maxD * maxD)
        d++;
    else {
        for (int i = 2; i < maxD; i += 2)
            if (x % i == 0)
                d++;
    }
    return d == 1;
}


int translationToBin(int num) {
    int bin = 0;
    int k = 1;
    while (num) {
        bin += (num & 2) * k;
        k *= 10;
        num >>= 1;
    }

    return bin;
}

int deleteOctNumber(int *num, int digit) {
    int oct = 0;
    int k = 1;
    while (*num) {
        int octDigit = *num & 7;
        if (octDigit != digit) {
            oct += octDigit * k;
            k <<= 3;
        }
        *num >>= 3;
    }
    *num = num;
}

int printOct(int num) {
    int oct = 0;
    int shift = 1;
    while (num) {
        oct += (num & 7) * shift;
        shift *= 10;
        num >>= 3;
    }

    printf("%d", oct);
}

int getMaxLenghUnits(int num) {
    int maxLengh = 0;
    int count = 0;
    while(num) {
        if (num & 2) {
            count++;
            maxLengh = max2(count, maxLengh);
        }
        else
            count = 0;
        num >>= 1;
    }

    return maxLengh;
}

void invertHex(int *num) {
    int newNum = 0;
    while (*num) {
        int lastDigit = *num & 15;
        newNum = newNum << 4 | lastDigit;
        *num >>= 4;
    }
    *num = newNum;
}

int swapPairBites(int num) {
    int newNum = 0;
    int shift = 0;
    while (num != 0) {
        int firstBit = num & 1;
        int secondBit = (num >> 1) & 1;
        if (num == 1 && secondBit == 0)
            swap(&firstBit, &secondBit);
        newNum |= secondBit << shift;
        newNum |= firstBit << (shift + 1);
        shift += 2;
        num >>= 2;
    }
    return newNum;
}