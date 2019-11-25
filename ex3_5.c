//
// Created by cuixin on 2019/11/25.
//

//
// Created by cuixin on 2019/11/25.
//

// 不能表示最大的负数的原因，有符号数的范围存储范围是[-2^n, 2^n - 1],而代码里如果n为负数，就执行n=-n操作
// 如果是最大负数，会发生溢出。

#include "stdio.h"
#include "string.h"
void reverse(char s[]);
void itob(int n, char s[], int b);
int main(){
    int n = -120;
    char s[100];
    int b = 36;
    itob(n, s, b);
    printf("%s", s);

}
/**
 * 10进制以下以0-9表示，10进制以上以 0-9 及a-z后面的字符表示
 * 最多支持36进制。
 * @param n
 * @param s
 * @param b
 */
void itob(int n, char s[], int b){
    if(n > 36){
        printf("不支持%d进制", n);
        return;
    }
    int i,sign;
    if(n < 0){
        sign = -1;
    }
    i = 0;
    do{
        int remainder = n %b;
        int delta = remainder < 0 ? -remainder: remainder;
        if(delta >= 10){
            s[i++] = delta -10 + 'a';
        }else{
            s[i++] = delta + '0';
        }
    }while ((n/=b) != 0);

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

