//
// Created by cuixin on 2019/11/18.
//

//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>

#define MAXLINE  1000

int getline(char line[], int maxLength);

int main() {
    //当前行长度
    int len;
    //目前为止发现的最长行的长度
    //当前的输入行
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("len: %d, str : %s", len, line);
        }
    }
}

/**
 *  将一行读入s中并返回其长度
 * @param s 读入s中
 * @param lim
 * @return 当前行的长度
 */
int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}