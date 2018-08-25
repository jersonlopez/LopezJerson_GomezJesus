#include "stdio.h"

void contarCaracter(char *array, char ch);
void test();

int main()
{
    test();
}

void contarCaracter(char *array, char letter) {
    int quantity = 0, position = 0, i = 0;
    char *str = array;

    while(*str != '\0'){
        if(*str == letter){
            if(position == 0) position = i;
            quantity += 1;
        }
        str++;
        i++;
    }

    if(quantity == 0) 
    printf("-1\n");
    else
    printf("la cantidad de %c en la cadena es: %d\n", letter, quantity);
    printf("y aparecio por primera vez en la posicion %d de la cadena \n", position);
}

void test(){
    char string[] = "codebabes";
    char letter = 'b';
    printf("la cadena es: %s \n", string);
    contarCaracter(string, letter);
}
