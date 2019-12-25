
//
// Created by cuixin on 2019/12/25.
//
#include <stdio.h>
struct date{
    //1`31, 2^5 = 32 >31
    unsigned int d:5;
    //1-12, 2^4 = 16 >12
    unsigned int m:4;
    unsigned  int y;
};

int main(){
    printf("size of date is %lu byte\n", sizeof(struct date));
    struct date dt = {31, 12, 2019};
    printf("date is %d/%d/%d", dt.d, dt.m, dt.y);
}

