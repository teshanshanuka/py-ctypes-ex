/**
 * @file sample.c
 * @author Teshan Liyanage (teshanuka@gmail.com)
 * @brief Some simple c functins
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

void print_something(){
    printf("Something!\n");
}

int mult(int val1, int val2){
    return val1*val2;
}

float arr_sum(float* arr, int size){
    float sum = 0;
    for(size_t i=0; i<size; i++)
        sum += arr[i];
    return sum;
}
