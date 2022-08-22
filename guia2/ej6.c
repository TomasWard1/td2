#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        sleep(10);
        printf("Hola.\n");
    }
    return 0;
}
