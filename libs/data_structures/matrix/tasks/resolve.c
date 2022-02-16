#include "resolve.h"

/********************************************************* 1 **********************************************************/

void swapRowsWithMaxAndMinValue(matrix m) {
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    if (minIndex.rowIndex != maxIndex.rowIndex)
        swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

/********************************************************* 2 **********************************************************/

int getMax(const int a[], const size_t size) {
    int maxValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] > maxValue)
            maxValue = a[i];

    return maxValue;
}

void sortRowsByMaxElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/********************************************************* 3 **********************************************************/

int getMin(const int a[], const size_t size) {
    int minValue = a[0];
    for (size_t i = 1; i < size; ++i)
        if (a[i] < minValue)
            minValue = a[i];

    return minValue;
}

void sortColsByMinElements(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

/********************************************************* 4 **********************************************************/

void impossibleMultiplication() {
    fprintf(stderr, "multiplication isn't possible");
    exit(1);
}

matrix mulMatrices(matrix const m1, matrix const m2) {
    if (m1.nCols != m2.nRows)
        impossibleMultiplication();

    matrix m3 = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m2.nCols; ++j) {
            m3.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; ++k)
                m3.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m3;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

/********************************************************* 5 **********************************************************/

long long getSum(const int a[], const size_t size) {
    long long sum = 0;
    for (size_t i = 0; i < size; ++i)
        sum += a[i];

    return sum;
}

bool isUnique(const int a[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i + 1; j < size - 1; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = getSum(m.values[i], m.nCols);

    if (isUnique(criteriaArray, m.nRows))
        transposeSquareMatrix(m);
}

/********************************************************* 6 **********************************************************/

bool isMutuallyInverseMatrices(matrix const m1, matrix const m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

/********************************************************* 7 **********************************************************/

int getMaxDiagonalElement(matrix const m, size_t indexRow, size_t indexCol) {
    int maxElement = m.values[indexRow][indexCol];
    while (indexRow < m.nRows && indexCol < m.nCols)
        maxElement = max2(maxElement, m.values[indexRow++][indexCol++]);

    return maxElement;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix const m) {
    long long sumElements = 0;
    for (size_t l = 1; l < m.nRows; ++l)
        sumElements += getMaxDiagonalElement(m, l, 0);

    for (size_t h = 1; h < m.nCols; ++h)
        sumElements += getMaxDiagonalElement(m, 0, h);

    return sumElements;
}

/********************************************************* 8 **********************************************************/

int getMinInArea(matrix const m) {
    position leftElement = getMaxValuePos(m);
    position rightElement = leftElement;

    int minElement = m.values[leftElement.rowIndex][leftElement.colIndex];
    if (leftElement.rowIndex == 0)
        return minElement;

    int subArr[10];
    int sizeSubArr = 1;
    while (leftElement.rowIndex >= 0 && rightElement.rowIndex <= m.nCols) {
        if (leftElement.colIndex == -1) {
            leftElement.colIndex++;
            sizeSubArr--;
        }

        if (rightElement.colIndex == m.nCols) {
            rightElement.colIndex--;
            sizeSubArr--;
        }

        int i = 0;
        while (i < sizeSubArr) {
            subArr[i] = (m).values[leftElement.rowIndex][leftElement.colIndex + i];
            i++;
        }

        minElement = getMin(subArr, sizeSubArr);

        rightElement.rowIndex--;
        rightElement.colIndex++;
        leftElement.rowIndex--;
        leftElement.colIndex--;
        sizeSubArr += 2;
    }

    return minElement;
}