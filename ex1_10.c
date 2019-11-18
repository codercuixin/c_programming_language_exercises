//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>
int main(){
    int c;
    while( ( c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }else{
            putchar(c);
        }
    }
}

