//
// Created by cuixin on 2019-12-21.
//

#define ALLOCSIZE 10000 /*  可用空间大小 */
static char allocbuf[ALLOCSIZE]; /* alloc 使用的存储区域*/
static char *allocp = allocbuf; /* 保存下一个空闲的位置*/

char *alloc(int n){ /* 返回指向n个字符首字符地址的指针*/
    if(allocbuf + ALLOCSIZE - allocp >= n){ /*有足够的空闲空间*/
        allocp += n;
        return allocp - n;
    }else{
        return 0; //c语言保证0永远不会是有效的数据地址。
    }
}
void afree(char *p){ /*释放从p指向的存储区*/
    if(p >=allocbuf && p < allocbuf + ALLOCSIZE){
        allocp = p;
    }
}
int strlen_v1(char *s){
    int n;
    for(n=0; *s != '\0'; s++){
        n++;
    }
    return n;
}

int strlen_v2(char *s){
    char *q = s;
    while(*s != '\0'){
        s++;
    }
    return s - q ;
}
//字符串复制，使用下标实现。
void strcpy_v1(char *s, char *t){
    int i=0;
    while((s[i] = t[i])!='\0'){
        i++;
    }

}
//字符串复制，使用指针实现
void strcpy_v2(char *s, char *t){
    while((*s= *t)!='\0'){
        s++;
        t++;
    }
}
//字符串复制，，使用指针实现版本2
// 一元操作符，从右向左，++表明先执行 *s,再给s的值+1， 也就是*s++ = *t++等价于 *s = *t; s+=1; t+=1;
void strcpy_v3(char *s, char *t){
    while( (*s++ = *t++)!='\0'){

    }
}

//字符串复制，，使用指针实现版本3,最后为字符\0,只需要判断表达式的值是否为0即可。
void strcpy_v4(char *s, char *t){
    while (*s++=*t++){}
}
//字符串比较，将s的每个字符按字典顺序与t对应的字符比较，由前往后比较，直到遇到不等的字符或是s到结尾了。
int strcmp(char *s, char *t){
    int i;
    for(i = 0; s[i] == t[i]; i++){
        if(s[i] == '\0'){
            return 0;
        }
    }
    return s[i] - t[i];
}
int strcmp(char *s, char *t){
    for(; *s == *t; s++, t++){
        if(*s == '\0'){
            return 0;
        }
    }
    return *s - *t;
}
#include "stdio.h"
int main(){
    printf("%d\n", strlen_v2("hello world"));
    char *s = "hello";
    printf("s> 0 为%d\n", s>0 ? 1: -1);

    char s2[100];
    strcpy_v3(s2, "hello world");
    printf("%s\n", s2);

    strcpy_v4(s2, "hello world");
    printf("%s\n", s2);
}