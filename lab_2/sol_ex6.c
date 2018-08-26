#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#define TAM 10
void copiar_vec(float *a, float *b, int n);
void imprimir_alumnos(float *a, float *b, int n);
void genera_notas(float *a,int n);
void media_alumnos(float *m, float *s, float *q, float *f, float *a, float *medias, int n);
float media_curso(float *a, int n);
void imprimir(float *a,int n);
void ordenar(float *a,int n);
void invertir_vec(float *a, int n);

float main() {
    srand(time(NULL));
    float matematicas[TAM];
    float sociales[TAM];
    float quimica[TAM];
    float fisica[TAM];
    float artistica[TAM];
    float alumnos_notas_m[TAM];
    float alumnos_notas_m_o[TAM];
    float media;
    float media_total;
    printf("Las notas de la asignatura de matematicas son:\n");
    genera_notas(matematicas, TAM);
    printf("Las notas de la asignatura de sociales son:\n");
    genera_notas(sociales, TAM);
    printf("Las notas de la asignatura de quimica son:\n");
    genera_notas(quimica, TAM);
    printf("Las notas de la asignatura de fisica son:\n");
    genera_notas(fisica, TAM);
    printf("Las notas de la asignatura de artistica son:\n");
    genera_notas(artistica, TAM);
    media_alumnos(matematicas,sociales,quimica,fisica,artistica,alumnos_notas_m,TAM);
    media = media_curso(matematicas,TAM);
    media_total = media;
    printf("La media del curso matematica es: %f\n",media);
    media = media_curso(sociales,TAM);
    media_total += media;
    printf("La media del curso sociales es: %f\n",media);
    media = media_curso(quimica,TAM);
    media_total += media;
    printf("La media del curso quimica es: %f\n",media);
    media = media_curso(fisica,TAM);
    media_total += media;
    printf("La media del curso fisica es: %f\n",media);
    media = media_curso(artistica,TAM);
    media_total += media;
    printf("La media del curso artistica es: %f\n",media);
    media_total = media_total/5;
    printf("La media total de la clase es: %f\n",media_total);
    copiar_vec(alumnos_notas_m,alumnos_notas_m_o,TAM);
    ordenar(alumnos_notas_m_o,TAM);
    printf("Alumnos por orden decreciente de notas medias individuales:\n");
    invertir_vec(alumnos_notas_m_o, TAM);
    imprimir_alumnos(alumnos_notas_m_o,alumnos_notas_m, TAM);
    return 0;
}

void invertir_vec(float *a, int n){
    float aux;
    for(int i = 0; i < n/2; i++) {
        aux = *(a+i);
        *(a+i) = *(a+n-i-1);
        *(a+n-i-1) = aux;
    }
}

void copiar_vec(float *a, float *b, int n){
    for(int i = 0; i < n; i++) {
        *(b+i)= *(a+i);
    }
}

void media_alumnos(float *m, float *s, float *q, float *f, float *a, float *medias, int n){
    float media = 0;
    for(int i = 0; i < n; i++) {
        media = (*(m+i)+*(s+i)+*(q+i)+*(f+i)+*(a+i) )/5;
        printf("La media del alumno %d es: %f\n",i,media);
        *(medias+i) = media;
    }
}

float media_curso(float *a, int n){
    float media = 0;
    for(int i = 0; i < n; i++) {
        media += *(a+i);
    }
    return media/n;
}

void genera_notas(float *a,int n){
    for(int i = 0; i < n; i++) {
        *(a+i) = 1 + (float)(rand()) / (float)(RAND_MAX/4);
    }
    imprimir(a,TAM);
}

void imprimir_alumnos(float *a, float *b, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(*(a+i)==*(b+j)){
                printf("El alumno numero %d tuvo tuvo el puesto numero %d con nota una media de %f \n",j,i, *(b+j)); 
            }
        }
          
    } 
}

void imprimir(float *a, int n) {
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%f ", *(a+i));   
    }
    printf("]\n");     
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