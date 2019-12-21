//
// Created by cuixin on 2019-12-21.
gcc ex4_14.c hdr.c
//
#include "stdio.h"
#define swap(t, x, y) { t temp =x ; x = y; y = temp; }
#ifndef HDR
#include <math.h>
#include <string.h>
#include "hdr.h"
#endif
int main(){
    int x = 1;
    int y = 2;
    swap(int, x, y);
    printf("%d,%d", x, y);
    hdr("hello world");
}