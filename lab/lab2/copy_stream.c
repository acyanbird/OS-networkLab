//
// Created by lucia on 26/10/2021.
//

#include "stdio.h"
#include "stdlib.h" // for exit()

#define SIZE 100    // len of str is 100

int main(){
    char name1[20], name2[20];

    char readlines[SIZE];

    printf("Input file name 1 with extension:");
    scanf("%s", name1);
    FILE *fptr1 = fopen(name1,"r");

    if(fptr1 == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    printf("Input file name 2 with extension:");
    scanf("%s", name2);
    FILE *fptr2 = fopen(name2, "w");

    while (fgets(readlines, SIZE, fptr1)) {   // read the file and put lines to f2
        fputs(readlines, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);

}
