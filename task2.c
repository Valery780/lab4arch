#include <stdio.h>
#include <stdlib.h>
struct item {
    int number;
    struct item *next;
};

void add_item(struct item **i, int number) {

    struct item *tmp = *i;

    struct item *new = malloc(sizeof(struct item));
    new->number = number;
    new->next = NULL;

    if (!tmp) {
        *i = new;
        return;
    }

    while (tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = new;
}

void print_list(struct item *list) {

    if (!list) {
        printf("linked list is empty!\n");
        return;
    }

    while (list) {
        printf("number: %d\n", list->number);
        list = list->next;
    }
}
struct item *delete_el(struct item *start, int a) {
    struct item *start_true = start;
    if (start -> number == a) {
        struct item *new_start = start -> next;
        free(start);
        return(new_start);
    }
    else {
        struct item *pointer = start -> next;
        while (pointer != NULL) {
            while (pointer -> number == a) {
                if (start -> next == pointer) {
                    if (pointer == NULL) {
                        start -> next = NULL;
                        free(pointer);
                        return(start_true);
                    }
                    else {
                        start -> next = pointer -> next;
                        free(pointer);
                        return(start_true);
                    }
                }
                start = start -> next;
            }
            pointer = pointer -> next;
        }
    }
}
int main(void) {
    struct item *list = NULL;

    add_item(&list, 10);
    add_item(&list, 20);
    add_item(&list, 30);
    print_list(list);
    list = delete_el(list,20);
    printf("New list:\n");
    print_list(list);
}