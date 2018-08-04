#include "stdio.h"

int esMultiplo(int a, int b);

int main()
{
    int a, b;
    int result;
    printf("Introduzca el primer número por favor: ");
    scanf("%d", &a);
    printf("Introduzca el segundo número por favor: ");
    scanf("%d", &b);
    result = esMultiplo(a,b);
    
    if (result==1) {
        printf("%d es multiplo de %d\n",b,a);
    }
    else {
        printf("%d NO es multiplo de %d\n",b,a);
    }
}

int esMultiplo(int a, int b){
    
    if (a%b==0) {
        return 1;
    }
    else {
        return 0;
    }
        
}