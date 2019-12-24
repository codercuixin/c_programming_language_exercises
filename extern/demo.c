//
// Created by cuixin on 2019/12/24.
//

//https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/
#include <stdio.h>
//可以声明多次，声明不会分配存储
void echo(char *);
void echo(char *);
int foo(int arg1, char arg2);
//上面的foo声明等价于下面的，也就是一个extern被隐藏了。
extern int foo(int arg1, char arg2);
int main(){
    echo("hello world");
}
//定义只能一次，定义会分配存储。定义是声明的超集
//apart from the role of the declaration,
// it also allocates memory for that variable/function.
void echo(char *msg){
    printf("%s", msg);
}


