#include "load_process.h"

void load_process(char *address, proc *info_proc){
    char character;
    char name[MAX_SIZE];
    char value[MAX_SIZE];
    FILE *inputFile;
    inputFile = fopen(address,"r");

    if ( inputFile == NULL) {
        printf("Error al abrir el archivo %s que contiene la información del proceso, ", address);
        printf("es posible que el proceso no exista o se equivoco al ingresar el proceso proceso\n");
        info_proc->pid=-1;
        return;
    }

    info_proc->pid=0;
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
            if (strstr(name, "Pid")&&info_proc->pid == 0){
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