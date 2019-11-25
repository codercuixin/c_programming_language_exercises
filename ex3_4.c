//
// Created by cuixin on 2019/11/25.
//

// 不能表示最大的负数的原因，有符号数的范围存储范围是[-2^n, 2^n - 1],而代码里如果n为负数，就执行n=-n操作
// 如果是最大负数，会发生溢出。

#include "stdio.h"
#include "string.h"
void reverse(char s[]);
void itoa(int n, char s[]);
int main(){
   int n = -120;
   char s[100];
   itoa(n, s);
   printf("%s", s);

}
void itoa(int n, char s[]){
    int i,sign;
    if(n < 0){
        sign = -1;
    }
    i = 0;
    do{
        int delta = n% 10 < 0 ? - (n% 10): n%10;
        s[i++] = delta + '0';
    }while ((n/=10) != 0);

    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int len =  strlen(s);
    for(int left = 0, right = len -1; left < right; left++, right --){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}

