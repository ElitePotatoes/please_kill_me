#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          //указатель на элементы вектора
    size_t size;        //размер вектора
    size_t capacity;    //вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из capacity значений.
vector createVector(size_t capacity);

//изменяет количество памяти, выделенное под хранение элементов вектора v.
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память вектора v.
void clear(vector *v);

//освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору v.
void deleteVector(vector *v);

//возврашает 'истина', если вектор v пустой, иначе - 'ложь'.
bool isEmptyVector(vector *v);

//возврашает 'истина', если вектор v полный, иначе - 'ложь'.
bool isFullVector(vector *v);

//возврашает 'истина', если вектор v нулевой, иначе - 'ложь'.
bool isZeroVector(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t index);

//добавляет элемент x в конец вектора v.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора v.
void popBack(vector *v);

//возвращает указатель на index-ый элемент вектора v.
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора v.
int *back(vector *v);

//возвращает указатель на нулевой элемент вектора v.
int *front(vector *v);

#endif //COURSE_VECTOR_H