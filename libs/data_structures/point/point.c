#include "point.h"

void inputPoint(point *p) {
    scanf("%lf %lf", &p->x, &p->y);
}

void outputPoint(point p) {
    printf("(%.3lf; %.3lf)\n", p.x, p.y);
}

void inputPoints(point p[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        inputPoint(&p[i]);
}

void outputPoints(point p[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        outputPoint(p[i]);
}

point getMiddlePoint(point p1, point p2) {
    double middleX = (p2.x - p1.x) / 2;
    double middleY = (p2.y - p1.y) / 2;

    return (point) {middleX, middleY};
}

bool isEqualPoint(point p1, point p2) {
    return (p1.x - p2.x) < DBL_EPSILON && (p1.y - p2.y) < DBL_EPSILON;
}

bool isPointBetween(point p1, point p2, point p3) {
    point middlePoint = getMiddlePoint(p1, p2);

    return isEqualPoint(middlePoint, p3);
}

void swapCoordinates(point *p) {
    swapVoid(&p->x, &p->y, sizeof(double));
}

void swapPoints(point *p1, point *p2) {
    swapVoid(p1, p2, sizeof(point));
}

double getDistance_(point p1, point p2) {
    double middleX = p2.x - p1.x;
    double middleY = p2.y - p1.y;

    return sqrt(pow(middleX, 2) + pow(middleY, 2));
}

int compare_points(const point *a, const point *b) {
    point *p1 = (point *) a;
    point *p2 = (point *) b;
    if (isEqualPoint(*p1, *p2))
        return 0;
    else if (p1->x < p2->x || p1->x == p2->x && p1->y < p2->y)
        return -1;
    else
        return 1;
}

int compare_distance(const point *a, const point *b) {
    point zeroPoint = {0, 0};
    point *p1 = (point *) a;
    point *p2 = (point *) b;
    double distance1 = getDistance_(*p1, zeroPoint);
    double distance2 = getDistance_(*p2, zeroPoint);
    if (distance1 == distance2)
        return 0;
    else if (distance1 < distance2)
        return -1;
    else
        return 1;
}