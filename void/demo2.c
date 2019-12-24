//
// Created by cuixin on 2019/12/24.
//
#include <stdio.h>
int main(){
    int a[2] = {1, 2};
    void *ptr = &a;
    ptr = ptr + sizeof(int);
    printf("%d", *(int *)ptr);
    return 0;
}