# Tarea 3: Protección de Memoria en xv6

## Introducción

En esta tarea, se implementaron las llamadas al sistema `mprotect` y `munprotect` en xv6 para gestionar la protección y desprotección de regiones de memoria. Esto permite cambiar dinámicamente los permisos de páginas de memoria de un proceso, habilitando o deshabilitando la escritura.

## Implementación

Se añadieron las funciones `mprotect` y `munprotect` en `kernel/vm.c` para modificar las tablas de páginas. Se agregaron las entradas correspondientes en `syscall.c` y `sysproc.c` para su uso en espacio de usuario.

## Pruebas

Para validar la implementación, se diseñaron dos programas:

### `mtest.c`

Este programa reserva una página de memoria, la protege con `mprotect` y luego intenta escribir en ella, generando un fallo de página esperado.

![mtest](./mtest.png)

### `muntest.c`

Este programa reserva una página, primero desprotege la memoria con `munprotect` y confirma que la escritura funciona. Luego, protege la misma página con `mprotect` y vuelve a intentar escribir, generando un fallo.

![muntest](./muntest.png)

## Resultados

Ambos programas demostraron que las funciones `mprotect` y `munprotect` funcionan correctamente:
- `mprotect` previene escrituras en memoria protegida.
- `munprotect` permite deshabilitar esta protección.

## Conclusión

La tarea fue completada con éxito. Las pruebas confirmaron que las funciones manejan adecuadamente los permisos de memoria, generando los fallos esperados al intentar violar las restricciones.
