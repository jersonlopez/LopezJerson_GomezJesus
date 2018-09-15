#include "stdio.h"

int characterCounter(int *characterNumber) {
    return (*characterNumber)++;
}

int wordsCounter(char character, int *wordNumber) {
    if( character == ' ' || character == '\n')
        (*wordNumber)++;

    return *wordNumber;
}

int linesCounter(char character, int *lineNumber) {
    if( character == '\n')
        (*lineNumber)++;
        
    return *lineNumber;
}

int whitespacesCounter(char character, int *whitespaceNumber) {
    if( character == ' ')
        (*whitespaceNumber)++;
        
    return *whitespaceNumber;
}

int uppercasesCounter(char character, int *uppercaseNumber) {
    if( character >= 65 && character <= 90)
        (*uppercaseNumber)++;
        
    return *uppercaseNumber;
}

int lowercasesCounter(char character, int *lowercaseNumber) {
    if( character >= 97 && character <= 122)
        (*lowercaseNumber)++;
        
    return *lowercaseNumber;
}

int digitCounter(char character, int *digitNumber) {
    if( character >= 48 && character <= 57)
        (*digitNumber)++;
        
    return *digitNumber;
}

struct stats {
  int chars;
  int words;
  int lines;
  int whitespaces;
  int uppercase;
  int lowercase;
  int digits;
};

int main()
{
    struct stats text;
    char filename[80];
    char character;
    FILE *inputFile;
    int characters = 0, words = 0, lines = 0, whitespaces = 0, uppercases = 0, lowercases = 0, digits = 0;

    printf("Entre el nombre del archivo que sera analizado: ");
    gets(filename);
    inputFile = fopen(filename,"r");

    if ( inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return 0;
    }

    while((character = fgetc(inputFile)) != EOF){
        text.chars = characterCounter(&characters);
        text.words = wordsCounter(character, &words);
        text.lines = linesCounter(character, &lines);
        text.whitespaces = whitespacesCounter(character, &whitespaces);
        text.uppercase = uppercasesCounter(character, &uppercases);
        text.lowercase = lowercasesCounter (character, &lowercases);
        text.digits = digitCounter(character, &digits);
    }

    printf("chars: %d\n", text.chars);
    printf("words: %d\n", text.words);
    printf("lines: %d\n", text.lines);
    printf("whitespaces: %d\n", text.whitespaces);
    printf("uppercases: %d\n", text.uppercase);
    printf("lowercases: %d\n", text.lowercase);
    printf("digits: %d\n", text.digits);

};

// uppercase
// lowercase
// digits