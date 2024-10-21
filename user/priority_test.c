#include "kernel/types.h" // for basic types like int
#include "kernel/stat.h"  // for file stats, if needed
#include "user/user.h"

int 
main()
{  
  int n = 20;
  printf("Creando %d procesos nuevos\n", n);
  for(int i = 0; i < 20; i++) {
    int nuevo_proceso = fork();
    if(nuevo_proceso == 0) { //Child
      //sleep(i);
      printf("Ejecutando proceso N° %d con pid %d\n", i, getpid());
      exit(0);
    }
  }
  
  for(int i = 0; i < n; i++) {
    wait(0);
  }
  exit(0);
}