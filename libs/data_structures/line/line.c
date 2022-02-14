#include "line.h"

void inputLine(line *line) {
    scanf("%lf %lf %lf", &line->a, &line->b, &line->c);
}

void outputLine(line line) {
    printf("%lf %lf %lf\n", line.a, line.b, line.c);
}

line getLineByPoints(point p1, point p2) {
    double a = p2.x - p2.x;
    double b = p2.y - p1.y;
    double c = -p1.x * (p2.y - p1.y) + p1.y * (p2.x - p1.x);

    return (line) {a, b, c};
}

void outputLineEquation(line line) {
    printf ("%+.2lfx %+.2lfy %+.2lf = 0", line.a, line.b, line.c);
}

bool isParallel(line l1, line l2) {
    return (l1.a * l2.b - l2.a * l1.b) < DBL_EPSILON;
}

bool isPerpendicular(line l1, line l2) {
    return (l1.a * l1.a + l2.b * l2.b) < DBL_EPSILON;
}

void inputLines(line lines[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        inputLine(&lines[i]);
}

void outputLines(line lines[], const size_t size) {
    for (size_t i = 0; i < size; ++i)
        outputLine(lines[i]);
}

bool hasParallelLines(line *lines, const size_t size) {
    for (size_t i = 0; i < size; ++i)
        for (size_t j = i + 1; j < size; ++j)
            if (isParallel(lines[i], lines[j]))
                return true;

    return false;
}

point getIntersectionPoint(line l1, line l2) {
    double x = (l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    double y = (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);

    return (point) {x, y};
}

void printIntersectionPoint(line l1, line l2) {
    if (!isParallel(l1, l2))
        outputPoint(getIntersectionPoint(l1, l2));
    else
        printf("No intersection point");
}
