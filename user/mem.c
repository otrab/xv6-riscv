#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(2, "usage: mem <value>\n");
        exit(1);
    }
    int *p;
    p = malloc(sizeof(int));
    if(p == 0){
        fprintf(2, "malloc failed\n");
        exit(1);
    }
    printf("(%d) addr pointed to by p: %p\n", getpid(), p);
    *p = atoi(argv[1]);
    while(1){
        sleep(10); // sleep for a short time
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    exit(0);
}