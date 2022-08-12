#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    char *a;
    char *b;
};

int len(char *s)
{
    int contador = 0;
    for (contador; s[contador] != '\0'; contador++)
        ;
    return contador;
}

int strEquals(char *s1, char *s2)
{
    int len1 = len(s1);
    int len2 = len(s2);

    int lenGrande;
    if (len1 > len2)
    {
        lenGrande = len1;
    }
    else
    {
        lenGrande = len2;
    }

    for (int i = 0; i < lenGrande; i++)
    {
        if (s1[i] != s2[i])
        {
            printf("Se encontro desigual\n");
            return 0;
        }
    }
    printf("Son iguales\n");

    return 1;
}

int listStrEquals(struct node *primero)
{
    struct node *current = primero;

    while (current->next != NULL)
    {
        if (!strEquals(current->a, current->b))
        {
            printf("Se encontro un nodo en la list desigual\n");
            return 0;
        }

        current = current->next;
    }

    printf("todos los nodos de la lista tienen str iguales\n");
    return 1;
}

int main()
{
    char *s1 = "Tomas";
    char *s2 = "Ward";
    struct node *first = (struct node *)malloc(sizeof(struct node));

    int res = strEquals(s1, s2);

    return 0;
}
