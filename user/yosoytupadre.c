#include "user/user.h"
#include "kernel/types.h"
#include "kernel/stat.h"

//int main(void){
//  int ppid  = getppid();
//  printf("El ID del proceso padre es: %d\n", ppid);
//  exit(0);
//}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf( "Usage: yosoytupadre n\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    int pid = getancestor(n);

    if (pid < 0) {
        printf( "No hay ancestro para n = %d.\n", n);
    } else {
        switch(n) {
            case 0:
                printf("El ID del proceso actual es %d.\n", pid);
                break;
            case 1:
                printf("El ID del proceso padre es %d.\n", pid);
                break;
            case 2:
                printf("El ID del proceso abuelo es %d.\n", pid);
                break;
            default:
                printf("El ID del ancestro %d es %d.\n", n, pid);
                break;
        }
    }

    exit(0);
}
