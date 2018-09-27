#ifndef LOAD_PROCESS_H_
#define LOAD_PROCESS_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"
#include "struct_proc.h"

#define MAX_SIZE 80

void load_process(char *address, proc *info_proc);

#endif