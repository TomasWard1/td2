#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node* subList(struct node* n, int i, int j) {
    // ?????????????????
}

struct node* addList(struct node* n, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = n;
    return newNode;
}

void printList(struct node* n) {
    while(n != 0) {
        printf("%i ",n->data);
        n = n->next;
    }
    printf("\n");
}

void printDelete(struct node* n) {
    while(n != 0) {
        struct node* t = n;
        n = n->next;
        free(t);
    }
}

int main() {

    struct node *n = NULL;
    for(int i=9;i>=0;i--) {
        n = addList(n,i);
    }

    n = subList(n, 3, 6);

    printList(n);

    printDelete(n);

    return 0;
}
