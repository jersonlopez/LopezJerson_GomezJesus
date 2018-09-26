#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 80

typedef struct p {
	int pid;
	char name[MAX_SIZE];
	char state[MAX_SIZE];
	char vmsize[MAX_SIZE];
	char vmdata[MAX_SIZE];
	char vmexe[MAX_SIZE];
	char vmstk[MAX_SIZE];
	int voluntary_ctxt_switches;
	int nonvoluntary_ctxt_switches;
} proc;

void split(char *original, char *partition, char character){
    char tag = MAX_SIZE;
    for(int i=0;i<MAX_SIZE;i++){
        if(*(original+i) != character){
            if(tag==MAX_SIZE){
                *(partition+i) = *(original+i);
            }else{
                *(original+i-tag-1) = *(original+i);                
            }                
        }else{            
            tag = i;
        }
    }
};

void load_process(char *address, proc *info_proc){
    char character;
    char name[MAX_SIZE];
    char value[MAX_SIZE];
    FILE *inputFile;
    printf("Direccion a abrir %s\n", address);
    inputFile = fopen(address,"r");

    if ( inputFile == NULL) {
        printf("Error al abrir el archivo %s\n", address);
    }

    int i = 0;
    while((character = fgetc(inputFile)) != EOF){
        if(character != '\n'){
            if(i<MAX_SIZE){
                value[i] = character;
                i++;
            }            
        }else{
            split(value,name,':');
            i = 0;
            if (strstr(name, "Pid")){
                info_proc->pid=atoi(value);
            }else if (strstr(name, "Name")){
                strcpy(info_proc->name,value);
            }else if (strstr(name, "State")){
                strcpy(info_proc->state,value);                
            }else if (strstr(name, "VmSize")){
                strcpy(info_proc->vmsize,value);                
            }else if (strstr(name, "VmData")){
                strcpy(info_proc->vmdata,value);                
            }else if (strstr(name, "VmStk")){
                strcpy(info_proc->vmstk,value);                
            }else if (strstr(name, "VmExe")){
                strcpy(info_proc->vmexe,value);                
            }else if (strstr(name, "nonvoluntary_ctxt_switches")){
                info_proc->nonvoluntary_ctxt_switches=atoi(value);                
            }else if (strstr(name, "voluntary_ctxt_switches")){
                info_proc->voluntary_ctxt_switches=atoi(value);
            }   
            
            memset(name,0,MAX_SIZE);
            memset(value,0,MAX_SIZE);
        }
    }
    fclose(inputFile);
}

void show_process(proc *info_proc){
    printf("Pid: %d\n", info_proc->pid);
    printf("Nombre del proceso: %s\n", info_proc->name);
    printf("Estado del proceso: %s\n", info_proc->state);
    printf("Tamaño total de la imagen de memoria: %s\n", info_proc->vmsize);
    printf("Tamaño de la sección de memoria TEXT: %s\n", info_proc->vmexe);
    printf("Tamaño de la sección de memoria DATA: %s\n", info_proc->vmdata);
    printf("Tamaño de la sección de memoria STACK: %s\n", info_proc->vmstk);
    printf("Voluntarios: %d\n", info_proc->nonvoluntary_ctxt_switches);
    printf("No voluntarios: %d\n", info_proc->voluntary_ctxt_switches);   
    printf("_________________________________________________\n");
}

void save_process(FILE *outFile, proc *info_proc){
    char cadena[MAX_SIZE+100];
    sprintf(cadena,"Pid: %d\n", info_proc->pid);
    fputs( cadena, outFile );
    sprintf(cadena,"Nombre del proceso: %s\n", info_proc->name);
    fputs( cadena, outFile );
    sprintf(cadena,"Estado del proceso: %s\n", info_proc->state);
    fputs( cadena, outFile );
    sprintf(cadena,"Tamaño total de la imagen de memoria: %s\n", info_proc->vmsize);
    fputs( cadena, outFile );
    sprintf(cadena,"Tamaño de la sección de memoria TEXT: %s\n", info_proc->vmexe);
    fputs( cadena, outFile );
    sprintf(cadena,"Tamaño de la sección de memoria DATA: %s\n", info_proc->vmdata);
    fputs( cadena, outFile );
    sprintf(cadena,"Tamaño de la sección de memoria STACK: %s\n", info_proc->vmstk);
    fputs( cadena, outFile );
    sprintf(cadena,"Voluntarios: %d\n", info_proc->nonvoluntary_ctxt_switches);
    fputs( cadena, outFile );
    sprintf(cadena,"No voluntarios: %d\n", info_proc->voluntary_ctxt_switches);
    fputs( cadena, outFile );
    fputs( "_________________________________________________\n", outFile );
}

int main(int argc, char *argv[])
{  
    FILE *outFile;        
    char address[MAX_SIZE];
    char name[MAX_SIZE] = "psinfo-report";
    proc proc_info[10];
    switch(argc){
        case 2:            
            sprintf(address, "/proc/%s/status", argv[1]);
            load_process(address, proc_info);
            show_process(proc_info);
        break;

        case 1:
            printf("Ingrese el numero del proceso del proceso");
            return 0;
        break;

        default:
            if (strstr(argv[1], "-l")){
                for(int i=0;i<argc-2;i++){
                    sprintf(address, "/proc/%s/status", argv[i+2]);
                    load_process(address, proc_info);
                    show_process(proc_info);
                }
            }else if (strstr(argv[1], "-r")){
                for(int i=0;i<argc-2;i++){
                    strcat(name,"-");                    
                    strcat(name,argv[i+2]);
                }
                strcat(name,".info");
                outFile = fopen (name, "w" );
                for(int i=0;i<argc-2;i++){
                    sprintf(address, "/proc/%s/status", argv[i+2]);
                    load_process(address, proc_info);
                    save_process(outFile,proc_info);
                }
                fclose(outFile);
            }else {
                printf("Ingreso mal el comando");
            }
        break;                    
    }
    return 0;
};

// uppercase
// lowercase
// digits