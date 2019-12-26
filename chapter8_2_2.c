//
// Created by cuixin on 2019/12/26.
//
#include <sys/syscall.h>
#include <stdio.h>
int getchar(void){
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

int getchar_v2(void){
    //利用static来保存数据。
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    if(n == 0){
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n > 0) ? (unsigned char) *bufp++: EOF;
}

int main(){
    int c;
    while((c=getchar()) !=EOF){
        printf("%c",c);
    }
}