#include "lines_counter.h"

int linesCounter(char character, int *lineNumber) {
    if( character == '\n')
        (*lineNumber)++;
        
    return *lineNumber;
}