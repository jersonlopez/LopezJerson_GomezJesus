#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *original, char *partition, char character){
    char tag = 80;
    for(int i=0;i<80;i++){
        if(*(original+i) != character){
            if(tag==80){
                *(partition+i) = *(original+i);
            }else{
                *(original+i-tag-1) = *(original+i);                
            }                
        }else{            
            tag = i;
        }
    }
};

int main()
{
    char filename[80];
    char address[80]= "/proc/";
    char name[80];
    char value[80];
    char character;
    int i = 0;
    FILE *inputFile;

    printf("Ingrese el numero del proceso: ");
    gets(filename);
    strcat(filename,"/status");
    strcat(address,filename);

    printf("direccion a abrir %s\n", address);
    inputFile = fopen(address,"r");

    if ( inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", address);
        return 0;
    }

    while((character = fgetc(inputFile)) != EOF){
        if(character != '\n'){
            if(i<80){
                value[i] = character;
                i++;
            }            
        }else{
            split(value,name,':');
            i = 0;
            if (strstr(name, "Name")){
                printf("Nombre del proceso: %s\n", value);
            }else if (strstr(name, "State")){
                printf("Estado del proceso: %s\n", value);
            }else if (strstr(name, "VmSize")){
                printf("Tamaño total de la imagen de memoria: %s\n", value);
            }else if (strstr(name, "VmData")){
                printf("Tamaño de la sección de memoria TEXT: %s\n", value);
            }else if (strstr(name, "VmStk")){
                printf("Tamaño de la sección de memoria DATA: %s\n", value);
            }else if (strstr(name, "VmExe")){
                printf("Tamaño de la sección de memoria STACK: %s\n", value);
            }else if (strstr(name, "nonvoluntary_ctxt_switches")){
                printf("Voluntarios: %s\n", value);
            }else if (strstr(name, "voluntary_ctxt_switches")){
                printf("No voluntarios: %s\n", value);
            }   
            
            memset(name,0,80);
            memset(value,0,80);
        }
    }
    fclose(inputFile);
    
};

// uppercase
// lowercase
// digits