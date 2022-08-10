#include <stdio.h>
#include <stdlib.h>

char *longest(char *v[], int size)
{
    int iMax = 0;
    int max = 0;

    for (int i = 0; i < size; i++)
    {
        int a = 0;
        while (v[i][a] != '\0')
        {
            a++;
        }

        if (a > max)
        {
            max = a;
            iMax = i;
        }
    }

    return v[iMax];
}

int len(char *s)
{
    int contador = 0;
    for (contador; s[contador] != '\0'; contador++)
        ;
    return contador;
}

int totalStrLen(char *v[], int size)
{
    int longitudTotal = 0;

    for (int i = 0; i < size; i++)
    {
        longitudTotal += len(v[i]);
    }

    return longitudTotal;
}

char *superConcatenate(char *v[], int size)
{
    int longitudTotal = totalStrLen(v, size);

    char *sc = (char *)malloc(sizeof(char) * longitudTotal + 1);

    int aGlobal = 0;
    for (int i = 0; i < size; i++)
    {

        for (int a = 0; v[i][a] != '\0'; a++, aGlobal++)
        {
            sc[aGlobal] = v[i][a];
        }
    }

    sc[aGlobal] = '\0';

    return sc;
}

char *superConcatenateWithSep(char *v[], int size, char *s)
{

    int lenSep = len(s);
    int lenStrSep = totalStrLen(v, size) + lenSep * (size - 1);

    char *withSep = (char *)malloc(sizeof(char) * lenStrSep + 1);

    int aGlobal = 0;
    for (int i = 0; i < size; i++)
    {

        if (aGlobal != 0)
        {
            for (int b = 0; b < lenSep; b++)
            {
                withSep[aGlobal] = s[b];
                aGlobal++;
            }
        }

        for (int a = 0; v[i][a] != '\0'; a++, aGlobal++)
        {
            withSep[aGlobal] = v[i][a];
        }
    }

       withSep[aGlobal] = '\0';

    return withSep;
}

int main()
{

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char *v[5] = {"hola", "como", "va", "el", "dia"};

    char *l = longest(v, 5);

    printf("La string mas larga es: \"%s\"\n", l);

    char *sc = superConcatenate(v, 5);

    printf("El arreglo de string super concatenado es: \"%s\"\n", sc);

    char *scs = superConcatenateWithSep(v, 5, ".");

    printf("El arreglo de string super concatenado con separadores es: \"%s\"\n", scs);

    free(sc);
    free(scs);

    return 0;
}