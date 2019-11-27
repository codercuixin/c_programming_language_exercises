//
// Created by cuixin on 2019/11/27.
//
#include "stdio.h"
int strrindex(char s[], char t[]);
int main(){
    char s[] ="abcdab";
    char t[] ="ab";
    int res =  strrindex(s, t);
    printf("%d", res); //4
}
int strrindex(char s[], char t[]){
    int i, j ,k;
    int res = -1;
    for( i = 0 ; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if(k > 0 && t[k] == '\0'){
            if(i > res){
                res = i;
            }
        }
    }
    return res;
}