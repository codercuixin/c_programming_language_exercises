//
// Created by cuixin on 2019/11/18.
//

#include <stdio.h>
int main(){
    int c;
    int beforeIsWord = 0;
    while( (c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            if(beforeIsWord){
                putchar('\n');
                beforeIsWord = 0;
            }
        }else{
            putchar(c);
            beforeIsWord = 1;
        }
    }
}