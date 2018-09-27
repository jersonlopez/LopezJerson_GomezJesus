#ifndef STRUCT_PROC_H_
#define STRUCT_PROC_H_

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

#endif