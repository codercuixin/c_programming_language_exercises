//
// Created by cuixin on 2019/11/19.
//

#include "stdio.h"

#define MAX_LINE 1000    //max input line size
#define TAB_TO_SPACE  4 // 4 spaces to a tab

char line[MAX_LINE];
int getLine(void);
int main(){
    int len;
    while((len = getLine()) > 0){
        int spaceCount = 0;
        for(int i=0; i<len; i++){
            if(line[i] == ' '){
                spaceCount++;
            }
            if(line[i] != ' '){
                spaceCount = 0;
            }
            //遇到连续TAB_TO_SPACE个空格，才替换成空格，
            if(spaceCount == TAB_TO_SPACE){
                i -= (TAB_TO_SPACE - 1);
                len -= (TAB_TO_SPACE - 1);
                line[i] = '\t';
                //并将改行后面的数据往前移动。
                for(int j=i+1; j<len; j++){
                    line[j] = line[j+(TAB_TO_SPACE-1)];
                }
                spaceCount = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
}

int getLine(void){
    int c, i;
    extern char line[];
    for(i =0; i <MAX_LINE-1 && ( c = getchar()) !=EOF && c!='\n'; ++i){
        line[i] = c;
    }
    if( c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '0';
    return i;
}