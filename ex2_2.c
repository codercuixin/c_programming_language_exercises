//
// Created by cuixin on 2019/11/19.
//
#include "stdio.h"
int main(){
    int lim = 1000;
    int s[lim];
    int c;
    for(int i=0; i<lim-1; i++){
        c = getchar();
        if(c == '\n'){
            break;
        }
        if(c == EOF){
            break;
        }
    }
}