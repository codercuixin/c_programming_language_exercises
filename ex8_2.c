//
// Created by cuixin on 2019/12/27.
//
/*
   Rewrite fopen and _fillbuf with fields instead of explicit bit operations.
   To avoid confusion, my implementation of standard definitions have a suffix "x"


   Field based approach is time consuming as we would have to check if each field
   is set or not while finding a free slot. Using Bit manipulation, we just have to
   compare the particular flag bit to zero.

   Bit fields can be used in struct _flags structure to reduce the total size of a File type.
 */
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define EOF (-1)
#define OPEN_MAX 20 //maximum files that can be open
#define PERMS 0666
//Filed based approach for flags;
typedef struct _flags{
    int _READ;
    int _WRITE;
    int _UNBUF;
    int _EOF;
    int _ERR;
} flags;
//File Data Structure
typedef struct _iobufx{
    int cnt;
    char *ptr;
    char *base;
    struct _flags flags;
    int fd;
}FILEX;

FILEX _iobx[OPEN_MAX];

int _fillbuffx(FILEX * f);

#define getcx(p)(--(p)->cnt >=0 ? (unsigned char) *(p)->ptr++: _fillbuffx(p))

//Check if Slot is empty by checking if all fields are
//empty in the flags structure
int is_empty(struct _flags flags){
    if(!flags._READ && !flags._WRITE && !flags._UNBUF && !flags._EOF && !flags._ERR){
        return 1;
    }
    return 0;
}

FILEX *fopnex(char *name, char *mode){
    int fd;
    FILEX *fp;
    if(*mode != 'r' && *mode !='w' && *mode != 'a'){
        return NULL;
    }
    //check for  free slots
    for(fp = _iobx; fp < _iobx + OPEN_MAX; fp++){
        if(is_empty(fp -> flags)){
            break;
        }
    }

    //if FUll return null
    if(fp >= _iobx + OPEN_MAX){
        return NULL;
    }

    //Create file on Write Mode
    if(*mode== 'w'){
        fd =creat(name, PERMS);
    }else if(*mode == 'a'){
        if((fd = open(name, O_RDONLY, 0)) == -1){
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }else{
        fd = open(name, O_RDONLY, 0);
    }

    if(fd == -1) {
        return NULL;
    }

    fp->fd = fd;
    fp->cnt = 0;
    if(*mode == 'r'){
        fp->flags._READ = 1;
    }else{
        fp->flags._WRITE = 1;
    }
    return fp;
}

int _fillbuffx(FILEX *fp){
    int bufsize;
    if(fp->flags._READ == 0){
        return EOF;
    }
    bufsize = (fp->flags._UNBUF != 0) ? 1 :BUFSIZ;
    if(fp->base == NULL){
        if((fp->base = (char *)malloc(bufsize)) == NULL){
            return EOF;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0){
        if(fp->cnt == -1){
            fp->flags._EOF = 1;
        }else{
            fp->flags._EOF = 1;
        }
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int main(void){
    FILEX *fp = fopnex("ex8_2.c", "r");
    if(fp != NULL){
        char c;
        while((c = getcx(fp)) != EOF){
            putchar(c);
        }
    }else{
        puts("Error");
    }
    return 0;
}