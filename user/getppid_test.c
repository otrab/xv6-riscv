#include "kernel/types.h"
#include "user/user.h"

int getppid(void);

int main() {
    int ppid = getppid();
    printf("Parent PID: %d\n", ppid);
    exit(0);
}

