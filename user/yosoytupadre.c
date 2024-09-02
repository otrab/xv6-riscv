#include "user/user.h"
#include "kernel/types.h"
#include "kernel/stat.h"

int main(void){
printf("id del proceso abuelo: %d\n", getpid());
 int pid = fork();
 if (pid == 0){
  printf("id del proceso padre: %d\n", getpid());
  int ppid= fork();
  if (ppid ==0){
  printf("id del proceso actual: %d\n", getpid());
   } else {
   wait(0);
   }
  } else {
   wait(0);
} return 0;
}


