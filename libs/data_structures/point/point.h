#ifndef MAIN_C_POINT_H
#define MAIN_C_POINT_H

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

#include "C:\Users\elite\CLionProjects\main\libs\algorithms\algorithm.h"

typedef struct point {
    double x;   //координата х
    double y;   //координата y
} point;

//ввод структуры point.
void inputPoint(point *p);

//вывод структуры point.
void outputPoint(point p);

//ввод массива структуры point.
void inputPoints(point p[], size_t size);

//вывод массива структуры point.
void outputPoints(point p[], size_t size);

//возвращает координаты точки, которая находится посередине между точками p1 и p2.
point getMiddlePoint(point p1, point p2);

//возвращает значение 'истина', если координаты точек p1 и p2 совпадают, иначе - 'ложь'.
bool isEqualPoint(point p1, point p2);

//возвращает 1, если координаты точки p3 соовпадают с координатами точки, расположенненой между координатами точек p1 и p2, иначе 0.
bool isPointBetween(point p1, point p2, point p3);

//обменивает значения координат точки p.
void swapCoordinates(point *p);

//обменивает значения координат точек p1 и p2.
void swapPoints(point *p1, point *p2);

//возвращает значение расстояния между точками p1 и p2.
double getDistance_(point p1, point p2);

//возврашает 0, если координаты координаты точки a и b равны; возвращает -1, если координата х точки a меньше координаты х точки b, или координаты х точек равны, а координата у точки а меньше координаты х точки b, иначе 0.
int compare_points(const point *a, const point *b);

//возврашает 0, если расстояние от точки а и точки b до начала координат равны; возвращает -1, если расстояние от точки а до начала координат меньше точки b до начала координат, иначе 0.
int compare_distance(const point *a, const point *b);

#endif //MAIN_C_POINT_H
