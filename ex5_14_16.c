//
// Created by cuixin on 2019-12-22.
//gcc ex5_14
//./a.out -f -d -r
// DO YOU love ME
//do you love me
//DARGON
//DO      you love me
//DTO
//^D
//
//
//DTO
//do you love me
//DO YOU love ME
//DO      you love me
//DARGON
//

#include <stdio.h>
#include <string.h>
//通过排序的最大文本行数
#define MAXLINES 5

#include <ctype.h>

char *lineptr[MAXLINES]; //指向文本行的指针数组

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

int getline_v1(char s[], int lim);

void qsort_v1(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int cmp(char *s1, char *s2);

int strcmp_inner(char *s1, char *s2);

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

int numeric = 0; //若进行数值排序，则numeric的值为1
int reverse = 0; //是否倒序排序。
int caseSensitive = 1; //字符串比较时，大小写是否敏感
int alphabetNumberSpaceOnly = 0;

//对输入的文本行进行排序
int main(int argc, char *argv[]) {
    int nlines; //读取的输入行数目
    while (argc-- > 1) {
        char *p = *++argv;
        if(*p++ == '-'){
            while(*p != '\0'){
                switch(*p){
                    case 'n':
                        numeric =1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                    case 'd':
                        alphabetNumberSpaceOnly = 1;
                        break;
                    case 'f':
                        caseSensitive = 0;
                        break;
                    default:
                        printf("error arg -%s", p);
                        return 1;
                }
                p++;
            }
        }else{
            printf("error arg %s", p);
            return 1;
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_v1((void **) lineptr, 0, nlines - 1,
                 (int (*)(void *, void *)) cmp);
        printf("\n\n");
        writelines(lineptr, nlines);
        return 0;
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
        if (nlines >= maxlines) {
            return nlines;
        } else if ((p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void qsort_v1(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int i, int j);
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    //划分交换
    for (int i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort_v1(v, left, last - 1, comp);
    qsort_v1(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

#include <stdlib.h>


int cmp(char *s1, char *s2) {
    int res;
    if (numeric) {
        double v1, v2;
        v1 = atof(s1);
        v2 = atof(s2);
        if (v1 < v2) {
            res = -1;
        } else if (v1 > v2) {
            res = 1;
        } else {
            res = 0;
        }
    } else {
        res = strcmp_inner(s1, s2);
    }

    if (reverse) {
        return -res;
    }
}

int strcmp_inner(char *s1, char *s2) {
    if (alphabetNumberSpaceOnly) {
        while (1) {
            //尝试找到第一个满足要求的s1字符
            while (*s1 != '\0' && !(isdigit(*s1) || isalpha(*s1) || isspace(*s1))) {
                s1++;
            }
            //尝试找到第一个满足要求的s2字符
            while (*s2 != '\0' && !(isdigit(*s2) || isalpha(*s2) || isspace(*s2))) {
                s2++;
            }
            if (*s1 == '\0' && *s2 == '\0') {
                return 0;
            } else if (*s1 == '\0' && *s2 != '\0') {
                return -1;
            } else if (*s1 != '\0' && *s2 == '\0') {
                return 1;
            } else {
                //比较两个字符
                if (!caseSensitive) {
                    int temp1 = tolower(*s1);
                    int temp2 = tolower(*s2);
                    if (temp1 != temp2) {
                        return temp1 - temp2;
                    }
                } else if (*s1 != *s2) {
                    return *s1 - *s2;
                }
                //比较下一个字符
                s1++;
                s2++;
            }
        }
    } else {
        if (caseSensitive) {
            return strcmp(s1, s2);
        } else {
            return strcmpi(s1, s2);
        }
    }
}