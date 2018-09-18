#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "character_counter.h"
#include "digit_counter.h"
#include "lines_counter.h"
#include "lowercases_counter.h"
#include "uppercases_counter.h"
#include "whitespaces_Counter.h"
#include "words_counter.h"

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
    FILE *outFile;
    int characters = 0, words = 0, lines = 0, whitespaces = 0, uppercases = 0, lowercases = 0, digits = 0;

    printf("Ingrese el nombre del archivo que sera analizado: ");
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
    printf("Obteniendo estadisticas...\n");
    char name[80];
    nameFile(filename,name);
    strcat(name,"_stats.txt");
    printf("%s --> generando reporte %s\n", filename, name);
    outFile = fopen (name, "w" );
    char cadena[50];
    sprintf(cadena,"chars: %d\n", text.chars);
    fputs( cadena, outFile );
    sprintf(cadena,"words: %d\n", text.words);
    fputs( cadena, outFile );
    sprintf(cadena,"lines: %d\n", text.lines);
    fputs( cadena, outFile );
    sprintf(cadena,"whitespaces: %d\n", text.whitespaces);
    fputs( cadena, outFile );
    sprintf(cadena,"uppercases: %d\n", text.uppercase);
    fputs( cadena, outFile );
    sprintf(cadena,"lowercases: %d\n", text.lowercase);
    fputs( cadena, outFile );
    sprintf(cadena,"digits: %d\n", text.digits);
    fputs( cadena, outFile ); 	
 	fclose ( outFile );
    printf("Estadisticas culminadas\n");
};

// uppercase
// lowercase
// digits