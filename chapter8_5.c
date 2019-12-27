//
// Created by cuixin on 2019/12/27.
//
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024


#include <fcntl.h>
#include <sys/syscall.h>
#define PERMS 0666
FILE *fopen(char *name, char *mode){
    int fd;
    FILE *fp;
    if(*mode != 'w' && *mode != 'r' && *mode != 'a'){
        return NULL:
    }
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
        if((fp->flag & (_READ | _WRITE)) == 0){
            break;//寻找一个空闲位
        }
    }
    if(fp >= _iob +OPEN_MAX){
        return NULL;
    }
    if(*mode == 'w'){
        fd = creat(name, PERMS);
    }else if(*mode == 'a'){
        if((fd = open(name, O_WRONLY, 0)) == -1){
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }else{
        fd = open(name, O_RDONLY, 0);
    }

    if(fd == -1){
        return NULL:
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ: _WRITE;
    return fp;
}