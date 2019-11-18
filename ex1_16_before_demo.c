//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>
#define MAXLINE  1000
int getline(char line[], int maxLength);
void copy(char to[], char from[]);

int main(){
    //当前行长度
    int len;
    //目前为止发现的最长行的长度
    int max;
    //当前的输入行
    char line[MAXLINE];
    //用于保存最长的行
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0){
        //存在这样的行
        printf("%s", longest);
    }
}
/**
 *  将一行读入s中并返回其长度
 * @param s 读入s中
 * @param lim
 * @return 当前行的长度
 */
int getline(char s[], int lim){
    int c, i;
    for( i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/**
 * 将from复制到to，这里假定to足够大
 * @param to
 * @param from
 */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0'){
        ++i;
    }
}