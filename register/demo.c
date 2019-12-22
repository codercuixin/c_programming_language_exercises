//
// Created by cuixin on 2019-12-22.
//

//https://www.geeksforgeeks.org/understanding-register-keyword/
#include <stdio.h>
//int main(){
//    register  int i = 20;
//
//    int *a = &i; //error : address of register variable requested ，放在寄存器中的变量不可以取址（内存地址）。
//    printf("%d", *a);
//    getchar();
//    return 0;
//}

//int main(){
//    int i = 20;
//
//    register int *a = &i; //register int指针里面存的是i的地址，是ok的。
//    printf("%d", *a);
//    getchar();
//    return 0;
//}

//int main(){
//    int i = 20;
//    // error: static cannot combine with previous 'register' declaration specifier
//    register static int *a = &i; //register是寄存器文件，而static存在bbs或者data中，https://www.geeksforgeeks.org/memory-layout-of-c-program/
//    printf("%d", *a);
//    getchar();
//    return 0;
//}

// error: illegal storage class on file-scoped variable
register x = 20;
int main(){
     register int i = 20;
    printf("%d", i);
    printf("%d", x);
    getchar();
    return 0;
}