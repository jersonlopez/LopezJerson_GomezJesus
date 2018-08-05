#include "stdio.h"
#include "math.h"

float suma(int x, int n);
int factorial(int a);

int main()
{
    int x, n;
    float result;
    printf("Introduzca el número x por favor: ");
    scanf("%d", &x);
    printf("Introduzca el número n por favor: ");
    scanf("%d", &n);
    result = suma(x, n);

    printf("La suma de la serie es: %.6f\n", result);
}

float suma(int x, int n)
{
    float result = 1;
    int flag = 1;
    for (int i = 2; i <= n; i += 2)
    {

        if (flag == 1){
            result -= pow(x, i)/factorial(i);
            flag = 0;
        }
        else
        {
            result += pow(x, i)/factorial(i);
            flag = 1;
        }
    }
    return result;
}

int factorial(int a)
{
    int i, product = 1;
    for (i = 2; i <= a; ++i)
        product *= i;
    return product;
}