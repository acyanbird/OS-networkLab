//
// Created by lucia on 29/10/2021.
//

#include "stdio.h"
#include "stdlib.h"

// init element structure
struct element{
    struct element *next;
    int data;
};

// init queue
struct queue {
    struct element *head;
    struct element *tail;
};

void add_q(struct queue *q, int data) {
    // add from tail

    struct element *elem = malloc(sizeof (struct element));
    elem->next = NULL;
    elem->data = data;

    if(!q->tail) {
        // if tail is null, queue is emtpy
        q->tail = q->head = elem;
    }
    else {
        q->tail->next = elem;
        q->tail = elem;
        printf("add %d, tail is %d\n", data, q->tail->data);
    }
}

void remove_q(struct queue *q) {
    // remove from head
    if(!q->tail) {
        // if tail is null
        printf("This queue is empty.\n");
    } else if(q->head == q->tail) {
        // only one element in queue
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
    }
}

void printall(struct queue *q) {
    if(!q->tail) {
        // if tail is null
        printf("This queue is empty.\n");
    }
    else if(q->tail == q->head) {
        printf("only 1 in q %d", q->tail->data);
    }
    else {
        struct element *elem = malloc(sizeof (struct element));
        elem = q->head;
        int num = 1;
        while(elem->next != NULL) {
            // while not the last
            printf("%d ", elem->data);
            elem = elem->next;
        }
        printf("%d\n", elem->data);
        // print the last
    }
}

int main() {
    struct queue *q1 = malloc(sizeof (struct queue));

    // init the queue
    q1->head = q1->tail = NULL;


    remove_q(q1);

    for (int i = 0; i < 5; ++i) {
        add_q(q1, i);
    }

    printall(q1);

    remove_q(q1);

    printall(q1);
}