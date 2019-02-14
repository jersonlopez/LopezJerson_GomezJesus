#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double producto_punto(double v1[], double v2[], int d);

int main(int argc, char *argv[])
{
	char num[100];	
	char num2[100];	
	char filename[80] = "benchmark/vec_10_1_a.txt";
	char filename2[80] = "benchmark/vec_10_1_b.txt";
	double resultado = 0;
	//strcat(filename,"_stats.txt");
	FILE *inputFile;
	FILE *inputFile2;
	inputFile = fopen(filename,"r");
	inputFile2 = fopen(filename2,"r");

    if(inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return 0;
    }
	if(inputFile2 == NULL) {
        printf("Error al abrir el archivo %s\n", filename2);
        return 0;
    }
	
	while (feof(inputFile) == 0 )
	{
		fgets(num,100,inputFile);
		fgets(num2,100,inputFile2);
		resultado += strtod(num,NULL)*strtod(num2,NULL);
	}

	printf("Resultado %f\n",resultado);
	return 0;
}

double producto_punto(double v1[], double v2[], int d)
{
	double resultado = 0;
	int i;
	for (i=0; i < d; i++) {
		resultado += v1[i] * v2[i];
	}
	return resultado;
}