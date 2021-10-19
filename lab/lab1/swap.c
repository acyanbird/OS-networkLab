//
// Created by cyanbird on 18/10/2021.
//
#include "stdio.h"


int swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int main(int argc, char *argv[]) {
    int val_a = 50;
    int val_b = 20;
    // call the swap() function correctly, swap() should swap the values stored in val_a and val_b so
    // that the swapped values of val_a and val_b are printed in the next two lines
    swap(&val_a, &val_b);   // pass their reference to the func
    printf("val_a is %d (should be 20)\n", val_a);
    printf("val_b is %d (should be 50)\n", val_b);
    return 0;
}