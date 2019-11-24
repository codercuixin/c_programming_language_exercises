//
// Created by cuixin on 2019-11-24.
//
int lower(int c);
#include "stdio.h"
int main(){
    printf("%c", lower('A'));
}
int lower(int c){
    return c >='A' && c <='Z' ? c-'A' + 'a': c;
}