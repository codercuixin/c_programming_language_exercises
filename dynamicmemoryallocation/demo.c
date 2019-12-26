//
// Created by cuixin on 2019/12/26.
//https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int* ptr;
    int n,i, sum = 0;

    n = 5;
    printf("Enter number of elements: %d\n", n);

    ptr = (int*)malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Memory not allocated.\n");
        exit(0);
    }else{
        printf("memory successfully allocated using malloc.\n");

        for(int i=0; i<n; ++i){
            ptr[i] = i+1;
        }

        //Print the elements of the array
        printf("The elements of the array are: ");
        for(i=0; i<n; ++i){
            printf("%d, ", ptr[i]);
        }
    }
    return 0;
}