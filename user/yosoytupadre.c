
#include "user.h"
#include "kernel/types.h"
//#include "stat.h"
//#include "fcntl.h"

int main(void) {
  int ppid = getppid();
  printf("Padre PID: %d\n", ppid);
  exit(0);
}