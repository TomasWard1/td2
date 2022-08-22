#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();

    printf("Aqui hay eco.\n");
    return 0;
}

