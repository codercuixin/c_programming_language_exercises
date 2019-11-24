//
// Created by cuixin on 2019-11-24.
//
#include "stdio.h"
unsigned rightrot(unsigned x, int p, int n);
int main(){
    unsigned x1 = 0x32e5;
    int p = 7;
    int n = 8;
    printf("%x\n", rightrot(x1, p, n));

}

unsigned rightrot(unsigned x, int p, int n){
    //x: Xmax...Xp+1 XpXp-1...Xp-n+1 Xp-n...X0
    unsigned  xRight = (~ (~0 << (p-n+1))) &x;
    printf("xRight: %x\n", xRight);
    unsigned  xLeft = (~0 << (p+1)) & x;
    printf("xLeft: %x\n", xLeft);
    unsigned  xMiddleInverse = (~((x >> (p-n + 1)) & ( ~(~0 << n)))) & (~(~0 << n));
    printf("xMiddleInverse: %x\n", xMiddleInverse);
    unsigned  xMiddle = xMiddleInverse << (p-n+1);
    return xRight + xMiddle + xLeft;
}