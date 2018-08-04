#include "stdio.h"

int main()
{
    int n;
    printf("Introduzca el numero de filas que desea imprimir por favor:");
    scanf("%d", &n);
    for (int i=1; i <= n; i++){
        int flag = 0;
        if(i%2==0)
            printf("0");
        else{
            flag = 1;
            printf("1");
        }
        for(int j=2; j<= i; j++){            
            if (flag == 0){
                flag = 1;
                printf("1");
            }
            else {
                flag = 0;
                printf("0");
            }            
        }
        printf("\n");
    }
    return 0;
}