//
// Created by cuixin on 2019/12/20.
//

#include <stdio.h>
int fun(){
    static int count = 0;
    count++;
    return count;
}
int fun2(){
    int count = 0;
    count++;
    return count;
}
int main(){
//    printf("%d ", fun());
//    printf("%d ", fun());

    printf("%d ", fun2());
    printf("%d ", fun2());
}