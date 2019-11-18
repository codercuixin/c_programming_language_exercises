//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>

int main() {
    int c;
    while (c = (getchar() != EOF)) {
       if(c == 0){
           printf("c == 0");
       }else{
           printf("c= %d",c);
       }
    }
}