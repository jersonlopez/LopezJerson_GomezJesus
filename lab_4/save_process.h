#ifndef SAVE_PROCESS_H_
#define SAVE_PROCESS_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct_proc.h"

#define MAX_SIZE 80

void save_process(FILE *outFile, proc *info_proc);

#endif