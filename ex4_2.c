//
// Created by cuixin on 2019/11/27.
//
#include <ctype.h>
#include "stdio.h"
double atof(char s[]);
int main(){
//    char s[] = "123.45e-6";
//    char s[] = "123.45e+6";
    char s[] = "123.45e6";
    double d = atof(s);
    printf("%.9f", d);
}

double atof(char s[]){
    double val, power;
    int i,sign;
    for(i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-'){
        i++;
    }
    for(val = 0.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.'){
        i++;
    }
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val +(s[i] - '0');
        power *= 10.0;
    }
    val = sign * val /power;

    if(s[i] != 'e'){
        return val;
    }
    i++;
    sign = 1;
    if(s[i] == '-'){
        sign = -1;
    }
    if(s[i] == '-' || s[i] == '+'){
        i++;
    }
    int exp = 0;
    for(; isdigit(s[i]); i++){
        exp = exp * 10 + (s[i] - '0');
    }
    double expNumber =1;
    for(int index=0; index< exp; index++){
        expNumber = expNumber * 10;
    }
    if(sign == 1){
        return val * expNumber;
    }else{
        return  val /expNumber;
    }
}

//int isspace(char c){
//    return c == ' ' ? 1: 0;
//}