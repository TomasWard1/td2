#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == 0) {
        printf("Soy Aureliano, hijo de Jose Arcadio.\n");
    } else if (pid1 > 0) {
        pid_t pid2 = fork();

        if (pid2 == 0) {
            printf("Soy Jose Arcadio, hijo de Jose Arcadio.\n");
        } else if (pid2 > 0) {
            pid_t pid3 = fork();

            if (pid3 == 0) {
                printf("Soy Amaranta, hija de Jose Arcadio.\n");
            } else if (pid3 > 0) {
                printf("Soy Jose Arcadio, padre de todas/os.\n");
            }
        }
    }
    return 0;
}
