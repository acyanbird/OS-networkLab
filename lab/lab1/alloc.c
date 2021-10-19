//
// Created by cyanbird on 19/10/2021.
//
#include "stdio.h"
#include "stdlib.h"

int sort(int *arr, int size){
    int tmp, j;
    for (int i = 1; i < size; i++) {
        tmp = *(arr+i); // get the first unsort
        for (j = i-1; j >= 0 ; j--) {
            if(tmp < *(arr+j)){
                *(arr+j+1) = *(arr+j);
            } else{
                break;
            }
        }
        *(arr+j+1) = tmp;   // assign value to the slot
    }
    return 0;
}

int main(){
    int size, num;
    printf("input the size of array:");
    scanf("%d", &size);
    int *arr = (int *) malloc(sizeof(int) * size );
    // give the array places

    for (int i = 0; i < size; i++) {
        printf("input number %d:", i+1);
        scanf("%d", &num);
        *(arr+i) = num; // equal to arr[i] = num
    }
    sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ",*(arr+i)); // print current value
    }
    printf("\n");
}
