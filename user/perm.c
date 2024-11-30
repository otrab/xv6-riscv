#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"

char buf[512];

int
main(int argc, char *argv[])
{
  int fd;
  char *path;

  path = "file.txt";
  fd = open(path, O_CREATE | O_RDWR);

  // escribimos en el archivo
  int n = 20;
  char buf[n];
  strcpy(buf, "texto en el archivo");

  if (write(fd, buf, n) != n) {
    fprintf(2, "write error\n");
    exit(1);
  }
  printf("Escritura en archivo rw exitosa!\n");

  int c = chmod(path, 1);
  if (c < 0) {
    printf("chmod 1 falló\n");
    exit(1);
  }

  if (write(fd, buf, n) != n) {
    printf("Escritura en archivo r falló\n");
  } else {
    printf("Escritura en archivo r exitosa!\n");
  }

  c = chmod(path, 3);
  if (c < 0) {
    printf("chmod 3 falló\n");
    exit(1);
  }
  if (write(fd, buf, n) != n) {
    printf("Escritura en archivo rw falló\n");
    exit(1);
  }
  printf("Escritura en archivo rw exitosa!\n");



  c = chmod(path, 5);
  if (c < 0) {
    printf("chmod 5 falló\n");
    exit(1);
  }
  fd = open(path, O_WRONLY);
  if (write(fd, buf, n) != n) {
    printf("Escritura en archivo inmutable falló\n");
  }

  c = chmod(path, 3);
  if (c < 0) {
    printf("chmod 5->3 falló\n");
  }

  close(fd);
  exit(0);
}