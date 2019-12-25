//
// Created by cuixin on 2019/12/25.
//

#include <stdio.h>
struct test {
    unsigned int x;
    //error: width of 'y' exceeds its type
    unsigned int y : 33;
    unsigned int z;
};
int main()
{
    printf("%lu", sizeof(struct test));
    return 0;
}