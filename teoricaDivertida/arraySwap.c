#define _BSD_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arraySwap(int* a, int size) {
    for (int i = 0; i < size/2; i++)
    {
        int aux = a[i];
        a[i] = a[size-1-i];
        a[size-1-1] = aux;
    }
    
}

int main() {

    int a[9] = {1,2,3,4,5,6,7,8,9};

    arraySwap(a,9);

    return 0;
}
