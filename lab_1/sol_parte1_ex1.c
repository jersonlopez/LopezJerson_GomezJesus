#include "stdio.h"

float calcular_comision(int ventas);

int main()
{
    float comision;
    int ventas;
    printf("Introduzca sus ventas del mes por favor:");
    scanf("%d", &ventas);
    comision = calcular_comision(ventas);
    printf("Su comisión obtenida fue de: %.3f\n", comision);
}

float calcular_comision(int ventas){
    float result;
    if(ventas <= 20000){
        result = ventas * 0.05;
    }else if( ventas > 2000 && ventas <= 50000){
        result = (ventas * 0.07) + 1000;
    }else if( ventas > 50000){
        result = (ventas * 0.1) + 3100;
    }
    return result;
}