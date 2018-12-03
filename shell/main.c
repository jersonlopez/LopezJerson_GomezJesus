
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <time.h>
#include <wait.h>
#include <stdbool.h>
#include "parser.h"
#define ROJO "\x1b[31;1;1m"
#define NEGRO "\x1b[0m"
#define VERDE "\x1b[32;1;1m"
#define AZUL "\x1b[34;1;1m"
#define CYAN "\x1b[36;1;1m"
#define MARRON "\x1b[33;1;1m"
#define PURPURA "\x1b[35;1;1m"
#define BLANCO "\x1b[37;1;1m"
#define TAM 100

void execute_cd(char **args);
void execute_pwd();
void execute_echo(char **items);
void execute_clr(int num);
int execute(char *command, char **params, bool background);

int main()
{
	char **items;
	int num, background;
	char expresion[TAM];

	while (1)
	{
		//cat /etc/hostname
		printf("%sUdea-Shell%s# ",VERDE,BLANCO);
		fgets(expresion, TAM, stdin);

		num = separaItems(expresion, &items, &background);

		if (num > 0)
		{
			if (strcmp(items[0], "udea-pwd") == 0)
			{
				execute_pwd();
			}
			else if (strcmp(items[0], "udea-cd") == 0)
			{
				execute_cd(items);
			}
			else if (strcmp(items[0], "udea-echo") == 0)
			{
				execute_echo(items);
			}
			else if (strcmp(items[0], "udea-clr") == 0)
			{
				execute_clr(num);
			}
			else if (strcmp(items[0], "udea-time") == 0)
			{
				time_t r_time;
				time(&r_time);
				printf("%sFecha y hora actual: %s%s",CYAN,BLANCO,ctime(&r_time));
			}
			else if (strcmp(items[0], "udea-exit") == 0)
			{
				exit(0);
			}
			else
			{
				execute(items[0], items, background);
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

void execute_pwd()
{
	char *cwd;
	char buff[PATH_MAX + 1];
	cwd = getcwd(buff, PATH_MAX + 1);
	if (cwd != NULL)
	{
		printf("%sUsted se encuentra parado en: %s%s.\n",MARRON,BLANCO,cwd);
	}
}

void execute_cd(char **args)
{
	if (args[1] == NULL)
	{
		printf("Error: %sEs necesario indicar el directorio.\n",ROJO);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			printf("Error: %sEl directorio ingresado no existe o lo escribio de forma incorrecta\n",ROJO);
		}
	}
}

void execute_echo(char **items)
{
	int i = 1;
	while (items[i] != NULL)
	{
		printf("%s%s ",PURPURA, items[i]);
		i++;
	}
	printf("\n");
}

void execute_clr(int num)
{
	if (num == 1)
	{		
		int result = system("reset");
		if (result == -1)
		{
			printf("%sOcurrio un error al ejecutar el comando.\n",ROJO);
		}
	}
	else
	{
		printf("%sNo se esperaba mas de 1 parámetro.\n",ROJO);
	}
}