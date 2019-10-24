#include <stdlib.h>
#include <stdio.h>

struct node {int i; struct node *next;};

void print_list (struct node *list) {

    printf("[ ");

    while (list->next != NULL) {
        printf("%d ",list->i);
        list = list->next;
    }

    printf("]\n");
}

struct node * insert_front (struct node *list, int n) {

    struct node *new = malloc(1 * sizeof(struct node));
    
    new->i = n;
    new->next = list;

    return new;
}

struct node * free_list (struct node *list) {

    struct node *next;

    while (list != NULL) {

        next = list->next;
        free(list);
        list = next;
    }

    return list;
}

int main() {

    struct node *list;

    printf("Printing empty list:\n");
    print_list(list);

    printf("Adding #s 0-9 to list.\n");
    int i;
    for(i = 0; i < 10; i++) {
        list = insert_front(list,i);
    }

    printf("Printing list:\n");
    print_list(list);

    return 0;
}