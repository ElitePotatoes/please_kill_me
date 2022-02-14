#include "matrix.h"

void badIndex() {
    fprintf(stderr, "bad index\n");
    exit(1);
}

void badSquareMatrix() {
    fprintf(stderr, "isn't square matrix\n");
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
    int criteriaArray[m.nRows];
    for (size_t i = 0; i < m.nRows; ++i)
        criteriaArray[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 0; i < m.nRows; ++i) {
        size_t maxIndex = i;
        for (size_t j = i; j < m.nRows; j++)
            if (criteriaArray[j] > criteriaArray[maxIndex])
                maxIndex = j;

        swapVoid(&criteriaArray[maxIndex], &criteriaArray[i], sizeof(int));
        swapRows(m, i, maxIndex);
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArray[m.nCols];
    int column[m.nRows];
    for (size_t i = 0; i < m.nCols; ++i) {
        for (size_t j = 0; i < m.nRows; ++i)
            column[i] = m.values[i][j];

        criteriaArray[i] = criteria(column, m.nRows);
    }

    for (size_t i = 0; i < m.nCols; ++i) {
        size_t maxIndex = i;
        for (size_t j = i; j < m.nCols; j++)
            if (criteriaArray[j] > criteriaArray[maxIndex])
                maxIndex = j;

        swapVoid(&criteriaArray[maxIndex], &criteriaArray[i], sizeof(int));
        swapColumns(m, i, maxIndex);
    }
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
            if (i == j && m.values[i][j] != 1 || m.values[i][j] != 0)
                return false;

    return true;
}

bool isSymmetricMatrix(matrix const m) {
    if (!isSquareMatrix(m))
        return false;

    for (size_t i = 0; i < m.nRows; ++i)
        for (size_t j = 0; j < m.nCols; ++j)
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