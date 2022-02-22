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

void needNewSquare() {
    fprintf(stderr, "Davai po novoi chert`");
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

long long findSumOfMaxesOfPseudoDiagonal(matrix const m) {
    int size = m.nCols + m.nRows - 1;
    int sumArray[size];
    for (size_t i = 0; i < size; ++i)
        sumArray[i] = 0;

    for (size_t i = 0; i < m.nRows; ++i) {
        for (size_t j = 0; j < m.nCols; ++j) {
            if (i == j)
                continue;

            sumArray[j - i + 2] = max2(sumArray[j - i + 2], m.values[i][j]);
        }
    }

    return getSum(sumArray, size);
}

int getMinInMatrixRow(matrix const m, const size_t rowIndex, const size_t leftPos, const size_t rightPos) {
    int minElement = m.values[rowIndex][leftPos];
    for (size_t j = leftPos + 1; j < rightPos; ++j)
        minElement = min2(minElement, m.values[rowIndex][j]);

    return minElement;
}

int getMinInArea(matrix const m) {
    position p = getMaxValuePos(m);

    int minElement = m.values[p.rowIndex][p.colIndex];
    if (p.rowIndex == 0)
        return minElement;

    size_t left = p.colIndex;
    size_t right = p.colIndex;
    for (size_t i = p.rowIndex - 1; i >= 0; --i) {
        if (right < m.nCols - 1)
            right++;

        if (left > 0)
            left--;

        minElement = min2(minElement, getMinInMatrixRow(m, i, left, right));
    }

    return minElement;
}

double getDistanceArray(const int a[], const size_t size) {
    double distance = 0;
    for (size_t i = 0; i < size; ++i)
        distance += pow(a[i], 2);

    return sqrt(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *criteriaArray = (float *) malloc(sizeof(float) * m.nRows);
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 0; i < m.nRows - 1; ++i)
        for (size_t j = i + 1; j < m.nRows; ++j)
            if (criteriaArray[i] > criteriaArray[j]) {
                swapRows(m, i, j);
                swapVoid(&criteriaArray[i], &criteriaArray[j], sizeof(float));
            }

    free(criteriaArray);
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistanceArray);
}

int countEqClassesByRowsSum(matrix const m) {
    long long criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = getSum(m.values[i], m.nCols);

    return countNUnique(criteriaArray, m.nRows);
}

int getNSpecialElement(matrix const m) {
    int criteriaArray[m.nCols];
    int subArray[m.nRows];
    for (size_t j = 0; j < m.nCols; ++j) {
        for (size_t i = 0; i < m.nRows; ++i)
            subArray[i] = m.values[i][j];

        criteriaArray[j] = getSum(subArray, m.nRows);
    }
                                                    //{17, 10, 12, 13}
    int counter = 0;
    for (size_t j = 0; j < m.nCols; ++j)
        for (size_t i = 0; i < m.nRows; ++i)
            if (criteriaArray[j] - m.values[i][j] < m.values[i][j])
                counter++;

    return counter;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2)
        needNewSquare();

    position min = getMinValuePos(m);

    int subArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        subArray[i] = m.values[i][min.colIndex];

    for (size_t j = 0; j < m.nCols; ++j)
        m.values[m.nRows - 2][j] = subArray[j];
}

bool hasAllNonDescendingRows(matrix const m) {
    for (size_t i = 0; i < m.nRows; ++i)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix ms[], const size_t nMatrix) {
    int counter = 0;
    for (size_t i = 0; i < nMatrix; ++i)
        counter += hasAllNonDescendingRows(ms[i]);

    return counter;
}

int countZeroRows(matrix const m) {
    int counterZero = 0;
    for (size_t i = 0; i < m.nRows; ++i)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            counterZero++;

    return counterZero;
}

void printMatrixWithMaxZeroRows(matrix ms[], const size_t nMatrix) {
    int *matrixWithZeroRows = (int *) malloc(sizeof(int) * nMatrix);
    for (size_t i = 0; i < nMatrix; ++i)
        matrixWithZeroRows[i] = countZeroRows(ms[i]);

    int maxZero = getMax(matrixWithZeroRows, nMatrix);
    for (size_t i = 0; i < nMatrix; ++i)
        if (matrixWithZeroRows[i] == maxZero)
            outputMatrix(ms[i]);

    free(matrixWithZeroRows);
}

int absoluteNorm(matrix const m) {
    int norm = abs(m.values[0][0]);
    for (size_t i = 0; i < m.nRows; ++i) {
        int max = abs(getMax(m.values[i], m.nCols));
        if (norm < max)
            norm = max;
    }

    return norm;
}

void printMatricesWithMinNorm(matrix ms[], const size_t nMatrix) {
    int normInMatrices[nMatrix];
    for (size_t i = 0; i < nMatrix; ++i)
        normInMatrices[i] = absoluteNorm(ms[i]);

    int min = getMin(normInMatrices, nMatrix);
    for (size_t i = 0; i < nMatrix; i++)
        if (normInMatrices[i] == min)
            outputMatrix(ms[i]);
}