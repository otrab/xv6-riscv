# Informe de Tarea 4: Implementación de Permisos Básicos en xv6

## Introducción

En esta tarea, se ha extendido el sistema operativo xv6 para incorporar un sistema de permisos en los archivos. Los permisos implementados permiten definir archivos como de solo lectura, lectura/escritura y agregar un atributo de inmutabilidad. Estas mejoras brindan un mayor control sobre el acceso y modificación de los archivos en el sistema.

## Modificaciones Realizadas

### 1. Estructura del Inode

Se añadió un campo `permissions` en la estructura del inode para almacenar los permisos asociados a cada archivo. Este campo utiliza un entero donde:

- `0`: Sin permisos de lectura ni escritura.
- `1`: Permiso de lectura.
- `2`: Permiso de escritura.
- `3`: Permisos de lectura y escritura.
- `5`: Archivo inmutable.

Al crear un nuevo inode, el valor predeterminado de `permissions` se establece en `3` (lectura y escritura).

### 2. Operaciones de Lectura y Escritura

Se modificaron las funciones de lectura y escritura para que respeten los permisos establecidos en el inode. Por ejemplo, si un archivo está marcado como de solo lectura, las operaciones de escritura son rechazadas adecuadamente.

### 3. Implementación del Permiso de Inmutabilidad

Se agregó un permiso especial que, cuando está activo (`permissions` con valor `5`), impide cualquier modificación al archivo, incluso si tiene permisos de escritura. Este permiso también restringe cambios futuros en los permisos del archivo.

### 4. Nueva Llamada al Sistema: `chmod`

Se implementó la syscall `chmod` que permite cambiar los permisos de un archivo específico. Esta función verifica que el archivo no sea inmutable antes de modificar sus permisos.

### 5. Actualización de Comandos de Usuario

Se añadió el programa de usuario `perm.c` para probar las funcionalidades de permisos. Este programa crea un archivo, modifica sus permisos y verifica el comportamiento esperado en cada caso.

## Pruebas Realizadas

Se llevaron a cabo pruebas exhaustivas utilizando el programa `perm.c`, el cual realiza las siguientes acciones:

1. Crea un archivo con permisos de lectura y escritura.
2. Escribe en el archivo y verifica el éxito de la operación.
3. Cambia los permisos a solo lectura y verifica que la escritura falle.
4. Restaura los permisos a lectura y escritura y confirma que la escritura sea exitosa.
5. Establece el permiso de inmutabilidad y verifica que la escritura falle.
6. Intenta cambiar los permisos de un archivo inmutable y confirma que la operación falle.

Estas pruebas confirmaron que el sistema de permisos funciona según lo esperado.

## Conclusión

La implementación del sistema de permisos en xv6 proporciona un control más granular sobre el acceso y modificación de archivos. Las modificaciones realizadas, junto con las pruebas efectuadas, aseguran que el sistema opere de manera estable y segura, respetando las restricciones de permisos establecidas.
