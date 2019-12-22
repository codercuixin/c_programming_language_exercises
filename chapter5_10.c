//
// Created by cuixin on 2019-12-22.
//

#include <stdio.h>
//int main(int argc, char* argv[]){
//    int i;
//    for( i=1; i< argc; i++){
//        printf("%s%s", argv[i], i < argc-1 ?" ": "");
//    }
//}
//
//int main(int argc, char* argv[]){
//   while(--argc > 0){
//       //单元操作符，从右向左结合。
//       printf("%s%s", *++argv, argc==1 ?"":" ");
//   }
//}

#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    // argv存的是第一个字符串的地址，先++，使其存的为第二个字符串的地址，然后用*取出该字符串首字母的地址。
    while (--argc > 0 && (*++argv)[0] == '-') {
        // argv[0] 为该字符串的第一个字符地址，先++,使其指向下一个字符地址，再用*取值。
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find : illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if(argc != 1) {
        printf("Usage: find -x -n pattern\n");
    }else{
        while (getline(line, MAXLINE) > 0){
            lineno++;
            if((strstr(line, *argv)!=NULL) != except){
                if(number){
                    printf("%d", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}


//int main(int argc, char * argv[]){
//    char line[MAXLINE];
//    int found = 0;
//    if(argc != 2){
//        printf("Usage: find pattern\n");
//    }else{
//        while (getline(line, MAXLINE) > 0){
//            if(strstr(line, argv[1]) != NULL){
//                printf("%s", line);
//                found++;
//            }
//        }
//    }
//    return found;
//}