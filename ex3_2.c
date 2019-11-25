//
// Created by cuixin on 2019/11/25.
//
#include "stdio.h"
void escape(char s[], char t[]);
int main(){
    char s[100];
    char t[] = "hello world\t\nwho are you\r\v\"Hello ";
    printf("%s",t);
    escape(s, t);
    printf("\nafter escape:\n");
    printf("%s",s);
}
void escape(char s[], char t[]){
    int indexT = 0;
    int indexS = 0;
    while(t[indexT] != '\0'){
        switch (t[indexT]){
            case '\f':
                s[indexS++] = '\\';
                s[indexS++] = 'f';
                break;
            case '\t':
                s[indexS++] = '\\';
                s[indexS++] = 't';
                break;
            case '\r':
                s[indexS++] = '\\';
                s[indexS++] = 'r';
                break;
            case '\v':
                s[indexS++] = '\\';
                s[indexS++] = 'v';
                break;
            case '\"':
                s[indexS++] = '\\';
                s[indexS++] = '"';
                break;
            case '\n':
                s[indexS++] = '\\';
                s[indexS++] = 'n';
                break;

            default:
                s[indexS++] = t[indexT];
                break;
        }
        indexT++;
    }
    s[indexS] = '\0';
}