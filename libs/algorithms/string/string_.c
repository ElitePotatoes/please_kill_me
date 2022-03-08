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
    while (rbegin != rend && isspace(*rbegin))
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
            *beginDestination = *beginSource++;

    return beginDestination;
}

char *copyIfReverse_(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource)
        if (f(*rbeginSource))
            *beginDestination = *rbeginSource--;

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

bool getWordReverse(char *rbegin, const char *rend, wordDescriptor *word) { //__aabbb__\0
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

    *(--startStringBuffer) = '\0';
}

/********************************************************** 6 *********************************************************/

bool isOrderedWords(char *begin) {
    wordDescriptor w1;
    if (!getWord(begin, &w1))
        return true;

    begin = w1.end;
    wordDescriptor w2;
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

int getCountWords(char *begin) {
    wordDescriptor readWord;

    int counter = 0;
    while (getWord(begin, &readWord)) {
        ++counter;

        begin = readWord.end;
    }

    return counter;
}

void getBagOfWords(bagOfWords *bag, char *begin) {
    bag->size = 0;
    wordDescriptor readWord;
    while (getWord(begin, &readWord)) {
        bag->words[bag->size++] = readWord;

        begin = readWord.end;
    }
}

void outputWord(wordDescriptor w) {
    while (w.begin <= w.end)
        printf("%c", *w.begin++);

    printf("\n");
}

void outputReverseWords(bagOfWords *bag) {
    for (size_t i = bag->size; i >= 0; --i)
        outputWord(bag->words[i]);
}

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
    while (getWord(begin, &readWord)) {
        if (isPalindromeWord(readWord))
            counter++;

        begin = readWord.end;
    }

    return counter;
}

/********************************************************** 9 *********************************************************/

bool isEmptyString(char *begin) {
    return (strlen_(begin) == 0) ? true : false;
}

char *getInterleavedString(char *fbegin, char *sbegin) {
    char *startStringBuffer;
    if (isEmptyString(fbegin) && isEmptyString(sbegin))
        return startStringBuffer;

    wordDescriptor w1, w2;
    bool isW1Found, isW2Found;
    while (isW1Found = getWord(fbegin, &w1), isW2Found = getWord(sbegin, &w2), isW1Found || isW2Found) {
        if (isW1Found) {
            startStringBuffer = copy_(w1.begin, w1.end, startStringBuffer);
            *startStringBuffer++ = ' ';

            fbegin = w1.end;
        }

        if (isW2Found) {
            startStringBuffer = copy_(w2.begin, w2.end, startStringBuffer);
            *startStringBuffer++ = ' ';

            sbegin = w2.end;
        }
    }

    *(--startStringBuffer) = '\0';

    return startStringBuffer;
}

/********************************************************* 10 *********************************************************/

void reverseString(char *begin) {
    wordDescriptor readWord;

    char *end = getEndOfString(begin);

    char *endStringBuffer = copy_(begin, end, stringBuffer);
    char *search = endStringBuffer - 1;
    while (getWordReverse(search, stringBuffer - 1, &readWord)) {
        begin = copy_(readWord.begin, readWord.end, begin);
        *begin++ = ' ';

        search -= readWord.end - readWord.begin + 1;
    }

    *(--begin) = '\0';
}

/********************************************************* 11 *********************************************************/

char *findA(char *begin, const char *end) {
    while (begin != end && *begin != 'a' && *begin != 'A')
        begin++;

    return begin;
}

void printWordBeforeFirstWordWithA(char *begin) {
    if (getCountWords(begin) == 0) {
        fprintf(stderr, "String not contains words\n");
        exit(1);
    }

    char *end = getEndOfString(begin);
    if (findA(begin, end) == end) {
        fprintf(stderr, "String not contains A\n");
        exit(1);
    }

    wordDescriptor previousWord;
    getWord(begin, &previousWord);
    char *searchA = findA(previousWord.begin, previousWord.end);
    if (*searchA != 'a' && *searchA != 'A') {
        fprintf(stderr, "First word contains A\n");
        exit(1);
    }

    begin = previousWord.end;

    wordDescriptor readWord;
    while (getWord(begin, &readWord)) {
        searchA = findA(readWord.begin, readWord.end);
        if (*searchA == 'a' || *searchA == 'A') {
            printf("This word before first word with A -> ");
            outputWord(previousWord);

            return;
        }

        previousWord.begin = readWord.begin;
        previousWord.end = readWord.end;

        begin = readWord.end;
    }
}

/********************************************************* 12 *********************************************************/

void wordDescriptorToString(wordDescriptor word, char *destination) {
    char *end = copy_(word.begin, word.end, destination);
    *end = '\0';
}

wordDescriptor lastWordInFirstStringInSecondString(char *fbegin, char *sbegin) {
    bagOfWords fbag;
    getBagOfWords(&fbag, fbegin);

    bagOfWords sbag;
    getBagOfWords(&sbag, sbegin);

    wordDescriptor word;
    for (size_t i = fbag.size; i >= 0; --i)
        for (size_t j = 0; j < sbag.size; ++j)
            if (areWordsEqual(fbag.words[i], sbag.words[i]) == 0) {
                word.begin = fbag.words[i].begin;
                word.end = fbag.words[i].end;

                return word;
            }

    //А что возвращать в ином случае?
}

/********************************************************* 13 *********************************************************/

bool stringContainsSameWords(char *begin) {
    bagOfWords bag;
    getBagOfWords(&bag, begin);

    for (size_t i = 0; i < bag.size; ++i)
        for (size_t j = i + 1; j < bag.size; ++j)
            if (areWordsEqual(bag.words[i], bag.words[j]) == 0)
                return true;

    return false;
}

/********************************************************* 14 *********************************************************/

/********************************************************* 15 *********************************************************/

void getStringWithoutSameLastWord(char *begin) { //делай предыдущие задания, олух.
    char *end = getEndOfString(begin);

    wordDescriptor needDelete;
    getWordReverse(end - 1, begin - 1, &needDelete);

    end -= needDelete.end - needDelete.begin - 1;
    *end = '\0';

    wordDescriptor readWord;
    char *endStringBuffer = copy_(begin, end, stringBuffer);
    while (getWord(endStringBuffer, &readWord))
        if (areWordsEqual(readWord, needDelete) != 0) {
            begin = copy_(readWord.begin, readWord.end, begin);

            *begin++ = ' ';
        }

    *(--begin) = '\0';
}

/********************************************************* 16 *********************************************************/

/********************************************************* 17 *********************************************************/

void deletePalindromeWords(char *begin) {
    wordDescriptor readWord;

    char *end = getEndOfString(begin);
    char *endStringBuffer = copy_(begin, end, stringBuffer);
    while (getWord(endStringBuffer, &readWord))
        if (!isPalindromeWord(readWord)) {
            begin = copy_(readWord.begin, readWord.end, begin);

            *begin++ = ' ';
        }

    *(--begin) = '\0';
}

/********************************************************* 18 *********************************************************/

void addWordsToSmallerString_Core(char *fbegin, char *sbegin, size_t fSize, size_t sSize) { //делай предыдущие задания, олух.
    wordDescriptor readWord;

    size_t different = fSize - sSize;
    char *search = getEndOfString(fbegin) - 1;
    while (different--) {
        getWordReverse(search, fbegin - 1, &readWord);

        search -= readWord.end - readWord.begin + 1;
    }

    char *endSbegin = getEndOfString(sbegin);
    *endSbegin++ = ' ';

    *copy_(readWord.begin, getEndOfString(fbegin), endSbegin) = '\0';
}

void addWordsToSmallerString(char *fbegin, char *sbegin) {
    size_t fSize = getCountWords(fbegin);
    size_t sSize = getCountWords(sbegin);

    if (fSize == sSize)
        return;

    if (fSize > sSize)
        addWordsToSmallerString_Core(fbegin, sbegin, sSize, fSize);
    else
        addWordsToSmallerString_Core(sbegin, fbegin, fSize, sSize);
}

/********************************************************* 19 *********************************************************/

