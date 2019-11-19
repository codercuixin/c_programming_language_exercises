//
// Created by cuixin on 2019/11/19.
//
#include <stdio.h>
void squeeze(char s1[], char s2[]);
int inStr(char s[], char c);

int main(){
    char s1[] ="hello";
    char s2[] ="how";
    squeeze(s1, s2);
    printf("%s", s1);
}

// K & r page 46
void squeeze(char s1[], char s2[]){
    int i,j;
    for( i=0, j=0; s1[i] !='\0'; i++){
        if(!inStr(s2, s1[i])){
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
// if you want to run fast,you cache the result
int inStr(char s[], char c){
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == c){
            return 1;
        }
        i++;
    }
    return 0;
}