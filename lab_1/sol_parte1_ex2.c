#include "stdio.h"

int main()
{
    int result, n;
    printf("Introduzca el numero hasta el que desea imprimir la tablas por favor:");
    scanf("%d", &n);
    for (int i=1; i < 11; i++){
        for(int j=1 ; j <= n; j++){
            result = i*j;
            printf("%dx%d = %d, ",i,j,result );
        }
        printf("\n");
    }
    return 0;
}
