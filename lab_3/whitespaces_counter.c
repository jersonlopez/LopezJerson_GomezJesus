#include "whitespaces_Counter.h"

int whitespacesCounter(char character, int *whitespaceNumber) {
    if( character == ' ')
        (*whitespaceNumber)++;
        
    return *whitespaceNumber;
}