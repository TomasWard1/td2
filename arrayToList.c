#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};

struct node* arrayToList(int* a, int size) {
    // ???????????????????????
}

int main() {

    struct node *n = NULL;

    int a[9] = {1,2,3,4,5,6,7,8,9};

    n = arrayToList(a, 9);

    return 0;
}
