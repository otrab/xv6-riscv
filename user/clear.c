#include "kernel/types.h" // for basic types like int
#include "kernel/stat.h"  // for file stats, if needed
#include "user/user.h"

int
main()
{
    //this clears the terminal
    printf("\033[2J\033[1;1H");
    exit(0);
}