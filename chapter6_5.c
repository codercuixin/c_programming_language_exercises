//
// Created by cuixin on 2019/12/25.
//
//

struct tnode {  //树节点
    char *word; //指向单词char的指针
    int count; // 单词出现的次数
    struct tnode *left; //左指针
    struct tnode *right; //右指针
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "charutil.h"
#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *);

int getword(char *, int);

/**
 * 分配新节点的存储空间，返回一个指针，指针能容纳一个树节点的空闲空间。
 * @return
 */
struct tnode *talloc(void);

char *strdup_mine(char *);

//单词出现频率的统计
int main() {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup_mine(w);
        p->count = 1;
        p->left = p->right = NULL;
    }else if((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }else if(cond < 0){
        p->left = addtree(p->left, w);
    }else{
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_mine(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL){
        strcpy(p, s);
    }
    return p;
}
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    //跳过空格
    while (isspace(c = getch())) {

    }

    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        //包含数字字符
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}