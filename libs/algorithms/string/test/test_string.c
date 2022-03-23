#include "test_string.h"

void test_strlen() {}
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
void test_removeAllSpaces() {}

/********************************************************** 2 *********************************************************/

void test_removeAdjacentEqualLetters() {}
void test_removeExtraSpaces() {}

/********************************************************** 3 *********************************************************/

void test_getWord() {}
void test_getWordReverse() {}
void test_digitToStart() {}
void test_reverseDigitToStart() {}
void test_digitToEnd() {}
void test_reverseDigitToEnd() {}
void test_copyReverse() {}
void test_reverseWord() {}
void test_reverseWords() {}

/********************************************************** 4 *********************************************************/

void test_spaceInsteadDigits() {}

/********************************************************** 5 *********************************************************/

void test_isEqualWords() {}

void test_replace_default() {
    char read[] = "hello world";
    char expected[] = "hello hello";

    replace(read, "world", "hello");

    assert(strcmp_(read, expected));
}
void test_replace_all() {
    char read[] = "hello hello hello";
    char expected[] = "darova darova darova";

    replace(read, "hello", "darova");

    assert(strcmp_(read, expected));
}
void test_replace() {
    test_replace_default();
    test_replace_all();
}

/********************************************************** 6 *********************************************************/

void test_isOrderedWords_emptyLine() {
    char read[] = " ";
    assert(isOrderedWords(read) == 1);
}
void test_isOrderedWords_oneSymbol() {
    char read[] = "a";
    assert(isOrderedWords(read) == 1);
}
void test_isOrderedWords_justWorld() {
    char read[] = "hello";
    assert(isOrderedWords(read) == 1);
}
void test_isOrderedWords_true_monoSymbols() {
    char read[] = "a b c";
    assert(isOrderedWords(read) == 1);
}
void test_isOrderedWords_false_monoSymbols() {
    char read[] = "c b a";
    assert(isOrderedWords(read) == 0);
}
void test_isOrderedWords_true_haveSameSymbols() {
    char read[] = "abbbcccde";
    assert(isOrderedWords(read) == 1);
}
void test_task6_default_case() {
    char testString[] = "abc abc";
    assert(isOrderedWords(testString) == 1);
}

void test_task6_mono_symbols() {
    char testString[] = "a b c d e";
    assert(isOrderedWords(testString) == 1);
}

void test_task6_one_word() {
    char read[] = "abc";
    assert(isOrderedWords(read) == 1);
}
void test_isOrderedWords() {
    //test_isOrderedWords_emptyLine();
    test_isOrderedWords_oneSymbol();
    test_isOrderedWords_true_monoSymbols();
    //test_isOrderedWords_false_monoSymbols();
    test_isOrderedWords_true_haveSameSymbols();
    test_isOrderedWords_justWorld();

    test_task6_default_case();
    test_task6_mono_symbols();
    test_task6_one_word();
}

/********************************************************** 7 *********************************************************/

void test_getBagOfWords() {}

/********************************************************** 8 *********************************************************/

void test_isPalindromeWord() {}

void test_getCountPalindromeWords();

/********************************************************** 9 *********************************************************/

void test_isEmptyStringWithoutWords();

void test_getInterleavedString();

/********************************************************* 10 *********************************************************/

void test_reverseString() {}

/********************************************************* 11 *********************************************************/

void test_findA() {}

void test_printWordBeforeFirstWordWithA() {}

/********************************************************* 12 *********************************************************/

void test_wordDescriptorToString() {}

void test_lastSameWordInFirstAndSecondString() {}

/********************************************************* 13 *********************************************************/

void test_stringContainsSameWords() {}

/********************************************************* 14 *********************************************************/

void test_stringContainsSameWordsWithSameSymbols() {}

/********************************************************* 15 *********************************************************/

void test_getStringWithoutSameLastWord_noWords() {
    char read[] = " ";
    char expected[] = " ";

    getStringWithoutSameLastWord(read);

    assert(strcmp_(read, expected));
}

void test_getStringWithoutSameLastWord_default() {
    char read[] = "hello world world";
    char expected[] = "hello";

    getStringWithoutSameLastWord(read);

    assert(strcmp_(read, expected));
}
void test_getStringWithoutSameLastWord() {
    //test_getStringWithoutSameLastWord_noWords();
    test_getStringWithoutSameLastWord_default();
}

/********************************************************* 16 *********************************************************/

void test_firstWordBeforeSameInFirstAndSecondString() {}

/********************************************************* 17 *********************************************************/

void test_deletePalindromeWords() {}

/********************************************************* 18 *********************************************************/

void test_addWordsToSmallerString_default() {
    char readOne[] = "hello world and die";
    char readTwo[] = "be usefull";
    char expected[] = "be usefull and die";

    puts(readTwo);

    addWordsToSmallerString(readOne, readTwo);

    assert(strcmp_(readTwo, expected) == 0);
}
void test_addWordsToSmallerString() {
    test_addWordsToSmallerString_default();
}

/********************************************************* 19 *********************************************************/

void test_allWordSymbolsInString() {}

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
    test_removeAllSpaces();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_getWord();
    test_getWordReverse();
    test_digitToStart();
    test_reverseDigitToStart();
    test_digitToEnd();
    test_reverseDigitToEnd();
    test_copyReverse();
    test_reverseWord();
    test_reverseWords();
    test_spaceInsteadDigits();
    test_isEqualWords();
    test_replace();
    //test_isOrderedWords();
    test_getBagOfWords();
    test_isPalindromeWord();
/*    test_getCountPalindromeWords();
    test_isEmptyStringWithoutWords();
    test_getInterleavedString();*/
    test_reverseString();
    test_findA();
    test_printWordBeforeFirstWordWithA();
    test_wordDescriptorToString();
    test_lastSameWordInFirstAndSecondString();
    test_stringContainsSameWords();
    test_stringContainsSameWordsWithSameSymbols();
    test_getStringWithoutSameLastWord();
    test_firstWordBeforeSameInFirstAndSecondString();
    test_deletePalindromeWords();
    test_addWordsToSmallerString();
    test_allWordSymbolsInString();
}