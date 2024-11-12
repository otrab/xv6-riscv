#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
    char *addr = sbrk(0);  // Obtener la dirección actual del heap
    if (sbrk(4096) == (void *)-1) {  // Reservar una página
        printf("Error reservando memoria\n");
        exit(1);
    }

    // Proteger la página recién reservada
    if (mprotect(addr, 1) < 0) {
        printf("Error: mprotect falló\n");
        exit(1);
    }

    printf("Intentando leer de memoria protegida (debería funcionar)...\n");
    char val = *addr;  // Leer debería ser seguro
    printf("Lectura exitosa, valor: %c\n", val);

    printf("Intentando escribir en memoria protegida (debería fallar)...\n");
    *addr = 'A';  // Esto debería causar un fallo

    printf("Escritura exitosa, valor en la dirección: %c\n", *addr);  // No debería llegar aquí

    exit(0);
}
