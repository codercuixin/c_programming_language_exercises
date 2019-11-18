//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>
int main(){
    int c ;
    int previousCharIsSpace = 0;
    while((c=getchar()) != EOF){
        if(c == ' '){
            if(previousCharIsSpace){
                continue;
            }else{
                putchar(c);
                previousCharIsSpace = 1;
            }
        }else{
            previousCharIsSpace = 0;
            putchar(c);
        }
    }
}
