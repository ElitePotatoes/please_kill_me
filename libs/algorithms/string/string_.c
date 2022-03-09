#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end)
        end++;

    return end - begin;
}

char *find_(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace_(char *begin) {
    while (*begin && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace_(char *begin) {
    while (*begin && !isspace(*begin) && *begin != ',')
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
    while (*begin)
        begin++;

    return begin;
}

void removeAllSpaces(char *begin) {
    char *destination = copyIf_(begin, getEndOfString(begin), begin, isspace);
    *destination = '\0';
}

/********************************************************** 2 *********************************************************/

void removeAdjacentEqualLetters(char *begin) {
    char *equal = begin;
    while (*equal) {
        if (isalpha(*begin) && equal != begin)
            *begin++ = *equal;

        equal++;
    }

    *begin = '\0';
}

void removeExtraSpaces(char *begin) {
    char *equal = begin;
    while (*equal) {
        if (isspace(*begin) && equal != begin)
            *begin++ = *equal;

        equal++;
    }

    *begin = '\0';
}

/********************************************************** 3 *********************************************************/

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace_(beginSearch);
    if (*word->begin)
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
    char *startStringBuffer = stringBuffer;
    char *endStringBuffer = copy_(begin, getEndOfString(begin), stringBuffer);
    *endStringBuffer = '\0';

    while (*startStringBuffer) {
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
    wordDescriptor changeWord = {replacement, replacement + sizeW1};
    wordDescriptor needful = {necessary, necessary + sizeW2};

    char *endStringBuffer;
    char *end = getEndOfString(begin);
    if (sizeW1 < sizeW2) {
        endStringBuffer = copy_(begin, end, stringBuffer);
        *endStringBuffer = '\0';
    }

    wordDescriptor readWord;
    while (getWord(begin, &readWord)) {
        if (areWordsEqual(changeWord, readWord) != 0)
            end = copy_(needful.begin, needful.end, begin);
        else
            end = copy_(readWord.begin, readWord.end, begin);

        begin = readWord.end;
    }

    *(--end) = '\0';
}

/********************************************************** 6 *********************************************************/

bool isOrderedWords(char *begin) {
    wordDescriptor previousWord;
    if (!getWord(begin, &previousWord))
        return true;

    begin = previousWord.end;

    wordDescriptor readWord;
    while (getWord(begin, &readWord)) {
        if (areWordsEqual(previousWord, readWord) > 0)
            return false;

        begin = readWord.end;
        previousWord = readWord;
    }

    return true;
}

/********************************************************** 7 *********************************************************/

int getCountWords(char *begin) {
    wordDescriptor readWord;

    int counter = 0;
    while (getWord(begin, &readWord)) {
        counter++;

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

bool isEmptyStringWithoutWords(char *begin) {
    return (isalpha(*findNonSpace_(begin))) ? true : false;
}

char *getInterleavedString(char *fbegin, char *sbegin) {
    if (isEmptyStringWithoutWords(fbegin) && isEmptyStringWithoutWords(sbegin))
        return stringBuffer;

    wordDescriptor w1, w2;
    bool isW1Found, isW2Found;
    char *endStringBuffer;
    while (isW1Found = getWord(fbegin, &w1), isW2Found = getWord(sbegin, &w2),
            isW1Found || isW2Found) {
        if (isW1Found) {
            endStringBuffer = copy_(w1.begin, w1.end, stringBuffer);
            *endStringBuffer++ = ' ';

            fbegin = w1.end;
        }

        if (isW2Found) {
            endStringBuffer = copy_(w2.begin, w2.end, stringBuffer);
            *endStringBuffer++ = ' ';

            sbegin = w2.end;
        }
    }

    *(--endStringBuffer) = '\0';

    return stringBuffer;
}

/********************************************************* 10 *********************************************************/

void reverseString(char *begin) {
    copy_(begin, getEndOfString(begin), stringBuffer);

    bagOfWords bag;
    getBagOfWords(&bag, stringBuffer);
    while (bag.size >= 0) {
        copy_(bag.words[bag.size].begin, bag.words[bag.size].end, begin);

        *begin++ = ' ';
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

wordDescriptor lastSameWordInFirstAndSecondString(char *fbegin, char *sbegin) {
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

    fprintf(stderr,"Strings not contains same word\n");
    exit(1);
}

/********************************************************* 13 *********************************************************/

bool stringContainsSameWords(char *begin) {
    bagOfWords bag;
    getBagOfWords(&bag, begin);

    for (size_t i = 0; i < bag.size - 1; ++i)
        for (size_t j = i + 1; j < bag.size; ++j)
            if (areWordsEqual(bag.words[i], bag.words[j]) == 0)
                return true;

    return false;
}

/********************************************************* 14 *********************************************************/

char compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;
    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}

bool stringContainsSameWordsWithSameSymbols(char *begin) {
    copy_(begin, getEndOfString(begin), stringBuffer);

    bagOfWords bag;
    getBagOfWords(&bag, stringBuffer);
    for (size_t i = 0; i < bag.size; ++i)
        qsort(bag.words[i].begin, bag.words[i].end - bag.words[i].begin, sizeof(char), compare_char);

    for (size_t i = 0; i < bag.size - 1; ++i)
        for (size_t j = i + 1; j < bag.size; ++j)
            if (areWordsEqual(bag.words[i], bag.words[j]) == 0)
                return true;

    return false;
}

/********************************************************* 15 *********************************************************/

void getStringWithoutSameLastWord(char *begin) {
    char *end = getEndOfString(begin);

    char *endBufferString = copy_(begin, getEndOfString(begin), stringBuffer);
    *endBufferString = '\0';

    wordDescriptor needDelete;
    if (!getWordReverse(endBufferString - 1, stringBuffer - 1, &needDelete))
        return; //Умирает на пустой строке: либо возвращать её (-), либо вносить оставшиеся тело функции в if (+-).

    wordDescriptor nextWord;
    char *startBufferString = stringBuffer;
    while (getWord(startBufferString, &nextWord)) {
        if (!areWordsEqual(nextWord, needDelete)) {
            end = copy_(nextWord.begin, nextWord.end, begin);

            end++;
        }

        startBufferString = nextWord.end;
    }

    *(--end) = '\0';
}

/********************************************************* 16 *********************************************************/

wordDescriptor firstWordBeforeSameInFirstAndSecondString(char *fbegin, char *sbegin) {
    bagOfWords fbag;
    getBagOfWords(&fbag, fbegin);

    bagOfWords sbag;
    getBagOfWords(&sbag, sbegin);

    wordDescriptor word;
    for (size_t i = 0; i < fbag.size; --i)
        for (size_t j = 0; j < sbag.size; ++j)
            if (areWordsEqual(fbag.words[i], sbag.words[i]) == 0) {
                if (i >= 1)
                    return fbag.words[i - 1];
                else {
                    fprintf(stderr,"String not contains word before first entry\n");
                    exit(1);
                }
            }

    fprintf(stderr,"Strings not contains same word\n");
    exit(1);
}

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

void addWordsToSmallerString_Core(char *fbegin, char *sbegin, bagOfWords fbag, bagOfWords sbag) {
    /*wordDescriptor readWord;
    size_t different = fSize - sSize;
    char *endF = getEndOfString(fbegin);

    char *endS = getEndOfString(sbegin);
    *endS++ = ' ';

    while (different--) {
        getWordReverse(endF - 1, fbegin - 1, &readWord);
        endS = copy_(readWord.begin, readWord.end, sbegin);
        endS++;

        endF -= readWord.end - readWord.begin + 1;
    }

    *endS = '\0';*/

    /*char *s_end = getEndOfString(sbegin);
    *s_end++ = ' ';

    for (size_t i = sbag.size; i < fbag.size - 1; ++i) {
        s_end = copy_(fbag.words[sbag.size + 1].begin, fbag.words[sbag.size + 1].end, sbegin);
        sbag.size++;

        s_end++;
    }

    *(--s_end) = '\0';*/
}

void addWordsToSmallerString(char *fbegin, char *sbegin) {
    bagOfWords fbag;
    getBagOfWords(&fbag, fbegin);

    bagOfWords sbag;
    getBagOfWords(&sbag, sbegin);

    if (fbag.size > sbag.size)
        addWordsToSmallerString_Core(fbegin, sbegin, fbag, sbag);
    else if (fbag.size < sbag.size)
        addWordsToSmallerString_Core(sbegin, fbegin, sbag, fbag);
}

/********************************************************* 19 *********************************************************/

bool allWordSymbolsInString(char *begin, wordDescriptor word) {
    char *end = getEndOfString(begin);
    while (word.begin < word.end)
        if (*find_(begin, end, *word.begin++) != *word.begin)
            return false;

    return true;
}