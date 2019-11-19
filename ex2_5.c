//
// Created by cuixin on 2019/11/19.
//
#include "stdio.h"

int inStrIndex(char s[], char c);

int any(char s1[], char s2[]);

int main() {
    char s1[] = "hello";
    char s2[] = "echo";
    printf("%d", any(s1, s2));
}

int any(char s1[], char s2[]) {
    int i = 0;
    int res = -1;
    while (s2[i] != '\0') {
        if ((res = inStrIndex(s1, s2[i])) != -1) {
            return res;
        }
        i++;
    }
    return -1;
}

int inStrIndex(char s[], char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}
