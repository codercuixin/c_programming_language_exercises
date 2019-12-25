//
// Created by cuixin on 2019/12/25.
//A special unnamed bit field of size 0 is used to force alignment on next boundary.
// For example consider the following program.

struct test1{
    unsigned int x:5;
    unsigned int y:8;
};

struct test2{
    unsigned int x:5;
    unsigned int :0;
    unsigned int y:8;
};
int main()
{
    printf("Size of test1 is %lu bytes\n",
           sizeof(struct test1));
    printf("Size of test2 is %lu bytes\n",
           sizeof(struct test2));
    return 0;
}