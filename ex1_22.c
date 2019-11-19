//
// Created by cuixin on 2019/11/19.
//
#include "stdio.h"

#define MAX_LINE_LENGTH 1000

int getLine(char line[], int lim);

int main() {
    char line[MAX_LINE_LENGTH];
    int lineLength = 0;
    int columns_nums_to_newline = 2;
    int before_is_space = 0;
    while ((lineLength = getLine(line, MAX_LINE_LENGTH)) > 0) {
        int count_columns = 0;
        for (int i = 0; i < lineLength; i++) {
            putchar(line[i]);
            if ((line[i] == ' ' || line[i] == '\t') && !before_is_space) {
                count_columns++;
                before_is_space = 1;
                ++i;
                while (i < lineLength && (line[i] == ' ' || line[i] == '\t')) {
                    putchar(line[i]);
                    i++;
                }
                --i;
            }else{
                before_is_space = 0;
            }
            if (count_columns == columns_nums_to_newline) {
                before_is_space = 0;
                putchar('\n');
                count_columns = 0;
            }
        }
    }
}


/**
 * k & r page 29
 */
int getLine(char line[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '0';
    return i;
}