//
// Created by lucia on 19/10/2021.
//
#include "stdio.h"
#include "math.h"

int isPrime(int num){
    // determine if input num is prime
    int root = (int) sqrt((double )num);
    for (int i = 2; i <= root ; i++) {
        // pass all num smaller than root
        if(!(num%i)){
            // if it can be divided, not prime
            return 0;
        }
    }
    return 1;
}

int primeSum(int start, int end){
    int sum = 0;    // init the sum
    for (int i = start; i <= end ; i++) {
        if(isPrime(i)){
            // if current num is prime, add to sum
            sum += i;
        }
    }
    return sum;
}
