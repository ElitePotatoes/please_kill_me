#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find_(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace_(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace_(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return ++rbegin;
}

char *findSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin--))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (lhs == rhs) {
        if (*lhs == '\0')
            return 0;

        lhs++;
        rhs++;
    }

    return (lhs < rhs) ? -1 : 1;
}

char *copy_(char *beginSource, const char *endSource, char *beginDestination) {
    while (beginSource != endSource)
        memcpy(beginDestination, beginSource++, sizeof(char));

    return beginDestination;
}

char *copyIf_(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource)
        if (f(*beginSource))
            memcpy(beginDestination, beginSource++, sizeof(char));

    return beginDestination;
}

char *copyIfReverse_(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f(*rbeginSource))
            memcpy(beginDestination, rbeginSource--, sizeof(char));

    return beginDestination;
}

/********************************************************** 1 *********************************************************/

char *getEndOfString_(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

void removeAllSpaces(char *begin) {
    char *endSource = getEndOfString_(begin);
    char *destination = copyIf_(begin, endSource, begin, isspace);
    *destination = '\0';
}

//TODO РАЗОБРАТЬСЯ В ВЫВОДЕ ОШИБОК, ВМЕСТЕ С МАКРОПОДСТАНОВКОЙ
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

/********************************************************** 2 *********************************************************/

char *removeSameLetters(char *begin) {
    char *equal = begin++;
    while (begin == equal && *equal != '\0')
        equal++;

    memcpy(--equal, begin, sizeof(char));

    return ++equal;
}

void removeAdjacentEqualLetters(char *begin) {
    while (*begin != '\0')
        if (!isspace(*begin))
            removeSameLetters(begin);

    *begin = '\0';
}

void removeExtraSpaces(char *begin) {
    while (*begin != '\0')
        if (isspace(*begin))
            removeSameLetters(begin);

    *begin = '\0';
}

/********************************************************** 3 *********************************************************/
/********************************************************** 4 *********************************************************/
/********************************************************** 5 *********************************************************/
/********************************************************** 6 *********************************************************/
/********************************************************** 7 *********************************************************/