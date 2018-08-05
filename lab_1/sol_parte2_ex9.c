#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int num_aleatorio();

int main() {
	int numero1,numero2,respuesta,solucion;
	int terminar;
	int continuar;
	
	terminar = 1;
    continuar = 0;

	do{                
        if (continuar == 0)
        {
            srand(time(NULL));//Inicializamos la semilla con la fecha/hora
            numero1 = num_aleatorio();
		    numero2 = num_aleatorio();
		    solucion= numero1*numero2;
        }
        		
		printf("¿Cuanto es %d veces %d?\n ", numero1,numero2);
		scanf("%d", &respuesta);
		
        if (respuesta==solucion)
        {
            printf("Muy bien!\n");
            printf("¿Desea continuar aprendiendo?\n Digite 1 para continuar o 0 para salir...\n");
            scanf("%d" , &terminar);   
            continuar = 0;            
        }
        else{
            printf("No. Por favor intenta nuevamente\n"); 
            continuar = 1;           
        }		
	}while(terminar == 1);

	return 0;
}

int num_aleatorio() {
	int numero_aleatorio = rand() % 10;//numero aleatorio de 1 cifra
	return numero_aleatorio;
}