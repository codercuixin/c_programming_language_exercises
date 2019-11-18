//
// Created by cuixin on 2019/11/18.
//Windows crt+z then enter
//Linux crt+d
//
#include <stdio.h>

int main() {
    int spaceCount = 0;
    int tableCount = 0;
    int newLineCount = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaceCount++;
        } else if (c == '\t') {
            tableCount++;
        } else if (c == '\n') {
            newLineCount++;
        }
    }
    printf("spaceCount=%d, tableCount=%d, newLineCount=%d", spaceCount, tableCount, newLineCount);
}
