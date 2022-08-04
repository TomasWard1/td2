#include <stdio.h>
#include <stdlib.h>

void ordenarArreglo(int *p, int size)
{
    int cambios = 1;
    while (cambios == 1)
    {
        cambios = 0;
        for (int i = 0; i < size-1; i++)
        {
            if (p[i] >  p[i+1])
            {
                int temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
                cambios = 1;
            }
        }
    }
}

int *merge(int *A, int sizeA, int *B, int sizeB)
{
    // ya sabes que los arreglos individuales estan ordenados de menor a mayor
    int *p = (int *)malloc(sizeof(int) * sizeA + sizeof(int) * sizeB);

    int iGlobal = 0;
    for (int i = 0; i < sizeA; i++)
    {
        p[i] = A[i];
        iGlobal++;
    }

    for (int i = 0; i < sizeB; i++, iGlobal)
    {
        p[iGlobal] = B[i];
        iGlobal++;
    }

    ordenarArreglo(p, sizeA + sizeB);

    return p;
}

int main()
{

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    int a[5] = {16, 17, 18, 19, 20};
    int b[4] = {18, 19, 20, 107};

    int *result = merge(a, 5, b, 4);

    printf("Result:");
    for (int i = 0; i < 9; i++)
    {
        printf(" %i", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
