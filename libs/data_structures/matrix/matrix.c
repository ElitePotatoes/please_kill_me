#include "matrix.h"

void badIndex() {
    fprintf(stderr, "bad index\n");
    exit(1);
}

void badSquareMatrix() {
    fprintf(stderr, "isn't square matrix\n");
    exit(1);
}

void impossibleMultiplication() {
    fprintf(stderr, "multiplication isn't possible");
    exit(1);
}

matrix getMemMatrix(const int nRows, const int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(const int nMatrices, const int nRows, const int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (size_t i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i)
        free(m.values[i]);

    free(m.values);
}

void freeMemMatrices(matrix *ms, const int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);

    free(ms->values);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, const int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix const m) {
    for (size_t i = 0; i < m.nRows; ++i) {
        printf("{");

        for (size_t j = 0; j < m.nCols; ++j)
            printf("%d, ", m.values[i][j]);

        printf("\b\b}\n");
    }
}

void outputMatrices(matrix *ms, const int nMatrices) {
    for (size_t i = 0; i < nMatrices; ++i)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, const int i1, const int i2) {
    if (i1 >= m.nRows || i2 >= m.nRows)
        badIndex();

    swapVoid(&m.values[i1], &m.values[i2], sizeof(int));
}

void swapColumns(matrix m, const int j1, const int j2) {
    if (j1 >= m.nCols || j2 >= m.nCols)
        badIndex();

    for (size_t i = 0; i < m.nRows; ++i)
        swapVoid(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 0; i < m.nRows - 1; ++i)
        for (size_t j = i + 1; j < m.nRows; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapRows(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(int));
            }

    free(criteriaArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArray = (int *) malloc(sizeof(int) * m.nCols);
    int *colsElements = (int *) malloc(sizeof(int) * m.nRows);
    for (size_t j = 0; j < m.nCols; ++j) {
        for (size_t i = 0; i < m.nRows; ++i)
            colsElements[i] = m.values[i][j];

        criteriaArray[j] = criteria(colsElements, m.nRows);
    }

    for (size_t i = 0; i < m.nCols - 1; ++i)
        for (size_t j = i + 1; j < m.nCols; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapColumns(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(int));
            }

    free(criteriaArray);
    free(colsElements);
}

bool isSquareMatrix(matrix const m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix const m1, matrix const m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (size_t i = 0; i < m1.nRows; ++i)
        for (size_t j = 0; j < m1.nCols; ++j)
            if (m1.values[i][j] != m2.values[i][j])
                return false;

    return true;
}

bool isEMatrix(matrix const m) {
    if (!isSquareMatrix(m))
        return false;

    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (i == j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0)
                return false;

    return true;
}

bool isSymmetricMatrix(matrix const m) {
    if (!isSquareMatrix(m))
        return false;

    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = i + 1; j < m.nCols; ++j)
            if (m.values[i][j] != m.values[j][i])
                return false;

    return true;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m))
        badSquareMatrix();

    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = i + 1; j < m.nCols; ++j)
            swapVoid(&m.values[i][j], &m.values[j][i], sizeof(int));
}

position getMinValuePos(matrix const m) {
    position min = {0, 0};
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }

    return min;
}

position getMaxValuePos(matrix const m) {
    position max = {0, 0};
    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[max.rowIndex][max.colIndex]) {
                max.rowIndex = i;
                max.colIndex = j;
            }

    return max;
}

matrix createMatrixFromArray(const int a[], const size_t nRows, const size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    size_t k = 0;
    for (size_t i = 0; i < nRows; ++i)
        for (size_t j = 0; j < nCols; ++j)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, const size_t nMatrices, const size_t nRows, const size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    size_t l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void swapRowsWithMaxAndMinValue(matrix m) {
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    if (minIndex.rowIndex != maxIndex.rowIndex)
        swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

void sortRowsByMaxElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElements(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
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

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = getSum(m.values[i], m.nCols);

    if (isUnique(criteriaArray, m.nRows))
        transposeSquareMatrix(m);
}

bool isMutuallyInverseMatrices(matrix const m1, matrix const m2) {
    matrix m3 = mulMatrices(m1,m2);
    bool result = isEMatrix(m3);

    freeMemMatrix(m3);

    return result;
}

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