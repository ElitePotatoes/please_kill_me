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
    while (*begin != '\0' && !isspace(*begin) && *begin != ',')
        begin++;

    return begin;
}

char *findNonSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return ++rbegin;
}

char *findSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return (unsigned char) *lhs - (unsigned char) *rhs;
}

char *copy_(char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
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

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

void removeAllSpaces(char *begin) {
    char *destination = copyIf_(begin, getEndOfString(begin), begin, isspace);
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

void removeAdjacentEqualLetters(char *begin) {
    char *equal = begin;
    while (*equal != '\0') {
        if (isalpha(*begin) && equal != begin && *equal != '\0')
            *begin++ = *equal;

        equal++;
    }

    *begin = '\0';
}

void removeExtraSpaces(char *begin) {
    char *equal = begin;
    while (*equal != '\0') {
        if (isspace(*begin) && equal != begin && *equal != '\0')
            *begin++ = *equal;

        equal++;
    }

    *begin = '\0';
}

/********************************************************** 3 *********************************************************/

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace_(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace_(word->begin);

    return true;
}

bool getWordReverse(char *rbegin, const char *rend, wordDescriptor *word) {
    word->begin = findNonSpaceReverse_(rbegin, rend);
    if (word->begin == rend)
        return false;

    word->end = findNonSpaceReverse_(word->begin, rend);

    return true;
}

void digitToStart(wordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isdigit);
    copyIfReverse_(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void reverseDigitToStart(wordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse_(endStringBuffer - 1, stringBuffer - 1, word.begin, isdigit);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToEnd(wordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

void reverseDigitToEnd(wordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIfReverse_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource)
        memcpy(beginDestination, rbeginSource--, sizeof(char));

    return beginDestination;
}

void reverseWord(wordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    copyReverse(endStringBuffer, stringBuffer, word.begin);
}

void reverseWords(char *begin) {
    wordDescriptor word;
    while (getWord(begin, &word)) {
        reverseWord(word);

        begin = word.end;
    }
}

/********************************************************** 4 *********************************************************/

char spaceInsteadDigits(char *begin) {
    char *endSource = getEndOfString(begin);
    char *startStringBuffer = stringBuffer;
    char *endStringBuffer = copy_(begin, endSource, stringBuffer);
    *endStringBuffer = '\0';

    while (*startStringBuffer != '\0') {
        if (isalpha(*startStringBuffer))
            *begin++ = *startStringBuffer;
        else if (isdigit(*startStringBuffer)) {
            unsigned char a = *startStringBuffer - CODE_ASCII;
            while (a--)
                *begin++ = ' ';
        }

        startStringBuffer++;
    }

    *begin = '\0';
}

/********************************************************** 5 *********************************************************/

int areWordsEqual(wordDescriptor w1, wordDescriptor w2) {
    return strcmp_(w1.begin, w2.begin);
}

void replace(char *begin, char *replacement, char *necessary) {
    size_t sizeW1 = strlen_(replacement);
    size_t sizeW2 = strlen_(necessary);
    wordDescriptor word1 = {replacement, replacement + sizeW1};
    wordDescriptor word2 = {necessary, necessary + sizeW2};

    char *startStringBuffer;
    if (sizeW1 >= sizeW2)
        startStringBuffer = begin;
    else {
        copy_(begin, getEndOfString(begin), stringBuffer);
        startStringBuffer = begin;
    }

    wordDescriptor readWord;
    while (getWord(begin, &readWord)) {
        if (areWordsEqual(word1, readWord) != 0)
            startStringBuffer = copy_(word2.begin, word2.end, startStringBuffer);
        else
            startStringBuffer = copy_(readWord.begin, readWord.end, startStringBuffer);

        *startStringBuffer++ = ' ';
        begin = readWord.end;
    }

    *startStringBuffer = '\0';
}

/********************************************************** 6 *********************************************************/

bool isOrderedWords(char *begin) {
    wordDescriptor w1;
    wordDescriptor w2;

    if (!getWord(begin, &w1))
        return true;

    begin = w1.end;
    while (getWord(begin, &w2)) {
        if (areWordsEqual(w1, w2) > 0)
            return false;

        begin = w2.end;

        w1.begin = w2.begin;
        w1.end = w2.end;
    }

    return true;
}

/********************************************************** 7 *********************************************************/

/*void outputBagOfWords(bagOfWords *bag, char *begin) {
    while ()
}*/

/********************************************************** 8 *********************************************************/

bool isPalindromeWord(wordDescriptor w) {
    while (w.begin <= w.end) {
        if (*w.begin != *w.end)
            return false;

        w.begin++; w.end++;
    }

    return true;
}

int getCountPalindromeWords(char *begin) {
    wordDescriptor readWord;

    int counter = 0;
    while (getWord(begin, &readWord))
        if (isPalindromeWord(readWord))
            counter++;

    return counter;
}

/********************************************************** 9 *********************************************************/