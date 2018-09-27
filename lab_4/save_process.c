#include "save_process.h"

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