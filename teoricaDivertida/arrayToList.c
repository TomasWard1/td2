#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *arrayToList(int *a, int size)
{
    struct node *first = 0;
    struct node *prev = 0;

    for (int i = 0; i < size; i++)
    {

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = a[i];
        newNode->next = NULL;

        if (!first)
        {
            first = newNode;
        }

        if (prev)
        {
            prev->next = newNode;
        }
        prev = newNode;
    }

    return first;
}

int main()
{

    struct node *n = NULL;

    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    n = arrayToList(a, 9);

    return 0;
}
