#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include <time.h>
#include <wait.h>
#include <stdbool.h>
#include "color.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
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