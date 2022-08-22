#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();

    printf("TD2.\n");
    return 0;
}
