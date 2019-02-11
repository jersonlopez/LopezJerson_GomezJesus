#include <stdio.h>
#include <stdlib.h>//EXIT
#include <string.h>//STRING
#include <unistd.h>//FORK
#include <wait.h>//WAIT
#include <stdbool.h>//BOOLEANO
#include "parser.h"
#include "sources/color.h"
#define TAM 100

void show_commands();
int execute(char *command, char **params, bool background);

int main()
{
	char **items;
	int num, background;
	char expresion[TAM];

	while (1)
	{		
        printf("%sProducto punto entre vectores",VERDE);       

		fgets(expresion, TAM, stdin);
		num = separaItems(expresion, &items, &background);

		if (num > 0)
		{			
			if (strcmp(items[0], "pps") == 0)
			{
				execute("./sources/pps", items, background);
			}
			else if (strcmp(items[0], "pph") == 0)
			{
				execute("./sources/pph", items, background);
			}			
			else if (strcmp(items[0], "help") == 0)
			{
				show_commands();
			}
			else if (strcmp(items[0], "exit") == 0)
			{
				exit(0);
			}			
		}
		liberaItems(items);
	}

	return 0;
}

int execute(char *command, char **params, bool background)
{
	int status;
	pid_t pid_programa;
	switch (pid_programa = fork())
	{
		case -1:
			printf("%sError ejecutando el comando.\n",ROJO);
			return -1;
		case 0:
			execvp(command, params);
			printf("%sHubo un error llamando el programa\n",ROJO);
			exit(0);
	}

	if (!background)
	{
		wait(&status);
	}

	return 0;
}

void show_commands(){
	printf("%sLos comandos internos son:\n",MARRON);
	printf("%sudea-pwd:\t%sImprime en pantalla el directorio de trabajo actual\n",VERDE,BLANCO);
	printf("%sudea-cd:\t%sCambia el directorio de trabajo del sheel\n",VERDE,BLANCO);
	printf("%sudea-echo:\t%sImprime el mensaje en pantalla\n",VERDE,BLANCO);
	printf("%sudea-clr:\t%sLimpia pantalla\n",VERDE,BLANCO);
	printf("%sudea-time:\t%sImprime el tiempo actual del sistema\n",VERDE,BLANCO);
	printf("%sudea-help:\t%sImprime los comandos internos\n",VERDE,BLANCO);
	printf("%sudea-exit:\t%sFinaliza la ejecución del Udea-Shell\n",VERDE,BLANCO);
}