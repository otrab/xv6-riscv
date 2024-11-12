#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    char *addr = sbrk(0);  
    if (sbrk(4096) == (void *)-1) {
        printf("Error reservando memoria\n");
        exit(1);
    }

    if (mprotect(addr, 1) < 0) {
        printf("Error: mprotect falló\n");
        exit(1);
    }

    printf("Intentando escribir en memoria protegida...\n");
    *addr = 'A';  // Esto debería fallar
    printf("Valor en la dirección: %c\n", *addr);

    exit(0);
}
