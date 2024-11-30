#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    char *addr = sbrk(0);  // Obtener la dirección actual del heap
    if (sbrk(4096) == (void *)-1) {
        printf("Error reservando memoria\n");
        exit(1);
    }

    // Desproteger la página inicialmente (debería permitir escritura)
    if (munprotect(addr, 1) == -1) {
        printf("munprotect falló\n");
        exit(1);
    }
    
    // Intentar escribir en memoria desprotegida
    *addr = 'A';
    printf("Escritura exitosa, valor: %c\n", *addr);

    // Proteger la misma página
    if (mprotect(addr, 1) == -1) {
        printf("mprotect falló\n");
        exit(1);
    }

    // Intentar escribir en memoria protegida (esto debería fallar)
    printf("Intentando escribir en memoria protegida...\n");
    *addr = 'B';  // Esto debería causar un fallo
    printf("Escritura en memoria protegida, valor: %c\n", *addr); // No debería llegar aquí

    exit(0);
}
