//
// Created by cuixin on 2019/12/27.
//
#include <sys/syscall.h>
#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>
int get(int fd, long pos, char *buf, int n){
    if(lseek(fd, pos, 0) >=0){
        return read(fd, buf, n);
    }else{
        return -1;
    }
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("./a.out fileName");
        exit(1);
    }
    int fd = open(argv[1], O_RDONLY, 0);
    if(fd == -1){
        fprintf(stderr, "can't open file %s", argv[1]);
        exit(2);
    }
    char buf[BUFSIZ];
    if(get(fd, 0, buf, BUFSIZ) >0){
        printf("%s\n", buf);
    }
    exit(0);
}