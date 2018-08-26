#include <stdio.h>

float mediana(float *a,int n);
float imprimir(float *a,int n);
void ordenar(float *a,int n);

float main() {
    float a[7] = {13.3,24.4,31.5,45,59.7,6.9,43.3};
    float m;
    printf("El vector es el siguiente:\n");
    imprimir(a,7);
    printf("El vector ordenado es el siguiente:\n");
    ordenar(a,7);
    imprimir(a,7);
    m = mediana(a,7);
    printf("La mediana del vector es: %f\n",m);
    return 0;
}

float mediana(float *a,int n) {
    int i = n/2 ;
    float m;
        m = *(a+i);
    return m;
}

float imprimir(float *a, int n) {
    printf("A = [ ");
    for(int i = 0; i < n; i++) {
        printf("%f ", *(a+i));   
    }
    printf("]\n"); 
    return 0;  
}

void ordenar(float *a, int n){
    int intervalo, j, k;
    intervalo = n/2;
    while(intervalo>0){
        for(int i = 0; i < n; i++){
            j = i - intervalo;
            while(j >= 0){
                k = j + intervalo;
                if(*(a+j) <= *(a+k)){
                    j = -1;
                }else{
                    float aux;
                    aux = *(a+j);
                    *(a+j) = *(a+k);
                    *(a+k) = aux;
                    j -= intervalo; 
                }
            }
        }
        intervalo = intervalo/2;
    }
}