#define _BSD_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringToUpperCase(char* s) {
    // ?????????????????
}

int main() {

    char* a = "Hola Carola";
    char* b = strdup(a);

    stringToUpperCase(b);

    printf("%s\n",b);

    return 0;
}
