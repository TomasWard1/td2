#include <stdio.h>
#include <stdlib.h>

int len(char *s)
{
    int contador = 0;
    for (contador; s[contador] != '\0'; contador++);
    return contador;
}

char *copy(char *s)
{
    return s;
}

void replaceChar(char *s, char old, char new)
{
    //s es un puntero que apunta al primer char de "Ramon"
    
   
    char* puntero;
    puntero = s;


    printf("Puntero apunta a: %s\n",puntero);
    printf("Len puntero: %i\n",len(puntero));
    for (int i = 0; i < len(puntero); i++)
    {
        printf("Indice: %i\n",i);
        printf("Valor del char: %c\n\n",puntero[i]);

        if (puntero[i] == old) {
            puntero[i] = new;
        }
    }

       printf("Resultado final: %s \n",puntero);



}

char *concatenate(char *s1, char *s2)
{

    // COMPLETAR

    return 0;
}

int main()
{
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char *s1 = "Ramon";
    char *s2 = "Ricardo";

    printf("La string \"%s\" mide %i\n", s1, len(s1));
    printf("La string \"%s\" mide %i\n", s2, len(s2));

    char *copyS1 = copy(s1);
    char *copyS2 = copy(s2);

    printf("La string \"%s\" es una copia de %s\n", copyS1, s1);
    printf("La string \"%s\" es una copia de %s\n", copyS2, s2);

    replaceChar(copyS1, 'a', 'o');
    replaceChar(copyS2, 'R', 'T');

    printf("Sobre la string \"%s\" remplazo 'a' por 'o': %s\n", s1, copyS1);
    printf("Sobre la string \"%s\" remplazo 'R' por 'T': %s\n", s2, copyS2);

    /*
      printf("Concateno \"%s\" con \"%s\":",copyS1, copyS2);

      char* concat = concatenate(copyS1, copyS2);

      printf(" \"%s\"\n",concat);

      free(concat);

      // */

    return 0;
}
