//
// Created by cuixin on 2019/11/18.
//
#include <stdio.h>
#define MAX_WORD_LENGTH  20;
int main(){
    //单词长度不能超过20
    int max_word_length = MAX_WORD_LENGTH;
    int  countPerLength[max_word_length];
    for(int i=0; i< max_word_length; i++){
        countPerLength[i] = 0;
    }
    int wordLength =0;
    int c ;
    while( (c = getchar()) !=EOF){
        if( c == ' ' || c == '\t' || c == '\n'){
            if(wordLength > 0 && wordLength < max_word_length){
                countPerLength[wordLength - 1] ++;
                wordLength = 0;
            }else{
                wordLength = 0;
            }
        }else{
            wordLength++;
        }
    }
    for(int i=0; i<max_word_length; i++){
        if(countPerLength[i] > 0){
            printf("length:%d, how many:%d\n", i+1, countPerLength[i]);
        }
    }
}
