//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>

void reverse(char s[]);

int main() {
    char s[] = "hello world";
    reverse(s);
}

void reverse(char s[]) {
    int number = 0;
    while (s[number] != '\0') {
        number++;
    }
    for (int i = number; i >= 0; i--) {
        putchar(s[i]);
    }
    putchar('\n');
}