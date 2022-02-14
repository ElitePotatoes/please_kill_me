#ifndef MAIN_C_VECTOR_VOID_H
#define MAIN_C_VECTOR_VOID_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct vectorVoid {
    void *data;             //указатель на нулевой элемент вектора
    size_t size;            //размер вектора
    size_t capacity;        //вместимость вектора
    size_t baseTypeSize;    //размер базового типа
} vectorVoid;

//возвращает структуру-дескриптор вектор из capacity значений и размером типа baseTypeSize.
vectorVoid createVectorV(size_t capacity, size_t baseSizeType);

//изменяет количество памяти, выделенное под хранение элементов вектора v.
void reserveV(vectorVoid *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память вектора v.
void clearV(vectorVoid *v);

//освобождает память, выделенную под неиспользуемые элементы вектора v.
void shrinkToFitV(vectorVoid *v);

//освобождает память, выделенную вектору v.
void deleteVectorV(vectorVoid *v);

//возврашает 'истина', если вектор v пустой, иначе - 'ложь'.
bool isEmptyVectorV(vectorVoid *v);

//возврашает 'истина', если вектор v полный, иначе - 'ложь'.
bool isFullVectorV(vectorVoid *v);

//возврашает 'истина', если вектор v нулевой, иначе - 'ложь'.
bool isZeroVectorV(vectorVoid *v);

//записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

//записывает на index-ый элемент вектора v значение, расположенное по адресу source.
void setVectorValueV(vectorVoid *v, size_t index, void *source);

//удаляет последний элемент из вектора v.
void popBackV(vectorVoid *v);

//добавляет элемент по адресу source в конец вектора v.
void pushBackV(vectorVoid *v, void *source);

#endif //MAIN_C_VECTOR_VOID_H