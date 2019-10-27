#include <stdlib.h>
#include <stdio.h>

struct node {int i; struct node *next;};

void print_list (struct node *list) {

    printf("[ ");

    while (list != NULL) {
        printf("%d ",list->i);
        list = list->next;
    }

    printf("]\n");
}

struct node * insert_front (struct node *list, int data) {

    struct node *new = malloc(1 * sizeof(struct node));
    
    new->i = data;
    new->next = list;

    return new;
}

struct node * free_list (struct node *list) {

    struct node *next;

    while (list != NULL) {

        next = list->next;
        printf("freeing node: %d\n",list->i);
        free(list);
        list = next;
    }

    return list;
}

struct node * remove_node (struct node *list, int data) {

	return list;

}

struct int find_node (struct node *list, int data) {

	int index = 0;

	while (list != NULL) {

		if (list->i == data) {

			return index;
		}

		index++;
		list = list->next;
	}

	return -1;
}

int main() {

    struct node *list = NULL;

    printf("Printing empty list:\n");
    print_list(list);

    printf("Adding #s 0-9 to list.\n");
    int i;
    for(i = 0; i < 10; i++) {
        list = insert_front(list,i);
    }

    printf("Printing list:\n");
    print_list(list);

    printf("Printing index of element 5:%d\n",find_node(list,5));
    printf("Printing index of element 10:%d\n",find_node(list,10));

    printf("Freeing list.\n");
    list = free_list(list);
    printf("Printing list:\n");
    print_list(list);

    return 0;
}