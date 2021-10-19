//
// Created by lucia on 19/10/2021.
//

#include "stdio.h"

int main(){
    int start, end, sum;
    printf("Input the start number:");
    scanf("%d", &start);
    printf("Input the end number:");
    scanf("%d", &end);

    sum = primeSum(start, end);

    printf("Sum is %d\n", sum);

}