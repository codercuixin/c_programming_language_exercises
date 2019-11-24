//
// Created by cuixin on 2019/11/19.
//
#include "stdio.h"
unsigned invert(unsigned x, int p, int n, unsigned y);
int main(){
    unsigned x1 = 0x32e5;
    int p = 7;
    int n = 4;
    unsigned y = 0x1a;
    printf("%x\n", invert(x1, p, n, y));

}

unsigned invert(unsigned x, int p, int n, unsigned y){
    //x: Xmax...Xp+1 XpXp-1...Xp-n+1 Xp-n...X0
    unsigned  xRight = (~ (~0 << (p-n+1))) &x;
    unsigned  xLeft = (~0 << (p+1)) & x;
    unsigned  yRightN= (~ (~0 << n)) & y;
    unsigned  xMiddle = yRightN << (p-n+1);
    return xRight + xMiddle + xLeft;
}
