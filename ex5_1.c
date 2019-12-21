//
// Created by cuixin on 2019-12-21.
// gcc ex5_1.c charutil.c
//
#include "charutil.h"
#include <stdio.h>
#define SIZE 5
int main(){
    int n, array[SIZE], getint(int *);
    for(n=0; n<SIZE && getint(&array[n])!=EOF; n++){
        printf("%d", array[n]);
    }

}

#include <ctype.h>

/*将输入中的下一个整形数赋值给*pn*/
int getint(int *pn){
    int c, sign;
    while(isspace(c = getch())); //跳过空格
    if(!isdigit(c) && c!=EOF && c!='+' && c != '-'){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1:1;
    if(c == '-' || c=='+'){
        c = getch();
        if(!isdigit(c)){
            ungetch(sign == -1? '-':'+');
            return 0;
        }
    }
    for(*pn =0; isdigit(c); c=getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if( c != EOF){
        ungetch(c);
    }
    return c;
}

