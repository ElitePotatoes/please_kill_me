#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H

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
#include <ctype.h>

#define ASSERT_STRING (expected, got) assertString(expected, got, \
                    __FILE__, __FUNCTION__, __LINE__);

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define CODE_ASCII 48

typedef struct wordDescriptor {
    char *begin;    //позиция начала слова.
    char *end;      //позиция первого символа, после последнего символа слова.
} wordDescriptor;

char stringBuffer [MAX_STRING_SIZE + 1];

typedef struct bagOfWords {
    wordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} bagOfWords;

bagOfWords _bag;
bagOfWords _bag2;

//возвращает количество элементов, расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
size_t strlen_(const char *begin);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти,
//между адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char *find_(char *begin, const char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace_(char *begin);

//возвращает указатель на первый пробельный символ, расположенный на ленте памяти, начиная с адреса begin
//или на первый ноль-символ.
char *findSpace_(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findNonSpaceReverse_(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findSpaceReverse_(char *rbegin, const char *rend);

//возвращает значение '-1', если lhs располагается до rhs в лексикографическом порядке,
//значение - '0', если lhs и rhs равны, иначе – '1'.
int strcmp_(const char *lhs, const char *rhs);

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination.
char *copy_(char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента памяти, начиная с beginSource и заканчивая endSource,
//удовлетворяющие функции-предикату f. Функция возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf_(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//записывает по адресу beginDestination элементы из фрагмента памяти, начиная с rbeginSource и заканчивая rendSource,
//удовлетворяющие функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse_(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//возвращает указатель на последний элемент, расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
char *getEndOfString(char *begin);

//удаляет все пробельные символы, расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
void removeAllSpaces(char *begin);

//ну как бы всё и так понятно из названия самой функции, но к этому мы вернемся позже.
void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

//оставляет только один символ в каждой последовательности подряд идущих одинаковых символов,
//расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
char *removeSameLetters(char *begin);

//оставляет только один символ в каждой последовательности подряд идущих одинаковых символов (не считая пробелов),
//расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
void removeAdjacentEqualLetters(char *begin);

//оставляет только один пробел в каждой последовательности подряд идущих одинаковых пробелов,
//расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
void removeExtraSpaces(char *begin);

//возвращает зачение 'true', если слово было считано, расположенное на ленте памяти,
//начиная с begin и заканчивая ноль-символом, и записывает адрес его начала и конца в word, иначе - 'false'.
bool getWord(char *beginSearch, wordDescriptor *word);

//возвращает зачение 'true', если слово было считано, расположенное на ленте памяти,
//начиная с rbegin и заканчивая rend, и записывает адрес его начала и конца в word, иначе - 'false'.
bool getWordReverse(char *rbegin, const char *rend, wordDescriptor *word);

//преобразует слово word, чтобы его цифры были перенесены в начало в той же последовательности.
void digitToStart(wordDescriptor word);

//преобразует слово word, чтобы его цифры были перенесены в начало в обратной последовательности.
void reverseDigitToStart(wordDescriptor word);

//преобразует слово word, чтобы его цифры были перенесены в конец в той же последовательности.
void digitToEnd(wordDescriptor word);

//преобразует слово word, чтобы его цифры были перенесены в конец в обратной последовательности.
void reverseDigitToEnd(wordDescriptor word);

//записывает по адресу beginDestination фрагмент памяти, начиная с адреса rbeginSource до rendSource.
//Возвращает указатель на следующий свободный фрагмент памяти в destination.
char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);

//преобразует слово word, чтобы его символы были перенесены в обратной последовательности.
void reverseWord(wordDescriptor word);

//преобразует символы во всех словах, расположенные на ленте памяти, начиная с begin и заканчивая ноль-символом.
void reverseWords(char *begin);

//преобразует строку, расположенную на ленте памяти, начиная с адреса begin и заканчивая ноль-символом,
//заменяя каждую цифру соответствующим ей числом пробелов.
char spaceInsteadDigits(char *begin);

//возвращает значение 'true', если все слова, расположенные на ленте памяти,
//начиная с адреса begin и заканчивая ноль-символом, лексичесически упорядочены, иначе - 'false'.
bool isOrderedWords(char *begin);

#endif //MAIN_C_STRING__H