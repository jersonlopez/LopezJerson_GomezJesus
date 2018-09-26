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

void show_process(char *address){
    char character;
    char name[80];
    char value[80];
    FILE *inputFile;
    printf("Direccion a abrir %s\n", address);
    inputFile = fopen(address,"r");

    if ( inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", address);
    }

    int i = 0;
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
}

int main(int argc, char *argv[])
{  
    char address[80];
    
    switch(argc){
        case 2:
            sprintf(address, "/proc/%s/status", argv[1]);
            show_process(address);
        break;

        case 1:
            printf("Ingrese el numero del proceso del proceso");
            return 0;
        break;

        default:
            switch(*argv[1]){
                case '-l':
                break;

                case '-r':
                break;

                default:
                    printf("Ingreso mal el comando");
                return 0;
            }
        break;        
    }
    return 0;
};

// uppercase
// lowercase
// digits