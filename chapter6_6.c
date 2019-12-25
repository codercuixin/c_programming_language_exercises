//
// Created by cuixin on 2019/12/25.
//
struct nlist {
    //todo 下面的next好像没用到
    struct nlist *next; //链表中的下一项
    char *name; //定义的名字
    char *defn; //替换文本
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);

char *strdup_mine(char *);
struct nlist *install(char *name, char *defn);
void undef(char *s);
#include <stdio.h>
#include <string.h>

int main() {
    install("k1", "hello");
    install("k2", "world");
    undef("k1");
//    install("k1", "hi");

    struct nlist *p = lookup("k1");
    if (p != NULL) {
        printf("(%s, %s)\n", p->name, p->defn);
    }
    p = lookup("k2");
    if (p != NULL) {
        printf("(%s, %s)\n", p->name, p->defn);
    }
}

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}


#include <stdlib.h>

/**
 * 将(name, defn)加入到hashtab中
 * @param name
 * @param defn
 * @return
 */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashVal;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup_mine(name)) == NULL) {
            return NULL;
        }
        hashVal = hash(name);
        np->next = hashtab[hashVal];
        hashtab[hashVal] = np;
    } else {
        free((void *) np->defn);
    }
    if ((np->defn = strdup_mine(defn)) == NULL) {
        return NULL;
    }
    return np;
}

void undef(char *s){
     struct nlist *p = hashtab[hash(s)];
     if(p != NULL){
         p->next = NULL;
         free((void*)p->name);
         free((void*)p->defn);
         p = NULL;
     }
}

char *strdup_mine(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL){
        strcpy(p, s);
    }
    return p;
}