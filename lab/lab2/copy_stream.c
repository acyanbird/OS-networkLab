//
// Created by lucia on 26/10/2021.
//

#include "stdio.h"
#include "stdlib.h"

#define SIZE 100    // len of str is 100

int main(){
    char name1[20], name2[20];
    printf("Input file name 1:");
    scanf("%s", name1);
    FILE *fptr1 = fopen(name1,"r");

    if(fptr1 == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
}
