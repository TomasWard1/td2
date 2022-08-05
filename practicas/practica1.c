#include <stdio.h>
#include <stdlib.h>

int multiplosEncontrados(int *lista)
{
    int contador = 0;
    for (int i = 0; lista[i] != '\0'; i++)
    {
        if (lista[i] % 3 == 0)
        {
            contador++;
        }
    }

    return contador;
}

void meterEnteros(int *lista, int *listaMultiplos)
{

    int iGlobal = 0;
    for (int i = 0; lista[i] != '\0'; i++)
    {
        if (lista[i] % 3 == 0)
        {
            listaMultiplos[iGlobal] = lista[i];
            iGlobal++;
        }
    }
}

int main()
{
    int lista[] = {1, 9, 5, 3, 7, 6, 8};

    int m = multiplosEncontrados(lista);

    printf("%i multiplos encontrados\n", m);
    int *listaMultiplos = malloc(sizeof(int) * m);

    meterEnteros(lista, listaMultiplos);

    printf("Tu lista nueva:");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", listaMultiplos[i]);
    }
    printf("\n");
    return 0;
}
