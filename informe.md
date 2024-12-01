Implementación de Permisos Básicos en xv6 (RISC-V)

Objetivo:

Implementar un sistema de permisos básicos en xv6 (risc) que permita modificar archivos para tener acceso de solo lectura o lectura/escritura, y agregar un nuevo permiso especial para hacerlo inmutable.

- agregamos al archivo file.h, int permissions;  ,permite guardar los permisos del archivo, indicando si es de solo lectura, escritura, ambos o inmutable.

- Modificamos el archivo sysfile ,especialmente sys_read, sys_write, y sys_open
sys_read y sys_write:
Verificación de si el archivo es legible (f->readable == 0) o escribible (f->writable == 0) antes de realizar las operaciones correspondientes.
sys_open:
Adición de validaciones para comprobar los permisos de lectura y escritura definidos en ip->permissions antes de abrir un archivo:
(ip->permissions & 1) == 0 verifica si el archivo no tiene permisos de lectura cuando se intenta abrir en modo O_RDONLY.
(ip->permissions & 2) == 0 verifica si el archivo no tiene permisos de escritura cuando se intenta abrir en modo O_WRONLY.

- modificamos filewrite en file.c: La validación de escritura respeta los permisos definidos en el perm del inode, asegurando que:

Archivos de solo lectura (permissions == 1) no puedan ser modificados.
Archivos inmutables (permissions == 5) tampoco puedan ser escritos.

- Implementamos la lógica de chmod,  La función recibe la ruta del archivo y el nuevo modo de permisos. Primero busca el archivo y verifica si tiene el permiso inmutable (5); si es así, no permite cambiar los permisos y devuelve un error. Si no es inmutable, actualiza los permisos en la estructura del archivo. Además, usamos bloqueos y transacciones para asegurar que los cambios sean seguros y consistentes. La función devuelve 0 si todo sale bien y -1 si ocurre un error.

- en syscall.h se define #define SYS_chmod  22

- en syscall.c agregamos 

[SYS_chmod]   sys_chmod,  
extern uint64 sys_chmod(void);

- creamos un archivo de prueba, test_1 , 

#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main() {
    int fd;
    char *archivo = "mi_archivo";

    printf("Creando archivo...\n");
    fd = open(archivo, O_CREATE | O_RDWR);
    if (fd < 0) {
        printf("Error al crear el archivo\n");
        exit(1);
    }

    printf("Escribiendo en archivo...\n");
    write(fd, "Contenido inicial\n", 18);
    close(fd);

    printf("Cambiando permisos a solo lectura...\n");
    if (chmod(archivo, PERMISSION_READ) < 0) {
        printf("Error al cambiar permisos a solo lectura\n");
        exit(1);
    }

    fd = open(archivo, O_WRONLY);
    if (fd >= 0) {
        printf("Error: Se pudo escribir con solo lectura\n");
        close(fd);
        exit(1);
    } else {
        printf("Correcto: No se puede escribir en el archivo de solo lectura\n");
    }

    printf("Volviendo a permisos de lectura y escritura...\n");
    if (chmod(archivo, PERMISSION_RW) < 0) {
        printf("Error al cambiar permisos a lectura y escritura\n");
        exit(1);
    } else {
        printf("Permisos cambiados correctamente a lectura y escritura\n");
    }

    fd = open(archivo, O_WRONLY);
    if (fd < 0) {
        printf("Error al abrir el archivo en modo escritura\n");
        exit(1);
    }

    printf("Escribiendo nuevo contenido...\n");
    write(fd, "Nuevo contenido\n", 16);
    close(fd);
    printf("Correcto: Se pudo escribir en el archivo con permisos de lectura y escritura\n");

    printf("Cambiando permisos a inmutable...\n");
    if (chmod(archivo, PERMISSION_IMMUTABLE) < 0) {
        printf("Error al cambiar permisos a inmutable\n");
        exit(1);
    }

    if (chmod(archivo, PERMISSION_RW) < 0) {
        printf("Correcto: No se pueden cambiar los permisos de un archivo inmutable\n");
    } else {
        printf("Error: Se cambiaron los permisos de un archivo inmutable\n");
    }

    fd = open(archivo, O_WRONLY);
    if (fd >= 0) {
        printf("Error: Se pudo escribir en el archivo inmutable\n");
        close(fd);
        exit(1);
    } else {
        printf("Correcto: No se puede escribir en el archivo inmutable\n");
    }

    printf("Pruebas completadas\n");
    exit(0);
}


- finalmenete al ejecutarlo obtenemos 
Creando archivo...
Escribiendo en archivo...
Cambiando permisos a solo lectura...
Correcto: No se puede escribir en el archivo de solo lectura
Volviendo a permisos de lectura y escritura...
Permisos cambiados correctamente a lectura y escritura
Escribiendo nuevo contenido...
Correcto: Se pudo escribir en el archivo con permisos de lectura y escritura
Cambiando permisos a inmutable...
Correcto: No se pueden cambiar los permisos de un archivo inmutable
Correcto: No se puede escribir en el archivo inmutable
Pruebas completadas
$ 

Dificultades encontradas y soluciones implementadas.

- uno de los errores que tuve :
  
user/test_1.c: In function 'main':
user/test_1.c:22:20: error: 'PERMISSION_READ' undeclared (first use in this function)
   22 |     chmod(archivo, PERMISSION_READ);
      |                    ^~~~~~~~~~~~~~~
user/test_1.c:22:20: note: each undeclared identifier is reported only once for each function it appears in
user/test_1.c:34:20: error: 'PERMISSION_RW' undeclared (first use in this function)
   34 |     chmod(archivo, PERMISSION_RW);
      |                    ^~~~~~~~~~~~~
user/test_1.c:46:20: error: 'PERMISSION_IMMUTABLE' undeclared (first use in this function)
   46 |     chmod(archivo, PERMISSION_IMMUTABLE);
      |                    ^~~~~~~~~~~~~~~~~~~~
make: *** [user/test_1.o] Error 1


Durante las pruebas con el archivo user/test_1.c, se produjo un error que indicaba que las constantes PERMISSION_READ, PERMISSION_RW y PERMISSION_IMMUTABLE no estaban declaradas.por lo que, se añadieron las siguientes definiciones en el archivo stat.h para establecer los permisos correspondientes:


#define PERMISSION_NONE       0
#define PERMISSION_READ       1
#define PERMISSION_WRITE      2
#define PERMISSION_RW         3
#define PERMISSION_IMMUTABLE  5


- Se presentó un error al utilizar las funciones argstr y argint, ya que no se estaba manejando adecuadamente el valor de retorno de estas funciones.
kernel/sysproc.c:105:38: error: void value not ignored as it ought to be
  105 |   if(argstr(0, path, MAXPATH) < 0 || argint(1, &perm) < 0)
  se resolvio La solución al error relacionado con las funciones argstr y argint consistió en asegurarse de que los valores de retorno de estas funciones se manejen adecuadamente.
