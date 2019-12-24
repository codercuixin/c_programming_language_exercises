//
// Created by cuixin on 2019/12/24.
//https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/
//https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/
// volatile总会从内存的某个位置读取最新值, 禁止编译器优化对该变量的访问。
//The system always reads the current value of a volatile object from the memory location
// rather than keeping its value in temporary register at the point it is requested,
// even if a previous instruction asked for a value from the same object.
//不带优化：gcc demo1.c -o demo -save-temps
//待优化：gcc -O3 demo1.c -o demo -save-temps
#include <stdio.h>
int main(void){
//    const int local = 10;
    const volatile int local = 10;
    int *ptr = (int *) &local;
    printf("Initial value of local:%d\n", local);
    *ptr = 100;
    printf("Modified value of local:%d\n", local);
    return 0;
}