#include "stdio.h"

int contarCaracter(char *array, char ch);

int main()
{
    char string[] = "soyelputas"
    char letter = "y"
    // printf("Introduzca sus ventas del mes por favor:");
    // scanf("%d", &ventas);
    comision = calcular_comision(ventas);
    printf("Su comisión obtenida fue de: %.3f\n", comision);
}

int contarCaracter(char *array, char letter) {
    int quantity = 0;
    char str = array;
    while(str != "\0"){
        if(str == letter){
            quantity += 1;
        }
    }
}
