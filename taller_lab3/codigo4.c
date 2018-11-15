#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main () {
    int i;
    int numHijos = 3;
    int status;
    pid_t pid;
    for (i = 0; i < numHijos; i++) {
        pid = fork();
        if (pid == -1) {
            /* Error */
            printf("No fue posible crear un hijo\n");
            return -1;
        }
        if (pid == 0) {
            printf("Soy el hijo #%d con PID: %d\n",i+1, getpid());
            exit(0);
        }
    }
    wait(&status);
    return 0;
}