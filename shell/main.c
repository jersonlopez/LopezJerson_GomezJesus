
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <wait.h>
#include <stdbool.h>
#include "parser.h"
#include "sources/color.h"
#define TAM 100

void execute_cd(char **args);
void execute_pwd();
int execute(char *command, char **params, bool background);

int main()
{
	char **items;
	int num, background;
	char expresion[TAM];

	while (1)
	{
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
				//execute("./sources/udea-cd", items, background);
				execute_cd(items);
			}
			else if (strcmp(items[0], "udea-echo") == 0)
			{
				execute("./sources/udea-echo", items, background);
			}
			else if (strcmp(items[0], "udea-clr") == 0)
			{
				execute("./sources/udea-clr", items, background);
			}
			else if (strcmp(items[0], "udea-time") == 0)
			{
				execute("./sources/udea-time", items, background);								
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