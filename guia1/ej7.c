#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct list
{
    struct node *first;
    int size;
};

struct node
{
    struct node *next;
    struct elem *data;
};

struct elem
{
    float x;
    float y;
    int i;
    char t;
};

struct list *listNew()
{
    struct list *l = (struct list *)malloc(sizeof(struct list));
    l->first = 0;
    l->size = 0;
    return l;
}

void listAdd(struct list *l, float x, float y, int i, char t)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    struct elem *e = (struct elem *)malloc(sizeof(struct elem));
    e->x = x;
    e->y = y;
    e->i = i;
    e->t = t;
    n->data = e;
    n->next = l->first;
    l->first = n;
    l->size = l->size + 1;
}

void listDelete(struct list *l)
{
    struct node *n = l->first;
    while (n != 0)
    {
        struct node *r = n;
        n = n->next;
        free(r->data);
        free(r);
    }
    free(l);
}

void listPrint(struct list *l)
{
    struct node *n = l->first;
    printf("[");
    while (n != 0)
    {
        struct elem *e = n->data;
        printf("(%f,%f,%i,%i)", e->x, e->y, e->i, e->t);
        n = n->next;
        if (n != 0)
        {
            printf(",");
        }
    }
    printf("]");
}

float magnitudeAverage(struct list *ls)
{

    if (ls->size == 0) {
        return 0;
    }

    float total = 0;
    struct node *aux = ls->first;

    for (int i = 0; i < ls->size; i++)
    {
        float modulo = sqrt(pow(aux->data->x, 2) + pow(aux->data->x, 2));
        total += modulo;
        aux = aux->next;
    }

    return total / ls->size;
}

int sorted(struct list *ls)
{
    int ascendente = 1; // interpretar como bool
    struct node *current = ls->first;
    
    while (current->next != NULL)
    {
        int currentI = current->data->i;
        int nextI = current->next->data->i;

        if (currentI > nextI)
        {
            ascendente = 0;
        }

        current = current->next;
    }

    return ascendente;
}

void numerate(struct list *ls)
{
    struct node *aux = ls->first;

    for (int i = 0; i < ls->size; i++)
    {
        aux->data->t = i;
        aux = aux->next;
    }
}

void swap(struct list *ls, int i, int j)
{

    if (i > j) {
        int aux = i;
        i = j;
        j = aux;
    }
    struct node *prev1 = ls->first;
    struct node *prev2 = ls->first;
    struct node *nodo1 = ls->first;
    struct node *nodo2 = ls->first;

    while (nodo1->data->t != i)
    {
        printf("%i\n", nodo1->data->t);
        prev1 = nodo1;
        nodo1 = nodo1->next;
    }

    while (nodo2->data->t != j)
    {
        prev2 = nodo2;
        nodo2 = nodo2->next;
    }

    printf("%i\n", prev1->data->t);
    printf("%i\n", nodo1->data->t);
    printf("%i\n", prev2->data->t);
    printf("%i\n", nodo2->data->t);



    if (nodo1->data->t == 0) {
        ls->first = nodo2;
    }

    struct node *aux = nodo2->next;

    prev1->next = nodo2;
    prev2->next = nodo1;
    nodo2->next = nodo1->next;
    nodo1->next = aux;
}

int main()
{

    // -- Descomentar para probar --
    // Lo siguiente es un ejemplo y DEBE ser modificado.

    struct list *l = listNew();
    listAdd(l, 30.0, 30.0, 30, 30);
    listAdd(l, 20.0, 20.0, 20, 20);
    listAdd(l, 10.0, 10.0, 10, 10);

    listPrint(l);
    printf("\n");
    float f = magnitudeAverage(l);
    printf("El modulo de los elementos x e y de la lista es: %f\n\n", f);

    listPrint(l);

    printf("\n");
    int i = sorted(l);
    printf("Los elementos de la lista estan ordenados: %i\n\n", i);

    listPrint(l);
    printf("\n");
    numerate(l);
    printf("Los elementos de la lista luego de numerarlos:\n");
    listPrint(l);
    printf("\n\n");

    listPrint(l);
    printf("\n");
    swap(l, 1, 0);
    printf("Los elementos con indices 0 y 1 estan intercambiados:\n");
    listPrint(l);
    printf("\n\n");

    listDelete(l);

    return 0;
}
