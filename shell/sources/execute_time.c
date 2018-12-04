#include <time.h>
#include <stdio.h>
#include "color.h"

int main()
{
    time_t r_time;
	time(&r_time);
	printf("%sFecha y hora actual: %s%s",CYAN,BLANCO,ctime(&r_time));
}