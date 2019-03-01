#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "color.h"

int result;
int *ptr_posiciones;
int n_hilos;
char ptr_filename[80];
char ptr_filename2[80];
pthread_mutex_t lock,lock2;
int cont_hilos;
long seconds;
long micros;
long seconds_open;
long micros_open;

int calcula_tam(){
    int tam = 1;
    FILE *inputFile = fopen(ptr_filename,"r");
    while (feof(inputFile) == 0 )
	{        
        if(fgetc(inputFile)=='\n'){
            tam++;
        }        
    }
    fclose(inputFile);
    return tam;
}

void* multiplica_seccion(void* data)
{    
    int pos;
    char num[10];	
    char num2[10];
	int resultado = 0;
    int pos_final;
    struct timeval start, end, start_open, end_open;
    FILE *inputFile;
	FILE *inputFile2;

    gettimeofday(&start_open,NULL);
        inputFile = fopen(ptr_filename,"r");
	    inputFile2 = fopen(ptr_filename2,"r");
    gettimeofday(&end_open,NULL);

    pthread_mutex_lock(&lock);
        pos = cont_hilos;
        cont_hilos--;
        seconds_open += (end_open.tv_sec - start_open.tv_sec);
        micros_open += ((seconds_open * 1000000) + end_open.tv_usec) - (start_open.tv_usec);
    pthread_mutex_unlock(&lock);

    if(inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", ptr_filename);
        return 0;
    }
	if(inputFile2 == NULL) {
        printf("Error al abrir el archivo %s\n", ptr_filename2);
        return 0;
    }

    if(pos == n_hilos-1){        
        fseek(inputFile,0,SEEK_END);
        pos_final = ftell(inputFile);
    }else{
        pos_final = *(ptr_posiciones+pos+1);
    }    

    fseek(inputFile,*(ptr_posiciones+pos),SEEK_SET);
    fseek(inputFile2,*(ptr_posiciones+pos+n_hilos),SEEK_SET);

    gettimeofday(&start,NULL);
    while (ftell(inputFile) != pos_final)
	{
		fgets(num,10,inputFile);
		fgets(num2,10,inputFile2);
		resultado += (atoi(num) * atoi(num2));
	}
    gettimeofday(&end,NULL);

    pthread_mutex_lock(&lock2);
        result += resultado;
        seconds += (end.tv_sec - start.tv_sec);
        micros += ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    pthread_mutex_unlock(&lock2);

    fclose(inputFile);
    fclose(inputFile2);
    return 0;
}

int main(int argc, char *argv[])
{         
    chdir("sources");   
	char filename[80] = "benchmark/";
    char filename2[80] = "benchmark/";
    strcat(filename,argv[1]);
    strcat(filename2,argv[2]);
    memcpy(ptr_filename, filename, 80*sizeof(char));
    memcpy(ptr_filename2, filename2, 80*sizeof(char));
    FILE *inputFile;
	inputFile = fopen(filename,"r");    
    int tam_vec = calcula_tam();    
    n_hilos = atoi(argv[3]);
    int numxhilo = tam_vec/n_hilos;
    int restantes = tam_vec%n_hilos;
    int posiciones[n_hilos*2];
    int objetivo = numxhilo;
    char character;
    char resudioant = '0';
    char segundo_archivo = '0';
    int cont = 1;
    int cont_saltos = 0;
    int cont_posi = 0;
    cont_hilos = n_hilos-1;
    posiciones[0] = 0;
    pthread_t threads_ids[n_hilos];

    printf("%sEl numero de hilos son: %s%d\n",BLANCO, PURPURA, n_hilos);
    printf("%sEl archivo 1 es: %s%s\n",BLANCO, CYAN, filename);
    printf("%sEl archivo 2 es: %s%s\n",BLANCO, CYAN, filename2);
    printf("%sTipo de procesamiento: %sparalelo\n",BLANCO, ROJO);

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
    }
    if (pthread_mutex_init(&lock2, NULL) != 0)
    {
        printf("\n mutex init failed\n");
    }
    
    while (feof(inputFile) == 0 )
	{        
        character = fgetc(inputFile);
        if(character != '\n'){
            cont_posi++;
        }else{
            cont_posi++;
            cont_saltos++;
            if(cont_saltos == objetivo){
                if(restantes != 0 && resudioant == '0')
                {                    
                    objetivo++;                    
                    resudioant = '1';
                    restantes--;                    
                }else{                    
                    posiciones[cont] = cont_posi;
                    cont++;
                    resudioant = '0';
                    objetivo = objetivo + numxhilo;
                }                    
            }
        }  

        if (feof(inputFile) != 0 && segundo_archivo == '0') {
            inputFile = fopen(filename2,"r");
            cont_posi = 0;
            cont_saltos = 0;
            objetivo = numxhilo;
            resudioant = '0';
            posiciones[cont] = 0;
            cont++;
            restantes = tam_vec%n_hilos;
            segundo_archivo = '1';
        }
              
    }

    ptr_posiciones = &posiciones[0];
    fclose(inputFile);

    for(int i = 0; i < n_hilos; i++)
    {
        int y = i;
        pthread_create(&threads_ids[i],NULL,multiplica_seccion,&y);
    }
    for(int i = 0; i < n_hilos; i++)
    {
        pthread_join(threads_ids[i],NULL);        
    }     
    printf("%sEl tiempo promedio que se tardo en realizar la operacion de multiplicación fue de:%s %lds (%ldms)\n", BLANCO, VERDE, seconds/n_hilos, micros/n_hilos);
    printf("%sEl tiempo promedio que se tardo en abrir los archivos fue de:%s %lds (%ldms)\n", BLANCO, VERDE, seconds_open/n_hilos, micros_open/n_hilos);
    printf("%sEl tiempo total que se tardo cada hilo fue:%s %lds (%ldms)\n", BLANCO, VERDE, (seconds_open+seconds)/n_hilos, (micros_open+micros)/n_hilos);
	printf("%sEl Resultado obtenido en la multiplicación paralela fue:%s %d\n", BLANCO,MARRON,result);
    pthread_mutex_destroy(&lock);
    pthread_mutex_destroy(&lock2);
}
