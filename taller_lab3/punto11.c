#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
int calcula_factorial(int num, int hilo);
int main(int argc, char *argv[])
{
  pid_t pid_h1;
  pid_t pid_h2;
  pid_t pid_h3;
  int status;
  pid_h1 = fork();
  if (pid_h1 == 0)
  {
    calcula_factorial(10,1);
    printf("HIJO1: He terminado!\n");
  }
  else
  {
    pid_h2 = fork();
    if (pid_h2 == 0)
    {
      calcula_factorial(10,2);
      printf("HIJO2: He terminado!\n");
    }
    else
    {
      pid_h3 = fork();
      if (pid_h3 == 0)
      {
        calcula_factorial(10,3);
        printf("HIJO3: He terminado!\n");
      }
      else
      {
        wait(&status);
        printf("PADRE: Mi hijo ha finalizado con un status %d\n", status);
        wait(&status);
        printf("PADRE: Mi hijo ha finalizado con un status %d\n", status);
        wait(&status);
        printf("PADRE: Mi hijo ha finalizado con un status %d\n", status);
        printf("PADRE: Fin!!\n");        
      }
    }
  }
  exit(0);
}

int calcula_factorial(int num, int hilo){
  if(num != 1){
    int factorial = num*calcula_factorial(num-1,hilo);
    printf("HIJO%d: fact(%d) = %d\n", hilo, num, factorial);
    return factorial;
  }else{
    printf("HIJO%d: fact(%d) = %d\n", hilo, num, 1);
    return 1;
  } 
  return 0; 
}