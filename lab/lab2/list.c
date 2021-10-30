//
// Created by cyanbird on 29/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
struct element {
    struct element * next;
    int data;
};
struct linked_list {
    struct element * head;
};

void append_int(struct linked_list * list, int val) {
    struct element * elem = malloc(sizeof(struct element));
    elem->data = val;
    elem->next = NULL; // Really important to explicitly set this to null. Malloc does not zero memory
    if (list->head == NULL) {
        // Empty list, we need to append to head
        list->head = elem;
    } else {
        // List has some elements, find the end and append to that
        struct element * tail = list->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = elem;
    }
}