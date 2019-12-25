//
// Created by cuixin on 2019/12/25.
//

#include <stdio.h>
struct date{
    //1`31, 2^5 = 32 >31
     int d:5;
    //1-12, 2^4 = 16 >12
     int m:4;
     int y;
};

int main(){
    printf("size of date is %lu byte\n", sizeof(struct date));
    //31-> 11111 有符号数则是-1
    //12-> 1100 有符号数则是-4
    struct date dt = {31, 12, 2019};
    printf("date is %d/%d/%d", dt.d, dt.m, dt.y);
}