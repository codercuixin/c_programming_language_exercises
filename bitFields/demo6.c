//
// Created by cuixin on 2019/12/25.
//

#include <stdio.h>
struct test {
    unsigned int x : 2;
    unsigned int y : 2;
    unsigned int z : 2;
};
int main()
{
    struct test t;
    //warning: unsigned conversion from 'int' to 'unsigned char:2' changes value from '5' to '1' [-Woverflow]
    t.x = 5;
    printf("%d", t.x);
    return 0;
}