//
// Created by cuixin on 2019/12/20.
//
#include "stdio.h"
int initializer(void){
    return 50;
}
int main(){
    //compiler error, must use constant literals
    static int i = initializer();
    printf(" value of i = %d", i);
    getchar();
    return 0;
}
