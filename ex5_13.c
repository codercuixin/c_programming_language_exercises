//
// Created by cuixin on 2019-12-22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//通过排序的最大文本行数
#define MAXLINES 5000

char *lineptr[MAXLINES]; //指向文本行的指针数组

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

int getline_v1(char s[], int lim);


char *alloc(int n);

void afree(char *p);

#define ALLOCSIZE 10000 /*  可用空间大小 */
static char allocbuf[ALLOCSIZE]; /* alloc 使用的存储区域*/
static char *allocp = allocbuf; /* 保存下一个空闲的位置*/

char *alloc(int n) { /* 返回指向n个字符首字符地址的指针*/
    if (allocbuf + ALLOCSIZE - allocp >= n) { /*有足够的空闲空间*/
        allocp += n;
        return allocp - n;
    } else {
        return 0; //c语言保证0永远不会是有效的数据地址。
    }
}

void afree(char *p) { /*释放从p指向的存储区*/
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

//对输入的文本行进行排序
int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2) {
        char *p = argv[1];
        if(p[0] == '-'){
            n = atoi(p+1);
        }
    }
    int nlines; //读取的输入行数目
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        int start = nlines - n >= 0 ? nlines - n : 0;
        for (int i = start; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
    } else {
        printf("error: input too big to sort");
        return 1;
    }
}

#define MAXLEN 1000 //定义输入文本行的最大长度

//readlines函数，读取输入行
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline_v1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/**
 *  将一行读入s中并返回其长度
 * @param s 读入s中
 * @param lim
 * @return 当前行的长度
 */
int getline_v1(char s[], int lim) {
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