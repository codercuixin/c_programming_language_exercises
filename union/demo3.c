//
// Created by cuixin on 2019/12/25.
//
#include <stdio.h>
union test{
    int x;
    char y;
};
int main(){
    union test p1;
    p1.x = 65;

    union test* p2 = &p1;
    printf("%d %c", p2->x, p2->y);
    return 0;
}