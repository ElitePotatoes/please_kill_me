#include "fraction.h"

void inputFraction(fraction *f) {
    scanf("%d / %d", &f->numerator, &f->denumerator);
}

void inputFractions(fraction f[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        inputFraction(&f[i]);
}

void outputFraction(fraction f) {
    printf("%d / %d\n", f.numerator, f.denumerator);
}

void outputFractions(fraction f[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        outputFraction(f[i]);
}

int gcd(int a, int b) {
    while (a != 0 && b != 0)
        if (a > b)
            a %= b;
        else
            b %= a;

    return a + b;
}

int lcm(int a, int b) {
    int gcdValue = gcd(a, b);
    if (gcdValue)
        return a * b / gcdValue;
    else
        return 0;
}

void simpleFraction(fraction *f) {
    int reduction = gcd(f->numerator, f->denumerator);
    f->numerator /= reduction;
    f->denumerator /= reduction;
}

fraction mulFractions(fraction f1, fraction f2) {
    fraction f3 = {f1.numerator * f2.numerator, f1.denumerator * f2.denumerator};
    simpleFraction(&f3);

    return f3;
}

void swapElementsOfFraction(fraction *f) {
    swapVoid(&f->numerator, &f->denumerator, sizeof(fraction));
}

fraction divFraction(fraction f1, fraction f2) {
    if (f2.denumerator == 0)
        return (fraction) {0, 0};
    else
        swapElementsOfFraction(&f2);

    mulFractions(f1, f2);
}

fraction addFraction(fraction f1, fraction f2) {
    fraction f3 = {f1.numerator * f2.denumerator + f2.numerator * f1.denumerator, f2.numerator * f1.denumerator};
    simpleFraction(&f3);

    return f3;
}

fraction subFraction(fraction f1, fraction f2) {
    f2.numerator = -f2.numerator;
    addFraction(f1, f2);
}

fraction sumFractions(const fraction f[], const size_t size) {
    fraction sumFractions = {f[0].numerator, f[0].denumerator};
    for (size_t i = 1; i < size; ++i)
        addFraction(sumFractions, f[i]);

    return sumFractions;
}