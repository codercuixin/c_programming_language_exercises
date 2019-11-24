//
// Created by cuixin on 2019-11-24.
//
#include "stdio.h"
unsigned rightrot(unsigned x, int n);
unsigned getMaxOneWeight(unsigned x);
int main(){
    unsigned x1 = 0x22e5;
    int n = 8;
    printf("%x\n", rightrot(x1, n));

}

unsigned rightrot(unsigned x,  int n){
    //x: Xmax...Xn Xn-1Xn-2...X0
    unsigned  xRightN = (~ (~0 << n)) & x;
    printf("xRightN %x\n", xRightN);
    unsigned  xRightNMutiply = xRightN <<  (getMaxOneWeight(x) - n);
    printf("xRightNMutiply(x): %x\n", xRightNMutiply);
    unsigned  xDevide = x >> n;
    printf("xDevide: %x\n", xDevide);
    return xRightNMutiply + xDevide;
}

unsigned getMaxOneWeight(unsigned x){
    unsigned  weight = 0;
    while ( (1<< weight) <= x){
        weight++;
    }
    return weight;
}