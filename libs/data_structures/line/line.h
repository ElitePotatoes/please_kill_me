#ifndef MAIN_C_LINE_H
#define MAIN_C_LINE_H

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

typedef struct line {
    double a;   //коэфициент а уравнения прямой
    double b;   //коэфициент b уравнения прямой
    double c;   //коэфициент c уравнения прямой
} line;

//ввод структуры line.
void inputLine(line *line);

//вывод структуры line.
void outputLine(line line);

//возвращает коэффициенты прямой по координатам точек p1, p2.
line getLineByPoints(point p1, point p2);

//вывод уранения прямой line.
void outputLineEquation(line line);

//возвращает значение 'истина', если прямые l1 и l2 параллельны, иначе - 'ложь'.
bool isParallel(line l1, line l2);

//возвращает значение 'истина', если прямые l1 и l2 перпендикулярны, иначе - 'ложь'.
bool isPerpendicular(line l1, line l2);

//ввод массива структуры line.
void inputLines(line lines[], size_t size);

//ввод массива структуры line.
void outputLines(line lines[], size_t size);

//возвращает значение 'истина', если среди элементов массива lines имеются параллельные линии, иначе - 'ложь'.
bool hasParallelLines(line *lines, size_t size);

//возвращает точку пересечения двух линий l1 и l2.
point getIntersectionPoint(line l1, line l2);

//вывод точки пересечения двух линий l1 и l2, если таковая имеется, иначе "Нет точки пересечения".
void printIntersectionPoint(line l1, line l2);

#endif //MAIN_C_LINE_H
