#include "words_counter.h"

int wordsCounter(char character, int *wordNumber) {
    if( character == ' ' || character == '\n')
        (*wordNumber)++;

    return *wordNumber;
}