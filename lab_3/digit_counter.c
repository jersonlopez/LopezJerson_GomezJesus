#include "digit_counter.h"

int digitCounter(char character, int *digitNumber) {
    if( character >= 48 && character <= 57)
        (*digitNumber)++;
        
    return *digitNumber;
}