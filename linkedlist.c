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

struct node *remove_node (struct node *list, int data) {

    if (list->i == data) {
        
        struct node *next = list->next;

        free(list);

        return next;
    }

    else {

        struct node *curr = list->next;
        struct node *prev = list;

        while (curr != NULL) {

            if (curr->i == data) {
                
                prev->next = curr->next;
                
                free(curr);

                return list;
            }

            curr = curr->next;
            prev = prev->next;
        }
    
        return list;
    }

}

/*
struct node * remove_node (struct node *list, int data) {

	int index = find_node(list,data);

	if (index == -1) {

		return list;
	}

	else if (index == 0) {

		struct node *next = list->next;
	
		free(list);

		return next;
	}

	else {

		int n = 0;

		while (n < index) {

			list = list->next;	
			n++;
		}
	}
}

int find_node (struct node *list, int data) {

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
*/

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

    printf("Removing 9:\n");
    list = remove_node(list,9);
    print_list(list);

    printf("Removing 4:\n");
    list = remove_node(list,4);
    print_list(list);

    printf("Removing 0:\n");
    list = remove_node(list,0);
    print_list(list);

    printf("Removing -1:\n");
    list = remove_node(list,-1);
    print_list(list);

    printf("Freeing list.\n");
    list = free_list(list);
    printf("Printing list:\n");
    print_list(list);

    return 0;
}