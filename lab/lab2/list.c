//
// Created by lucia on 29/10/2021.
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

void append_head(struct  linked_list *list, int val){
    // create an element ready to be add first
    struct element *elem = malloc(sizeof (struct element));
    // let the slot that can accept element be free
    // need to be pointer or it can't be changed in func

    elem->next = list->head;    // let element point to head
    elem->data = val;

    list->head = elem;
}

void remove_head(struct linked_list *list){
    // remove from head
    struct element *elem = malloc(sizeof (struct element));
    elem = list->head;
    if(!elem){
        // if element is null
        printf("List is null");
    }
    else{
        list->head = elem->next;
    }
}

void print_all(struct linked_list *list) {  // print all val in list
    struct element *elem = malloc(sizeof (struct element));
    elem = list->head;
    while(elem) {
        printf("%d ", elem->data);
        elem = elem->next;  // next is a pointer
    }
}
int main(){
    struct linked_list *list = malloc(sizeof (struct linked_list));
    for (int i = 0; i < 5; ++i) {
        append_int(list, i);
    }

    printf("Original list is:\n");
    printf("\n");

    print_all(list);
    printf("\n");

    append_head(list, -1);

    printf("Modified list is:\n");
    print_all(list);
    printf("\n");

    remove_head(list);
    printf("Modified 2 list is:\n");
    print_all(list);
    printf("\n");

    struct linked_list *l2 = malloc(sizeof (struct linked_list));
    l2->head = NULL;
    // test if list is null work
    remove_head(l2);
}
