//
// Created by cuixin on 2019-12-21.
//
#include "stdio.h"
//将字符中t的最多n个字符复制到字符串s中，并返回s。如果t中少于n个字符，则用'\0'填充。
char *strncpy(char *s,char *t,int n);
//将字符中t的最多n个字符连接到字符串s中，并以'\0'结束，该函数返回s
char *strncat(char *s,char *t,int n);
//将s中的最多前n个字符与t比较，如果s<t，则返回负数；如果s>t,则返回正数；否则返回0
int *strncmp(char *s,char *t, int n);

int main(){
    char s[100] = ""; //这里要给s分配大一点的内存，不能用指针，因为t后分配在s后面。
    char *t = "do you remember me";
    char *p = strncpy(s, t, 6);
    printf("%s\n", p);
    char *p2 = strncat(s, t+6, 5);
    printf("%s\n", p2);

    int res= strncmp("hello2", "hello world", 5);
    printf("%d\n", res);

}

char *strncpy(char *s,char *t,int n){
    char *p = s;
    while(*t!='\0' && n>0){
        *p = *t;
        p++;
        t++;
        n--;
    }
    *p = '\0';
    return s;
}
char *strncat(char *s,char *t,int n){
    //将s移到'\0'
    char *p = s;
    while(*p!='\0'){
        p++;
    }
    while(*t!='\0' && n>0){
        *p = *t;
        p++;
        t++;
        n--;
    }
    *p = '\0';
    return s;
}

int *strncmp(char *s,char *t, int n){
    while(*s!='\0' && n>0){
        if(*t == '\0'){
            return -1;
        }
        else if(*s != *t){
            return *s - *t;
        }
        t++;
        s++;
        n--;
    }
    return 0;
}