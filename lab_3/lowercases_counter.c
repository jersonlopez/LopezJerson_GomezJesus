#include "lowercases_counter.h"

int lowercasesCounter(char character, int *lowercaseNumber) {
    if( character >= 97 && character <= 122)
        (*lowercaseNumber)++;
        
    return *lowercaseNumber;
}