
#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    printf("Mi padre es: %d\n", getppid());
    exit(0);
}