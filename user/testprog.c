#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"



int main(void) {
    int n;
    int pid;

    for(n = 0; n < 20; n++) {
        pid = fork();
        if(pid < 0) {
            printf("Error al hacer fork\n");
            exit(1); 
        }
        if(pid == 0) {
            sleep(10 * (n+1));
            printf("Ejecutando proceso %d con PID %d\n", n, getpid());
            exit(0);        
      }
     }

    for(n = 0; n < 20; n++) {
        wait(0);
    }

    exit(0); 
}

