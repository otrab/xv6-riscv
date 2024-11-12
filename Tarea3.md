# Tarea 3: Implementación de Protección de Memoria en xv6

## Introducción

En esta tarea, se implementaron las llamadas al sistema `mprotect` y `munprotect` para permitir la protección y desprotección de páginas de memoria en xv6. Estas funciones permiten modificar los permisos de las páginas de memoria en tiempo de ejecución, estableciendo regiones como solo lectura y revirtiendo esta protección cuando sea necesario.

## Archivos Modificados

- **`kernel/proc.c`**: Implementación de las funciones `mprotect` y `munprotect`.
- **`kernel/syscall.c`**: Registro de las nuevas llamadas al sistema.
- **`kernel/syscall.h`**: Asignación de números de sistema.
- **`user/user.h`**: Declaración de las funciones para uso en espacio de usuario.
- **`user/usys.pl`**: Inclusión de las nuevas llamadas en las entradas del sistema.
- **`user/mtest.c`**: Programa para validar la funcionalidad de las llamadas al sistema.

## Detalles de la Implementación

### `mprotect`

Esta función permite marcar páginas de memoria como solo lectura. Recibe dos parámetros:
- `addr`: Dirección de inicio de la región de memoria.
- `len`: Número de páginas a proteger.

### `munprotect`

Rehabilita la escritura en las páginas de memoria previamente protegidas. Recibe los mismos parámetros que `mprotect`.

### Manejo de Errores

Ambas funciones validan las siguientes condiciones:
1. La dirección debe estar alineada a un límite de página.
2. No se debe exceder el rango de memoria del proceso.
3. El rango de páginas debe ser válido.

En caso de incumplimiento, retornan `-1`.

## Pruebas

Se diseñó el programa `mtest.c` para probar las siguientes situaciones:
1. Proteger una página de memoria y verificar que las escrituras generen errores.
2. Desproteger la página y confirmar que las escrituras sean exitosas.
3. Validación de errores en casos límite, como direcciones no válidas o rangos fuera de los límites.

### Instrucciones de Ejecución

1. Compilar el sistema con `make qemu`.
2. Ejecutar `mtest` desde el shell para verificar la funcionalidad.

## Resultados

Las pruebas demostraron que las funciones `mprotect` y `munprotect` operan correctamente en condiciones normales y excepcionales. Las páginas protegidas no permiten escrituras y generan fallos esperados. La reversión de protección con `munprotect` restaura la funcionalidad de escritura.

## Conclusión

La tarea logró implementar exitosamente mecanismos de protección de memoria en xv6, mejorando la seguridad del sistema mediante la gestión dinámica de permisos.

