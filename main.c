#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <memory.h>
#include <assert.h>

#include "libs/data_structures/matrix/matrix.h"

int main() {
    //SetConsoleOutputCP (CP_UTF8);

    matrix m = getMemMatrix(3, 3);

    inputMatrix(m);
    outputMatrix(m);

    printf("\n");

    //swapRows(m, 1, 2);
    //swapColumns(m, 1, 2);
    transposeSquareMatrix(m);

    outputMatrix(m);

    //

    return 0;
}