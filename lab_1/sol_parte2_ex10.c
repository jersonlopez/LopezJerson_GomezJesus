#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int num_aleatorio(int limite);
char mensaje_correcto(int num);
char mensaje_incorrecto(int num);

int main() {
	int numero1,numero2,numero3,respuesta,solucion;
	int terminar;
	int continuar;
	
	terminar = 1;
    continuar = 0;

	do{                
        if (continuar == 0)
        {
            srand(time(NULL));//Inicializamos la semilla con la fecha/hora
            numero1 = num_aleatorio(10);
		    numero2 = num_aleatorio(10);
		    solucion = numero1*numero2;
        }
        		
		printf("¿Cuanto es %d veces %d?\n ", numero1,numero2);
		scanf("%d", &respuesta);
		
        if (respuesta==solucion)
        {
            numero3 = num_aleatorio(4)+1;
            mensaje_correcto(numero3);
            printf("¿Desea continuar aprendiendo?\n Digite 1 para continuar o 0 para salir...\n");
            scanf("%d" , &terminar);   
            continuar = 0;            
        }
        else{
            numero3 = num_aleatorio(4)+1;
            mensaje_incorrecto(numero3);                        
            continuar = 1;           
        }		
	}while(terminar == 1);

	return 0;
}

int num_aleatorio(int limite) {
	int numero_aleatorio = rand() % limite;//numero aleatorio de 1 cifra
	return numero_aleatorio;
}

char mensaje_correcto(int num){      
    switch (num)
    {
        case 1:
            printf("Muy bien!\n");
            break;
        case 2:
            printf("Excelente!\n");            
            break;
        case 3:
            printf("Buen trabajo!\n");             
            break;
        case 4:
            printf("Sigue haciendolo bien!\n");                         
            break;
        default:
            break;
    }
    return 0;
}

char mensaje_incorrecto(int num){    
    switch (num)
    {
        case 1:
            printf("No. Por favor trata de nuevo\n");                
            break;
        case 2:
            printf("Incorrecto. Trata una vez más\n");                
            break;
        case 3:
            printf("No te rindas!\n");                
            break;
        case 4:
            printf("No. Trata de nuevo\n");                
            break;
        default:
            break;
    }
    return 0;
}