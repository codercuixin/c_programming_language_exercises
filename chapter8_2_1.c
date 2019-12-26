//
// Created by cuixin on 2019/12/26.
// Unix下调用

#include <sys/syscall.h>
main(){
    char buf[BUFSIZ];
    int n;
    while((n = read(0, buf, BUFSIZ)) > 0){
        write(1, buf, n);
    }
    return 0;
}