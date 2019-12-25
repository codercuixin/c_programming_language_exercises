//
// Created by cuixin on 2019/12/25.
//Array of bit fields is not allowed.
// For example, the below program fails in the compilation.
struct test {
    unsigned int x[10] : 5;
};

int main()
{
}
