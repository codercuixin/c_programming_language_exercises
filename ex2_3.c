//
// Created by cuixin on 2019/11/19.
//
#include "stdio.h"

int htoi(char s[]);

int main() {
    char s[] = "0x11";
    char s2[] = "0Xf1";
    char s3[] = "e1";
    char s4[] = "0";
    printf("%d\n", htoi(s));
    printf("%d\n", htoi(s2));
    printf("%d\n", htoi(s3));
    printf("%d\n", htoi(s4));
}

int htoi(char s[]) {
    int i = 0;
    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        i = 2;
    }
    int sum = 0;
    //c语言字符串最后一个字符为\0,可以利用这个来遍历。
    while (s[i] != '\0') {
        int curNum;
        if (s[i] >= '0' && s[i] <= '9') {
            curNum = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            curNum = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            curNum = s[i] - 'A' + 10;
        } else {
            printf("the input is invalid\n");
            return 0;
        }
        sum = sum * 16 + curNum;
        i++;
    }
    return sum;
}