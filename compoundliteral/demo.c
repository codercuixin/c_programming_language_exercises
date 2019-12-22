//
// Created by cuixin on 2019-12-22.
//
//https://www.geeksforgeeks.org/compound-literals-c/
#include <stdio.h>
struct Point{
    int x, y;
};
int main(){
    int *p = (int []){ 1, 2, 3};
    printf("%d, %d, %d\n", p[0], p[1], p[2]);

    struct Point point = (struct  Point){4, 5};
    printf("%d, %d\n",point.x, point.y );
}