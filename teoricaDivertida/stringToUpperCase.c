#define _DEFAULT_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringToUpperCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++)
    {
        int letra = s[i]; //lo interpretamos como int usando el ASCII table
        if (letra >= 97) {
            //esta en minuscula
            int nuevaLetra = letra - 32; //lo cambiamos a mayuscula
            s[i] = nuevaLetra;
        }

    }
    
}

int main() {

    char* a = "Hola Carolaz";
    char* b = strdup(a);

    stringToUpperCase(b);

    printf("%s\n",b);

    return 0;
}
