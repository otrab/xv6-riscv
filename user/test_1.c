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

