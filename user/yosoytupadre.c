#include "kernel/types.h"
#include "user/user.h"

int main() {
    printf("Ancestor 0 (self): %d\n", getancestor(0));
    printf("Ancestor 1 (parent): %d\n", getancestor(1));
    printf("Ancestor 2 (grandparent): %d\n", getancestor(2));
    printf("Ancestor 3 (great-grandparent): %d\n", getancestor(3)); // Should return -1
    exit(0);
}
