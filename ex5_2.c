//
// Created by cuixin on 2019-12-21.
//

//
// Created by cuixin on 2019-12-21.
// gcc ex5_2.c charutil.c
//
#include "charutil.h"
#include <stdio.h>
#define SIZE 5
int main(){
    int n,getfloat(float *);
    float array[SIZE];
    for(n=0; n<SIZE && getfloat(&array[n])!=EOF; n++){
        printf("%g\n", array[n]);
    }

}

#include <ctype.h>

/*将输入中的下一个整形数赋值给*pn*/
int getfloat(float *pn){
    int c, sign;
    while(isspace(c = getch())); //跳过空格
    if(!isdigit(c) && c!=EOF && c!='+' && c != '-' && c!='.'){
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
    double decimalSum = 0.0;
    if(c == '.'){
        c = getch();
        double pow = 0.1;
        for(; isdigit(c); c=getch()){
            decimalSum = decimalSum + pow * (c - '0');
            pow *= 0.1;
        }
        *pn += decimalSum;
    }
    *pn *= sign;
    if( c != EOF){
        ungetch(c);
    }
    return c;
}

