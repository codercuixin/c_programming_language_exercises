//
// Created by cuixin on 2019/12/23.
//
#include "stdio.h"
#include <stdlib.h>
int main(int argc, char *argv[]) {
    //tabs_size其实指定了每个单词占据的长度， 任何一个单词长度都不能超过它。
    int tabs_size = 8;
    if(argc == 2){
        tabs_size = atoi(argv[1]);
    }
    int curLineLength = 0;
    int curChar;
    while ((curChar = getchar()) != EOF) {
        if (curChar == '\t') {
            int delta = tabs_size - (curLineLength % tabs_size);
            while (delta-- > 0) {
                putchar(' ');
                curLineLength++;
            }
        } else if (curChar == '\n') {
            putchar(curChar);
            curLineLength = 0;
        } else {
            putchar(curChar);
            curLineLength++;
        }
    }
}


//
// Created by cuixin on 2019/11/19.
//

#include "stdio.h"

#define MAX_LINE 1000    //max input line size
#define TAB_TO_SPACE  4 // 4 spaces to a tab

//char line[MAX_LINE];
//int getLine(void);
//int main(){
//    int len;
//    while((len = getLine()) > 0){
//        int spaceCount = 0;
//        for(int i=0; i<len; i++){
//            if(line[i] == ' '){
//                spaceCount++;
//            }
//            if(line[i] != ' '){
//                spaceCount = 0;
//            }
//            //遇到连续TAB_TO_SPACE个空格，才替换成空格，
//            if(spaceCount == TAB_TO_SPACE){
//                i -= (TAB_TO_SPACE - 1);
//                len -= (TAB_TO_SPACE - 1);
//                line[i] = '\t';
//                //并将改行后面的数据往前移动。
//                for(int j=i+1; j<len; j++){
//                    line[j] = line[j+(TAB_TO_SPACE-1)];
//                }
//                spaceCount = 0;
//                line[len] = '\0';
//            }
//        }
//        printf("%s", line);
//    }
//}

//int getLine(void){
//    int c, i;
//    extern char line[];
//    for(i =0; i <MAX_LINE-1 && ( c = getchar()) !=EOF && c!='\n'; ++i){
//        line[i] = c;
//    }
//    if( c == '\n'){
//        line[i] = c;
//        ++i;
//    }
//    line[i] = '0';
//    return i;
//}