#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include "color.h"

int main(int argc, char *argv[])
{
	char *cwd;
	char buff[PATH_MAX + 1];
	cwd = getcwd(buff, PATH_MAX + 1);
	if (cwd != NULL)
	{
		printf("%sUsted se encuentra parado en: %s%s.\n",MARRON,BLANCO,cwd);
	}
	printf("valor %s\n",argv[1]);
    if (argv[1] == NULL)
	{
		printf("Error: %sEs necesario indicar el directorio.\n",ROJO);
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			printf("Error: %sEl directorio ingresado no existe o lo escribio de forma incorrecta\n",ROJO);
		}		
		cwd = getcwd(buff, PATH_MAX + 1);
		if (cwd != NULL)
		{
			printf("%sUsted se encuentra parado en: %s%s.\n",MARRON,BLANCO,cwd);
		}
	}
}