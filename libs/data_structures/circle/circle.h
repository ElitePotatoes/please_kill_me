#ifndef MAIN_C_CIRCLE_H
#define MAIN_C_CIRCLE_H

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

#include "C:\Users\elite\CLionProjects\main\libs\data_structures\point\point.h"


typedef struct circle {
    point center;   //центр
    double r;       //радиус
} circle;

//ввод структуры circle.
void inputCircle(circle *a);

//ввод массива а структуры circle.
void inputCircles(circle a[], size_t size);

//вывод структуры circle.
void outputCircle(circle a);

//вывод массива a структуры circle.
void outputCircles(circle a[], size_t size);

//возвращает значение 'истина', если окружность с1 касается окружности с2 с внешней стороны, иначе - 'ложь'.
bool hasOneOuterIntersection(circle c1, circle c2);

//сортирует массив с поубыванию радиуса элементов структуры circle.
void decreasingCirclesByRadius(circle c[], size_t size);

//возвращает значение 'истина', если окружность с2 лежит в окружности с1, иначе - 'ложь'.
bool isInnerCircle(circle c1, circle c2);

//возвращает количество вложенных окружностей в окружность с порядковым номером index в массиве с размера size.
int countingInnerCircles(const circle c[], size_t size, size_t index);

//возвращает первую окружность из массива с размера size, у которой больше всего вложенных окружностей.
circle getCircleWithMaxCircles(const circle c[], size_t size);

#endif //MAIN_C_CIRCLE_H
