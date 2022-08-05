#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dato;
    struct node *next;
};

struct node *chequearMultTres(int *lista)
{

    struct node *inicio = NULL;
    struct node *ult = NULL;

    int yaTieneInicio = 0;

    for (int i = 0; lista[i] != '\0'; i++)
    {

        if (lista[i] % 3 == 0)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->dato = lista[i];
            newNode->next = NULL;

            if (yaTieneInicio == 0)
            {
                inicio = newNode;
                yaTieneInicio = 1;
            }
            if (ult != NULL)
            {
                ult->next = newNode;
            }
            ult = newNode;
        }
    }

    return inicio;
}

int main()
{

    int lista[] = {12, 9, 5, 3, 7, 6, 8};

    struct node *res = chequearMultTres(lista);

    for (int i = 0; i < 8; i++)
    {
        printf("%i\n", res[i].dato);
    }

    return 0;
}
