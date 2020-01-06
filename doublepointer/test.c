//
// Created by cuixin on 2020/1/6.
// https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/

#include <stdio.h>
int main(){
    int val = 10;
    int *ptr1 = &val;
    *ptr1 = 20;
    int **ptrToPtr = &ptr1;
    **ptrToPtr = 30;
    getchar();
}