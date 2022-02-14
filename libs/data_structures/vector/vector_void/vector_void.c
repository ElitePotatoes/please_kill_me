#include "vector_void.h"

void badAlloc() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

void emptyVector() {
    fprintf(stderr, "vector is empty");
    exit(1);
}

void badIndex(const size_t index) {
    fprintf(stderr, "IndexError: a[%d] is not exists", index);
    exit(1);
}

vectorVoid createVectorV(const size_t capacity, const size_t baseSizeType) {
    int *data = NULL;
    if (capacity > 0) {
        data = (void *) malloc(baseSizeType * capacity);
        if (data == NULL)
            badAlloc();
    }

    return (vectorVoid) {data, 0, capacity, baseSizeType};
}

void reserveV(vectorVoid *v, const size_t newCapacity) {
    v->capacity = newCapacity;
    if (v->capacity < v->size)
        v->size = v->capacity;

    if (newCapacity > 0) {
        v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
        if (v->data == NULL)
            badAlloc();
    }
    else
        v->data = NULL;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    reserveV(v, 0);
}

bool isEmptyVectorV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullVectorV(vectorVoid *v) {
    return v->size == v->capacity;
}

bool isZeroVectorV(vectorVoid *v) {
    return v->capacity == 0;
}

void getVectorValueV(vectorVoid *v, const size_t index, void *destination) {
    if (index > v->size)
        badIndex(index);

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, const size_t index, void *source) {
    if (index > v->size)
        badIndex(index);

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyVectorV(v))
        emptyVector();

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullVectorV(v) && !isZeroVectorV(v))
        reserveV(v, v->size * 2);
    else if (isZeroVectorV(v))
        reserveV(v, 1);

    setVectorValueV(v, v->size++, source);
}