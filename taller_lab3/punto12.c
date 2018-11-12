#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
void crea_array(char argumentos[],char* arg[], char nombre[]);
int main()
{
  int pid;
  char programa[80];
  char nombre[20];
  memset(programa, '\0', 80);
  char *arg[10];
  printf("Ingrese el nombre del programa a ejecutar y sus argumentos: ");
  fgets(programa,80,stdin);
  crea_array(programa,arg,nombre);  
  if ((pid = fork()) == 0) {
  		execvp(nombre,arg);
  }
  else {
    wait(&pid);
    printf("exec finalizado\n");
  }
  return 0;
}

void crea_array(char argumentos[],char *arg[],char nombre[]){
  int cont1 = 0;
  int cont2 = 0;
  char matriz[20][20];
  memset( matriz, '\0', 400 );
  for(int i = 0; i < 80; i++)
  {
    if(argumentos[i] != ' '){      
      if(argumentos[i] == '\0' || argumentos[i] == '\n'){
        if(cont1!=0){
          arg[cont1] = matriz[cont1];
        }         
        i = 80;
      }else{
        matriz[cont1][cont2] = argumentos[i];
        cont2++;
      }
    }else{      
      arg[cont1] = matriz[cont1];                  
      cont2 = 0;
      cont1++;
    }    
  }
  strcpy(nombre,matriz[0]);
}