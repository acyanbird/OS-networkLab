//
// Created by cyanbird on 18/10/2021.
//

#include <stdio.h>

// write the code for the sort() function that sorts an integer array in ascending order
int sort(int x[], int size){
    // array is like pointer, input the first val ptr, so it will be changed
    // insert sort
    int tmp, j;
    for(int i = 1;i < size;i++){
        tmp = x[i];
        for (j = i-1; j >= 0; j--) {
            if(tmp < x[j]){
                // move backward
                x[j+1] = x[j];
            } else{
                // end the loop since tmp in right place
                break;
            }

        }
        x[j+1] = tmp;
    }
    return 0;
}


int main() {
    int x[]={4,1,4,3,10,5};
    int i;

    sort(x,6); // sort() function sorts the array x in ascending order

    printf("The sorted array is as follows:\n");

    for(i=0; i<6; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
    return 0;
}