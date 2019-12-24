//
// Created by cuixin on 2019/12/24.
//https://www.geeksforgeeks.org/void-pointer-c-cpp/
#include <stdio.h>
int main(){
    int a = 10;
    char b = 'x';
    void *p = &a;
    //需要先转换指针类型
    printf("%d\n", *(int *)p);
    p = &b;
    printf("%d\n", *(char *)p);
}