#include <stdio.h>
#include "color.h"

int main(int argc, char *argv[])
{
    int i = 1;
	while (argv[i] != NULL)
	{
		printf("%s%s ",PURPURA, argv[i]);
		i++;
	}
	printf("\n");
}