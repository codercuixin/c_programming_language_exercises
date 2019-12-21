//
// Created by cuixin on 2019-12-21.
//
#include "stdio.h"
int strend(char *s, char *t);
int main(){
    char s1[100] = "hello world";
    char s2[100] = "1 world";
    int res= strend(s1, s2);
    printf("%d\n",res);

}

int strend(char *s, char *t){
    //将s和t移到尾部
    while(*s !='\0'){
        s++;
    }
    int tLen = 0;
    while(*t !='\0'){
        t++;
        tLen++;
    }
    //从t的最后一个字符开始和s的最后一个比较。
    while(tLen >= 0){
        if(*s != *t){
            return 0;
        }
        s--;
        t--;
        tLen--;
    }
    return 1;

}