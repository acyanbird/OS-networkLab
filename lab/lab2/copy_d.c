//
// Created by lucia on 28/10/2021.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h" //  for read(), write() and close() functions
#include<fcntl.h>  // for the open() function

#define SIZE 100

int main() {

    char readlines[SIZE];
    char name1[20], name2[20];

    printf("Input file name 1 with extension:");
    scanf("%s", name1);

    int fd1 = open(name1, O_RDONLY);
    int x;

    if(fd1 < 0) { // if open failed
        fprintf(stderr, "error opening file");
        exit(1);
    }

    printf("Input file name 2 with extension:");
    scanf("%s", name2);

    int fd2 = open(name2, O_WRONLY);

    if(fd2 < 0){    // if file not exist
        fd2 = open(name2, O_CREAT, 0777);
    }

    while ((x = read(fd1, readlines, SIZE - 1) ) > 0){ // x is the len of line
        readlines[x] = '\0';    // add end to line
        printf("%s", readlines);
        write(fd2, readlines, strlen(readlines));   // write to where from where, len of writing len
    }

    close(fd1);
    close(fd2);
}