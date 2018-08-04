#include "stdio.h"
#include "math.h"

int suma(int x, int n);

int main()
{
    int x, n;
    int result;
    printf("Introduzca el número x por favor: ");
    scanf("%d", &x);
    printf("Introduzca el número n por favor: ");
    scanf("%d", &n);
    result = suma(x, n);

    printf("La suma de la serie es: %d\n", result);
}

int suma(int x, int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result += pow(x, i);
    }
    return result;
}