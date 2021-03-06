//
// Created by cuixin on 2019/12/24.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "charutil.h"

#define MAXTOKEN 100
enum {
    NAME, PARENS, BRACKETS
};

int gettoken(void);

void dc1(void);

void dirdc1(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000]; //输出串

int main() {
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n') {
            printf("syntax error");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int main2() {
    int type;
    char temp[MAXTOKEN];
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

void dc1(void) {
    int ns;//用来统计字符*的个数
    for (ns = 0; gettoken() == '*';) {
        ns++;
    }
    dirdc1();
    while (ns-- > 0) {
        strcat(out, " pointer to")
    }
}

void dirdcl(void) {
    int type;
    if (tokentype == '(') {
        dc1();
        if (tokentype ! = ')'){
            printf("error: missing )\n");
        }
    } else if (tokentype == NAME) {
        strcpy(name, token);
    } else {
        printf("error: expected name or (dcl) \n");
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t') {

    }
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        };
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';) {}
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c, isalnum(c = getch());) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}