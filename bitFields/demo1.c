//
// Created by cuixin on 2019/12/25.
//

//https://www.geeksforgeeks.org/bit-fields-c/
#include <stdio.h>
struct date{
    unsigned int d;
    unsigned int m;
    unsigned int y;
};
int main(){
    printf("Size of date is %lu bytes\n", sizeof(struct date));
    struct date dt = {31, 12, 2019};
    printf("date is %d/%d/%d", dt.d, dt.m, dt.y);
}