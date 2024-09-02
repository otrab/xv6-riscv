
#include "user.h"
#include "kernel/types.h"
//#include "stat.h"
//#include "fcntl.h"

int main(void) {
  int ppid = getppid();
  printf("Padre PID: %d\n", ppid);

  // Probar la nueva llamada al sistema getancestor
  int ancestor_0 = getancestor(0);
  int ancestor_1 = getancestor(1);
  int ancestor_2 = getancestor(2);
  int ancestor_invalid = getancestor(10); // Número mayor que la cantidad de ancestros disponibles

  printf("Ancestro 0 (mismo proceso): %d\n", ancestor_0);
  printf("Ancestro 1 (padre): %d\n", ancestor_1);
  printf("Ancestro 2 (abuelo): %d\n", ancestor_2);
  printf("Ancestro 10 (inválido): %d\n", ancestor_invalid); // Debería imprimir -1

  exit(0);
}