//
// Created by cuixin on 2019/11/18.
//
#include "stdio.h"

int main() {
    //tabs_size其实指定了每个单词占据的长度， 任何一个单词长度都不能超过它。
    int tabs_size = 7;
    int curLineLength = 0;
    int curChar;
    while ((curChar = getchar()) != EOF) {
        if (curChar == '\t') {
            int delta = tabs_size - (curLineLength % tabs_size);
            while (delta-- > 0) {
                putchar(' ');
                curLineLength++;
            }
        } else if (curChar == '\n') {
            putchar(curChar);
            curLineLength = 0;
        } else {
            putchar(curChar);
            curLineLength++;
        }
    }
}
