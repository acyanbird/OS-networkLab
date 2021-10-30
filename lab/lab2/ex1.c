//
// Created by lucia on 26/10/2021.
//

// need to change, count the word at the end without space

#include<stdio.h>
#include<string.h>

int count_words(char *str) {
    // this function should return the number of words in str
    // count the space num in str
    int num = 0;
    int len = 0;    // init counter
    while (*str != '\0') {
        if (*str != ' ') {
            num++;
        }
        str++;
    }
    return num;
}
int main(){


    char str[100];

    printf("Enter a string:");
    fgets(str,100,stdin);    // this function reads a line or at most 99 bytes from stdin file stream that represents the keyboard
    printf("Number of words in the entered string is %d\n",count_words(str));

    return 0;
}