#include "test_string.h"

#define ASSERT_STRING (expected, got) assertString(expected, got, \
                    __FILE__, __FUNCTION__, __LINE__);

void test_strlen_zeroSymbols() {
    char read[] = "";
    assert(strlen_(read) == 0);
}
void test_strlen_standart() {
    char read[] = "Hello world!";
    assert(strlen_(read) == 12);
}
void test_strlen() {
    test_strlen_zeroSymbols();
    test_strlen_standart();
}

void test_find() {}
void test_findNonSpace() {}
void test_findNonSpaceReverse() {}
void test_findSpaceReverse() {}
void test_strcmp() {}
void test_copy() {}
void test_copyIf() {}
void test_copyIfReverse() {}

/********************************************************** 1 *********************************************************/

void test_getEndOfString() {}
void test_removeNonLetters() {}

void test_string() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_getEndOfString();
    test_removeNonLetters();
}

/*void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

assertString(s1, s2, "digitToStartTransform.h", "test_digitToStartTransform_oneWord", 30) ;

void test_removeNonLetters() {
    char s[] = "Hello world!";
    removeNonLetters(s);
    ASSERT_STRING("Helloworld!", s) ;
}*/
