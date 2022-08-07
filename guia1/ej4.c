#include <stdio.h>
#include <stdlib.h>

void pairOfEquals(char v[], int size, char **a, char **b)
{
    // a y b son las direcciones de los punteros a y b, que apuntan a chars.
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        int analyze = v[i];

        for (int j = i+1; v[j ] != '\0'; j ++)
        {
            int current = v[j ];
            if (analyze == current)
            {
                *a = &v[i];
                *b = &v[j ];

                found += 1;
                break;
            }
        }

        if (found)
        {
            break;
        }
    }
}

int main()
{

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    char v[7] = {9, 4, 5, 6, 3, 2, 100};

    char *a;
    char *b;

    pairOfEquals(v, 7, &a, &b);

    if (a == 0 || b == 0)
    {
        printf("No hay iguales\n");
    }
    else
    {
        printf("Los valores iguales son: %i == %i\n", (char)(*a), (char)(*b));
    }

    return 0;
}
