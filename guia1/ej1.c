#include <stdio.h>
#include <stdlib.h>


int len(char *s)
{
    int contador = 0;
    for (contador; s[contador] != '\0'; contador++)
        ;
    return contador;
}

char *copy(char *s)
{//

    char *p = (char *)malloc(sizeof(char) * len(s) + 1);

    int i = 0;
    for (i; s[i] != '\0'; i++)
    {
        p[i] = s[i];
    }

    p[i] = '\0';

    return p;
}

void replaceChar(char *s, char old, char new)
{
    for (int i = 0; i < len(s); i++)
    {
        if (s[i] == old)
        {
            s[i] = new;
        }
    }
}

char *concatenate(char *s1, char *s2)
{

    int len1 = len(s1);
    int len2 = len(s2);
    char *p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

    int iGlobal = 0;
    for (iGlobal; s1[iGlobal] != '\0'; iGlobal++)
    {
        p[iGlobal] = s1[iGlobal];
    }

    for (int i = 0; s2[i] != '\0'; i++, iGlobal++)
    {
        p[iGlobal] = s2[i];
    }

     p[iGlobal] = '\0';

    free(s1);
    free(s2);

    return p;
}

int main()
{
    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char *s1 = "Tomas";
    char *s2 = "Ward";

    printf("La string \"%s\" mide %i\n", s1, len(s1));
    printf("La string \"%s\" mide %i\n", s2, len(s2));

    char *copyS1 = copy(s1);
    char *copyS2 = copy(s2);

    printf("La string \"%s\" es una copia de %s\n", copyS1, s1);
    printf("La string \"%s\" es una copia de %s\n", copyS2, s2);

    replaceChar(copyS1, 'a', 'o');
    replaceChar(copyS2, 'r', 't');

    printf("Sobre la string \"%s\" remplazo 'a' por 'o': %s\n", s1, copyS1);
    printf("Sobre la string \"%s\" remplazo 'R' por 'T': %s\n", s2, copyS2);

    printf("Concateno \"%s\" con \"%s\":", copyS1, copyS2);

    char *concat = concatenate(copyS1, copyS2);

    printf(" \"%s\"\n", concat);

    free(concat);

    return 0;
}
