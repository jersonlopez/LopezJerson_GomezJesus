#include "show_process.h"

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