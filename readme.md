# Tarea 3: Protección de Memoria en xv6

## Objetivo
Modificar xv6 para implementar un sistema de protección de memoria que permita marcar regiones de memoria como solo lectura.

### Modificaciones Requeridas
1. **Incorporar Funciones de Protección**
   - Implementar las funciones `mprotect` y `munprotect`.

2. **Modificación de la Tabla de Páginas**
   - Actualizar la tabla de páginas para incluir un bit que indique si una página es de solo lectura.

### Funciones a Implementar
- **mprotect(void *addr, int len)**
  - Permite marcar una región de memoria, comenzando en `addr` con longitud `len`, como solo lectura.
  - Calcular cuántas páginas están involucradas y modificar el bit W de cada PTE para deshabilitar la escritura.

- **munprotect(void *addr, int len)**
  - Permite revertir la protección de solo lectura de una región de memoria, volviéndola de nuevo de lectura/escritura.
  - Similar a `mprotect`, pero restaura el permiso de escritura para las páginas afectadas.

### Manejo de Errores
- Las funciones deben manejar errores, como:
  - Direcciones inválidas para `addr` o `len`.
  - Direcciones que no pertenecen al proceso.
  - Otros errores deducibles.

## Consejos (Hints)

   -  Revisar el código existente en xv6 para entender cómo se gestionan las tablas de páginas.
   - Documentar adecuadamente las modificaciones realizadas.

## Entrega

   -  Código fuente modificado de xv6.
    - Programa de prueba.
   -  Informe (archivo "README.md") detallando:
    -    Funcionamiento y lógica de la protección de memoria.
    -    Explicación de las modificaciones realizadas.
- Dificultades encontradas y soluciones implementadas.

## Instrucciones de Entrega

   - Crear una nueva rama en tu fork de xv6 para esta tarea.
    - Realizar cambios y commits en esta rama.
  -   Subir la rama a tu fork en GitHub.
  -  Proporcionar en el buzón de WebC:
  -  El enlace a tu rama en GitHub (https://github.com/tu_usuario/xv6-riscv/tree/nombre_apellido_t3)
  -  Tu informe debe ser el archivo README.

## Evaluación

- (2 puntos) Implementación de mprotect: dados un base addr y una longitud len, calcular cuántas páginas están involucradas, y recorrerlas en la tabla de páginas y modificar el bit W de cada PTE para deshabilitar la escritura.
- (2 puntos) Implementación de munprotect: Similar a mprotect, pero esta llamada debe restaurar el permiso de escritura para las páginas afectadas.
- (2 puntos) Manejo de errores: Por ejemplo, si addr o len son inválidos, las llamadas deben fallar y devolver un error. O si apuntan a direcciones que no son del proceso, o ¡cualquier otro error que deduzcan!

## Ejemplo de Prueba
```c
#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
    char *addr = sbrk(0);  // Obtener la dirección actual del heap
    sbrk(4096);  // Reservar una página
    // Intentar proteger la nueva página
    if (mprotect(addr, 1) == -1) {
        printf("mprotect falló\n");
    }
    // Intentar escribir en la página protegida
    char *ptr = addr;
    *ptr = 'A';  // Esto debería fallar si la protección es exitosa
    printf("Valor en la dirección: %c\n", *ptr);  // Verificar el valor
    return 0;
}

