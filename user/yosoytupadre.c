#include "user/user.h"
#include "kernel/types.h"
#include "kernel/stat.h"

int main(void){
  int ppid  = getppid();
  printf("El ID del proceso padre es: %d\n", ppid);
  exit(0);
}


