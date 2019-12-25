//
// Created by cuixin on 2019/12/25.
//

#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]){
    char *p = argv[0];
    for(; p != NULL; p=p+1){
        if(isalpha(*p)) {
            putchar(toupper(*p));
        }else{
            putchar(*p);
        }
    }

}