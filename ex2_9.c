//
// Created by cuixin on 2019-11-24.
//
#include <stdio.h>
int bitcount(unsigned x);

int main(){
    int b = bitcount(0x2345);
    printf("%d", b);
}


int bitcount(unsigned x) {
    if(x == 0){
        return 0;
    }
    int b = 1;
    //有n个1，循环就执行n-1次，巧妙
    while ((x &= (x - 1)) != 0) {
        b++;
    }
    return b;
}