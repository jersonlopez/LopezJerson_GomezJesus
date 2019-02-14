
/*
Ejemplo tomado y levemente (casi nada) adaptado de:
-> https://vcansimplify.wordpress.com/2013/03/08/pthread-tutorial-simplified
*/

#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

int result;
int *ptr_posiciones;
int n_hilos;
char filename[80];
char filename2[80];

void* say_hello(void* data)
{
    char *str;
    str = (char*)data;
    
        printf(" puedo acceder a esta variable global%d\n",result);
    
    
}

void* open_file2(void* data)
{    
    int *pos = (int*)data;
    
    printf("error %d\n",*pos);
    //printf("error %d\n",*(ptr_posiciones)+*pos);

    //printf("la posición del %d valor es %d\n",i+1,posiciones[i]);
        //fgets(num,100,inputFile);
        //printf("lo que hay en el vector es %s\n",num);
    
    char num[10];	
    char num2[10];
	int resultado = 0;
	
	FILE *inputFile;
	FILE *inputFile2;
	inputFile = fopen(filename,"r");
	inputFile2 = fopen(filename2,"r");
    fseek(inputFile,*(ptr_posiciones)+*pos,SEEK_SET);
    fseek(inputFile2,*(ptr_posiciones)+*pos+n_hilos,SEEK_SET);

    if(inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", filename);
        return 0;
    }
	if(inputFile2 == NULL) {
        printf("Error al abrir el archivo %s\n", filename2);
        return 0;
    }

    while (feof(inputFile) == 0 )
	{
		fgets(num,10,inputFile);
		fgets(num2,10,inputFile2);
		resultado += (atoi(num) * atoi(num2));
        printf("Resultado: %d\n",resultado);
	}

	printf("Resultado final: %d\n",resultado);

    fclose(inputFile);
    fclose(inputFile2);
    return 0;
}

void main()
{
    //strcat(filename,"_stats.txt");
    //pthread_create(&t1,NULL,open_file,"hello.txt");
    //pthread_create(&t1,NULL,open_file2,"1");
    //pthread_create(&t2,NULL,say_hello,"The CPU is mine now :D");
    
    char num[10];	
	//char num2[100];	
	char filename[80] = "sources/benchmark/vec_10_1_a.txt";
    char filename2[80] = "sources/benchmark/vec_10_1_b.txt";
    FILE *inputFile;
	//FILE *inputFile2;
	inputFile = fopen(filename,"r");
        //fseek(inputFile,0,SEEK_END);

	//fgets(num,100,inputFile);

    int expo = 10;
    n_hilos = 9;
    int numxhilo = expo/n_hilos;
    int restantes = expo%n_hilos;
    int posiciones[n_hilos*2];
    int objetivo = numxhilo;
    char character;
    char resudioant = '0';
    char segundo_archivo = '0';
    int cont = 1;
//    printf("Resultado %ld\n",ftell(inputFile));
  //  printf("num x hilo %d\n",numxhilo);
    //printf("modulo %d\n",restantes);
    int cont_saltos = 0;
    int cont_posi = 0;
    posiciones[0] = 0;
    pthread_t threads_ids[n_hilos];

    while (feof(inputFile) == 0 )
	{        
        character = fgetc(inputFile);
        if(character != '\n'){
            cont_posi++;
        }else{
            cont_posi++;
            cont_saltos++;
            if(cont_saltos == objetivo){
                if(restantes != 0 && resudioant == 0)
                {
                    objetivo++;
                    resudioant = 1;
                    restantes--;
                }else{
                    posiciones[cont] = cont_posi;
                    cont++;
                    resudioant = 0;
                    objetivo = objetivo + numxhilo;
                }                    
            }
        }  

        if (feof(inputFile) != 0 && segundo_archivo == '0') {
            inputFile = fopen(filename2,"r");
            cont_posi = 0;
            cont_saltos = 0;
            objetivo = numxhilo;
            resudioant = 0;
            posiciones[cont] = 0;
            cont++;
            restantes = expo%n_hilos;
            segundo_archivo = '1';
        }
              
    }
    ptr_posiciones = &posiciones[0];
    fclose(inputFile);

    for(int i = 0; i < n_hilos*2; i++)
    {
        printf("la posición del %d valor es %d\n",i+1,posiciones[i]);
        //fgets(num,100,inputFile);
        //printf("lo que hay en el vector es %s\n",num);
    }

    for(int i = 0; i < n_hilos; i++)
    {
        printf("i vale %d\n",i);
        pthread_create(&threads_ids[i],NULL,open_file2,&i);
    }
    for(int i = 0; i < n_hilos; i++)
    {
        pthread_join(threads_ids[i],NULL);        
    }  
}
