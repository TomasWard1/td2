#include <stdio.h>
#include <stdlib.h>

void ordenarArreglo(int *p, int size)
{
    //bubble sort
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
    int *p = (int *)malloc(sizeof(int) * sizeA + sizeof(int) * sizeB + sizeof(int));

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

    p[iGlobal] = '\0';

    ordenarArreglo(p, sizeA + sizeB);

    return p;
}

int main()
{


    int a[5] = {1, 2, 3, 4, 5};
    int b[4] = {4, 5, 6, 1000};

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
