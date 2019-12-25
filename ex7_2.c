//
// Created by cuixin on 2019/12/25.
//
#define MAxLINE 20
#include <ctype.h>
#include <stdio.h>
int getline_v1(char s[], int lim);
char s[MAxLINE];
int main(){
    int count = 0;
    while(getline_v1(s, MAxLINE) > 0){
        for(int i=0; i<MAxLINE && s[i] != '\0'; i++){
            if(isgraph(s[i])){
                putchar(s[i]);
            }else{
                printf("%x", s[i]);
            }
        }
    }
}

int getline_v1(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}