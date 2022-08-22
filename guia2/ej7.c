#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int array[20];

static void* fillArray(__attribute__((unused)) void* _) {
    for(int i=10; i<20; i++) {
        array[i] = i+1;
    }
    return 0;
}

int main() {

    pthread_t thread;
    pthread_create(&thread, NULL, fillArray, NULL);

    for(int i=0; i<10; i++) {
        array[i] = i+1;
    }

    pthread_join(thread, NULL);

    for(int j=0; j<20; j++) {
        printf("%i\n", array[j]);
    }

    return 0;
}