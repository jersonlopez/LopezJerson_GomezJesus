#include "stdio.h"
#include "math.h"

int suma(int x, int n);
int factorial(int a);

int main()
{
    int x, n;
    int result;
    printf("Introduzca el número x por favor: ");
    scanf("%d", &x);
    printf("Introduzca el número n por favor: ");
    scanf("%d", &n);
    result = suma(x, n);
    for (int i=1; i <= n; i++){
        int flag = 0;
        if(i%2==0)
            printf("0");
        else{
            flag = 1;
            printf("1");
        }
        for(int j=2; j<= i; j++){            
            if (flag == 0){
                flag = 1;
                printf("1");
            }
            else {
                flag = 0;
                printf("0");
            }            
        }
        printf("\n");
    }
    return 0;
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

int factorial (int a) {
  int i,product=1;
  for (i=2; i<=n; ++i)
    product *= i;
  return product;
}