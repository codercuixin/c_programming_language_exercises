//
// Created by cuixin on 2019-12-21.
// todo 为什么macos不支持*s++
//
#include "stdio.h"
void strcat_v1(char *s, char *t);
int main(){
    char s1[100] = "hello world";
    char s2[100] = " do you remember me?";
    strcat_v1(s1, s2);
    printf("%s\n",s1);

}
//void strcat_v1(char *s, char *t){
//    //将指针移到原来s的尾部
//    while(*s++){
//    }
//
//    //将t的字符连后s后面
//    while(*s++ = *t++){
//
//    }
//
//}
void strcat_v1(char *s, char *t){
    //将指针移到原来s的尾部
    while(*s != '\0'){
        s++;
    }

    //将t的字符连后s后面
    while(*s = *t){
        s++;
        t++;
    }

}