//
// Created by cyanbird on 18/10/2021.
//
#include "stdio.h"
#include "math.h"

int isPrime(int n){ // determine weather input int is prime
    int root = (int)sqrt((double)n); // force change n into double find its root, and back to int ignore decimals
    for(int i = 2;i <= root;i++){
        if(!(n%i))
            // n % i is 0
            return 0;
    }
    // if can't be divided, is prime
    return 1;
}

int main(){
    int num;
    printf("Input a integer:");
    scanf("%d", &num); // it will report err cuz directly convert char, careful
    if (isPrime(num)){
        printf("Integer %d is prime number.", num);
    } else{
        printf("Integer %d is not prime number.", num);
    }
}

