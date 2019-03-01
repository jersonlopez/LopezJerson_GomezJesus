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
void verifica_archivo(char **items ,int potencial);

int main()
{
	char **items;
	int num, background;
	char expresion[TAM];

	while (1)
	{		
        printf("%sBienvenido al asistente de producto punto entre vectores\n",VERDE);       
		printf("%s-> %s",BLANCO,AZUL);
		fgets(expresion, TAM, stdin);
		num = separaItems(expresion, &items, &background);

		if (num > 0)
		{			
			if (strcmp(items[0], "pps") == 0)
			{
				execute("./sources/pps", items, background);
			}
			else if (strcmp(items[0], "ppp") == 0)
			{
				execute("./sources/ppp", items, background);
			}
			else if (strcmp(items[0], "mult") == 0)
			{
				if (strcmp(items[1], "ppp") == 0)
				{
					verifica_archivo(items ,atoi(items[2]));
					execute("./sources/ppp", items, background);
				}
				else if (strcmp(items[1], "pps") == 0)
				{
					verifica_archivo(items ,atoi(items[2]));
					execute("./sources/pps", items, background);
				}
			}			
			else if (strcmp(items[0], "comp") == 0)
			{
				verifica_archivo(items ,atoi(items[2]));
				execute("./sources/pps", items, background);
				printf("____________________________________\n");
				execute("./sources/ppp", items, background);
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

void verifica_archivo(char **items ,int potencial){
	switch (potencial)
	{
		case 1:
			items[1] = "vec_10_1_a.txt";
			items[2] = "vec_10_1_b.txt";
		break;
	
		case 3:
			items[1] = "vec_10_3_a.txt";
			items[2] = "vec_10_3_b.txt";
		break;

		case 6:
			items[1] = "vec_10_6_a.txt";
			items[2] = "vec_10_6_b.txt";
		break;

		case 8:
			items[1] = "vec_10_8_a.txt";
			items[2] = "vec_10_8_b.txt";
		break;

		default:
			printf("%sNo hay ningún archivo con ese potencial\n",ROJO);
		break;
	}
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
	printf("%spps:%s Realiza la multiplicación de dos vectores de forma secuencial, es necesario especificar los nombres de los archivos que contiene los vectores, por ejemplo: %s pps vec_10_1_a.txt vec_10_1_b.txt\n",VERDE,BLANCO,ROJO);
	printf("%sppp:%s Realiza la multiplicación de dos vectores de forma paralela, es necesario especificar los nombres de los archivos que contiene los vectores y el numero de hilos, %spor ejemplo: ppp vec_10_1_a.txt vec_10_1_a.txt 2\n",VERDE,BLANCO,ROJO);
	printf("%smult:%s Realiza la multiplicación entre los vectores de la carpeta benchmark, para esto debera especificar: si es ppp o pps, el exponencial para identificar los archivos a multiplicar. En caso de que sea paralelo debera decir el numero de hilos, Por ejemplo: %smult pps 3 10\n",VERDE,BLANCO,ROJO);	
	printf("%scomp:%s Realiza la multiplicación entre los vectores de la carpeta benchmark de forma secuencial y paralela, debe ingresar exponencial para identificar los archivos a multiplicar. No olvide decir la cantida de hilos, Por ejemplo: %scomp all 3 10\n",VERDE,BLANCO,ROJO);	
	printf("%sexit:%s Finaliza la ejecución del asistente\n",VERDE,BLANCO);
}