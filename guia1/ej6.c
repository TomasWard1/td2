#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addLast(struct node *n, int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (n == NULL)
    {
        n = newNode;
        return n;
    }

    struct node *aux = n;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    // esto modifica el nodo en aux y en n al mismo tiempo
    aux->next = newNode;
    return n;
}

struct node *removeFirst(struct node *n)
{
    struct node *primero = n;
    struct node *segundo = n->next;

    n = segundo;

    free(primero);

    return n;
}

struct node *join(struct node *n1, struct node *n2)
{
    struct node *nueva = (struct node *)malloc(sizeof(struct node));
    *nueva = *n1;

    struct node *aux = nueva;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    // modifica tambien al puntero nuevas (referencian el mismo nodo)
    aux->next = (struct node *)malloc(sizeof(struct node));
    *aux->next = *n2;

    free(n1);
    free(n2);

    return nueva;
}

struct node *removeData(struct node *n, int data)
{
    struct node *iter = n;
    struct node *prev = NULL;
    int lastNode = 0;

    while (lastNode == 0)
    {

        struct node *found = NULL;

        if (iter->data == data)
        {
            found = iter;
            if (prev == NULL)
            {
                n = n->next;
            }
            else
            {
                prev->next = iter->next;
            }
        }
        else
        {
            prev = iter;
        }

        //permite iterar sobre el ultimo
        if (iter->next == NULL)
        {
            lastNode = 1;
        }

        iter = iter->next;

        //borra el nodo encontrado
        if (found != NULL)
        {
            free(found);
        }
    }

    return n;
}

void printList(struct node *n)
{
    printf("[");
    if (n == 0)
    {
        printf("]\n");
    }
    else
    {
        while (n->next != 0)
        {
            printf("%i, ", n->data);
            n = n->next;
        }
        printf("%i]\n", n->data);
    }
}

int main()
{

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct node *n1 = NULL;
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n1\n");

    n1 = addLast(n1, 2021);

    n1 = addLast(n1, 42);

    n1 = addLast(n1, 0x400);
    printList(n1);
    printf("\n");

    printf("Agrego datos a la lista: n2\n");
    struct node *n2 = NULL;
    n2 = addLast(n2, 0);
    n2 = addLast(n2, 42);
    n2 = addLast(n2, 3);
    n2 = addLast(n2, 42);
    printList(n2);
    printf("\n");

    printf("Join lista n1 y n2: n3\n");
    struct node *n3 = join(n1, n2);
    printList(n3);
    printf("\n");

    printf("RemoveFirst: n3\n");
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");

    printf("RemoveData: 42\n");
    n3 = removeData(n3, 42);
    printList(n3);
    printf("\n");

    printf("RemoveFirst dos veces: n3\n");
    n3 = removeFirst(n3);
    n3 = removeFirst(n3);
    printList(n3);
    printf("\n");

    free(n3);

    return 0;
}
