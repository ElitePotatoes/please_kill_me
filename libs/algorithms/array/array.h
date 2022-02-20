#ifndef INC_ARRAY_H
#define INC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

//ввод массива a размера size.
void inputArray(int a[], size_t size);

//вывод массива a размера size.
void outputArray(const int a[], size_t size);

//возвращает значение первого вхождения элемента x в массиве a размера size при его наличии, иначе - size.
int linearSearch(const int a[], size_t size, int x);

//возвращает позицию вхождения элемента x в отсортированном массиве a размера size при его наличии, иначе - size.
int binarySearch(const int a[], size_t size, int x);

//вставка элемента со значением value в массив a размера size на позицию pos.
void insert(int a[], size_t *size, size_t pos, int value);

//добавление элемента value в конец массива a размера size.
void append(int a[], size_t *size, int value);

//удаление из массива a размера size элемента на позиции pos с сохранением порядка оставшихся элементов.
void deleteByPosSaveOrder(int a[], size_t *size, size_t pos);

//удаление из массива a размера size элемента на позиции pos без сохранения порядка оставшихся элементов
//размер массива a уменьшается на единицу.
void deleteByPosUnsaveOrder(int a[], size_t *size, size_t pos);

//возвращает значение ’истина’ если все элементы массива a размера size соответствует
//функции-предикату predicate иначе - ’ложь’.
int all(const int a[], size_t size, int (*predicate)(int));

//возвращает значение ’истина’ если хотя бы один элемент массива a размера size соответствует
//функции-предикату predicate, иначе - ’ложь’
int any(const int a[], size_t size, int (*predicate)(int));

//применяет функцию predicate ко всем элементам массива source размера size и сохраняет результат
//в массиве dest размера size.
void forEach(const int *source, int *dest, size_t size,
              const int (*predicate)(int));

//возвращает количество элементов массива a размера size удовлетворяющих функции-предикату predicate.
int countIf(const int a[], size_t size, int (*predicate)(int));

//удаляет из массива a размера size все элементы, удовлетворяющие функции-предикату deletePredicate,
//записывает в size новый размер массива.
void deleteIf(int a[], size_t *size, int(*deletePredicate)(int));

//сортирует массив a размера size по возрастанию.
void increasingSort(int a[], size_t size);

//сортирует массив a размера size по убыванию.
void decreasingSort(int a[], size_t size);

//сортировка вставками.
void insertionSort(int a[], size_t size);


//возвращает минимальное значение в массиве а размера size.
int getMin(const int a[], size_t size);

//возвращает максимальное значение в массиве а размера size.
int getMax(const int a[], size_t size);

//возвращает сумму элементов массива а размера size.
long long getSum(const int a[], size_t size);

//возвращает значение 'истина', если в массиве а размера size нет одинаковых элементов, иначе - 'ложь'.
bool isUnique(const int a[], size_t size);

//возвращает расстаояние до начала координат массива a размера size.
double getDistanceArray(const int a[], size_t size);

//возвращает количество классов эквивалентных индексов массива a размера size.
int countNUnique(long long a[], size_t size);

//возвращает значение 'истина', если все элементы массива a размера size расположены по возрастанию, иначе - 'ложь'.
bool isNonDescendingSorted(const int a[], size_t size);

//возвращает значение схождений элементов массива a размера size со значением value.
int countValues(const int a[], size_t size, int value);


//компанатор переменных типа int для qsort.
int compare_ints(const void *a, const void *b);

//компанатор переменных типа long long для qsort.
int cmp_long_long(const void *pa, const void *pb);

#endif //INC_ARRAY_H