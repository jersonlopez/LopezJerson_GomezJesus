#include "uppercases_counter.h"

int uppercasesCounter(char character, int *uppercaseNumber) {
    if( character >= 65 && character <= 90)
        (*uppercaseNumber)++;
        
    return *uppercaseNumber;
}