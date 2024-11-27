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
            exit(1);  // Salida con código de error
        }
        if(pid == 0) {
            // Código para el proceso hijo
            printf("Ejecutando proceso %d con PID %d\n", n, getpid());
            sleep(100); // Dormir por algunos "ticks" para observar la ejecución
            exit(0); // Termina el proceso hijo con salida exitosa
        }
    }

    for(n = 0; n < 20; n++) {
        wait(0); // Espera a que todos los procesos hijos terminen
    }

    exit(0); // Termina el proceso padre con salida exitosa
}

