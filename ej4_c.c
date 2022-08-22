#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int data = 0;
    pid_t pid = fork();

    if (pid == 0) {
        data++;
        printf("Valor de data del hijo: %d\n", data);
    } else if (pid > 0) {
        printf("Valor de data del padre: %d\n", data);
    }
    return 0;
}
