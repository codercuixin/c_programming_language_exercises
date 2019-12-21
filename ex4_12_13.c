//
// Created by cuixin on 2019/11/25.
//

// 不能表示最大的负数的原因，有符号数的范围存储范围是[-2^n, 2^n - 1],而代码里如果n为负数，就执行n=-n操作
// 如果是最大负数，会发生溢出。

#include "stdio.h"
#include "string.h"
void reverse(char s[]);
void doReverse(char s[], int left, int right);
void itoa(int n, char s[]);
void doitoa(int n, int nLen, char *s);
int getNLen(int n);
int main(){
    int n = -120;
    char s[100];
    itoa(n, s);
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
}
void itoa(int n, char s[]){
    int nLen = getNLen(n);
    doitoa(n, nLen, s);
}
int getNLen(int n){
    int len = 0;
    if(n  < 0){
        n = -n;
        len++;
    }
    int num = 1;
    while(n >= num){
        len++;
        num *= 10;
    }
    return len;
}
void doitoa(int n, int nLen, char s[]){
    if(n < 0){
        n = -n;
        s[0] = '-';
    }
    if(n/10){
        doitoa(n/10, nLen-1, s);
    }
    s[nLen-1] = n % 10 + '0';
}
void reverse(char s[]){
    int len = strlen(s);
    if(len > 0){
        doReverse(s, 0, len-1);
    }
}
void doReverse(char s[], int left, int right){
    if(left >= right){
        return;
    }
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    doReverse(s, left+1, right-1);
}

