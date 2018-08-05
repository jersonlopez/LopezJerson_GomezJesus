/*

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int lanzar_moneda();

int main() {
	int caras = 0;
	int sellos = 0;
	int num_lanzamientos, lado;
	srand(time(NULL));//Inicializamos la semilla con la fecha/hora

	printf("Ingrese el numero lanzamientos\n" );
	scanf("%d" ,&num_lanzamientos);

	for (int i = 0; i < num_lanzamientos; ++i)
	{
		lado = lanzar_moneda();
		if (lado==0)
		{
			printf("C"); //imprime cara en caso de 0
			caras ++;
		}
		else{
			printf("S"); //imprime sello en caso de 1
			sellos ++;
		}
	}
	printf(", # de caras = %d, # de sellos = %d\n", caras, sellos);
	return 0;
}


int lanzar_moneda() {	
	int num_aleatorio = rand()% 2;//generamos un numero aleatorio entre 0 y 1
	return num_aleatorio;
}