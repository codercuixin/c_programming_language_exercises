//
// Created by cuixin on 2019/11/25.
//
#include "stdio.h"
void expand(char s1[], char s2[]);
int isEnglishCharacter(char c);
int isNumber(char c);

int main(){
    char s1[] ="-a-b-d-0-9-a-z-";
    char s2[1000];
    expand(s1, s2);
    printf("%s", s2);
}
void expand(char s1[], char s2[]){
    int indexS1= 0;
    int indexS2 = 0;
    while (s1[indexS1] != '\0'){
        if(s1[indexS1] == '-'){
            if(indexS1 != 0){
                char previous = s1[indexS1 -1];
                char next = s1[indexS1+1];
                if(isEnglishCharacter(previous) && isEnglishCharacter(next)){
                   int delta = next - previous;
                   if(delta > 1){
                       for( int i=1; i<delta; i++){
                           s2[indexS2++] = previous+i;
                       }
                   }else{
                       s2[indexS2++] = '-';
                   }
                }else if(isNumber(previous) && isNumber(next)){
                    int delta = next - previous;
                    if(delta > 1){
                        for( int i=1; i<delta; i++){
                            s2[indexS2++] = previous+i;
                        }
                    }else{
                        s2[indexS2++] = '-';
                    }
                }else{
                    s2[indexS2++] = '-';
                }
            }else{
                s2[indexS2++] = s1[indexS1];
            }
        }else{
            s2[indexS2++] = s1[indexS1];
        }
        indexS1++;
    }
    s2[indexS2] = '\0';

}

int isEnglishCharacter(char c){
    return c >='a' && c <= 'z';
}
int isNumber(char c){
    return c>='0' && c<='9';
}