#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <linux/limits.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
	chdir("sources");
	struct timeval start, end;
	char num[10];	
	char num2[10];	
	char filename[80] = "benchmark/";
    char filename2[80] = "benchmark/";
	int resultado = 0;
    strcat(filename,argv[1]);
    strcat(filename2,argv[2]);	
	FILE *inputFile;
	FILE *inputFile2;
	inputFile = fopen(filename,"r");
	inputFile2 = fopen(filename2,"r");

	printf("%sEl numero de hilos son: %sninguno\n",BLANCO, PURPURA);
    printf("%sEl archivo 1 es: %s%s\n",BLANCO, CYAN, filename);
    printf("%sEl archivo 2 es: %s%s\n",BLANCO, CYAN, filename2);
    printf("%sTipo de procesamiento: %ssecuencial\n",BLANCO, ROJO);

    if(inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return 0;
    }
	if(inputFile2 == NULL) {
        printf("Error al abrir el archivo %s\n", filename2);
        return 0;
    }
	
	gettimeofday(&start,NULL);
	while (feof(inputFile) == 0 )
	{
		fgets(num,10,inputFile);
		fgets(num2,10,inputFile2);
		resultado += atoi(num)*atoi(num2);
	}
	gettimeofday(&end,NULL);
	long seconds = (end.tv_sec - start.tv_sec);
  	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
  	printf("%sEl tiempo que se tardo en realizar la operacion fue de:%s %lds (%ldms)\n", BLANCO, VERDE, seconds, micros);
	printf("%sEl Resultado obtenido en la multiplicación secuencial fue:%s %d\n", BLANCO,MARRON,resultado);
	return 0;
}
