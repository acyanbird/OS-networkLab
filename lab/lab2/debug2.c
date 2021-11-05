#include <stdlib.h>
#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[]) {
    int *array_of_ints = (int *) malloc(sizeof(int) * 10);
    int i;
    for (i = 0; i < 10; i++) {
        array_of_ints[i] = i;
    }

    for (int j = 0; j < 10; j++) {
        printf("%d ", array_of_ints[j]);
    }

    printf("\n");
}