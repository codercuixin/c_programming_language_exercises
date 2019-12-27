//
// Created by cuixin on 2019/12/27.
//todo 跑起来

#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void fsize(char *);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fsize(".");//默认为当前目录
    } else {
        while (--argc > 0) {
            fsize(*++argv);
        }
    }
    return 0;
}

int stat(char *, struct stat *);

void dirwalk(char *, void (*fcn)(char *));

/*fsize 函数：打印文件name的长度*/
void fsize(char *name) {
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }
    printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

/*dirwalk 函数：对dir中的所有文件调用函数fcn*/
void dirwalk(cahr *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    Dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0) {
            continue;//跳过自身和父目录
        }
        if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->name);
        } else {
            sprintf(name, "%s %s", dir, dp->name);
            (*fcn)(name);
        }
    }
    close(dfd);
}

int fstat(int fd, struct stat *);

DIR *opendir(char *dirname) {
    int fd;
    struct stat stbuf;
    DIR *dp;
    if ((fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (dp = (DIR *) malloc(sizeof(DIR))) == NULL) {
        return NULL;
    }
    dp->fd = fd;
    return dp;
}

void closedir(DIR *dp) {
    if (dp) {
        close(dp->fd);
        free(dp);
    }
}

#include <sys/dir.h>
Dirent *readdir(DIR *dp) {
    struct direct dirbuf;
    static Dirent d;
    while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
        if (dirbuf.d_ino == 0) {
            continue;
        }
        d.ino = dirbuf.d_ino;
        strncpy(d.name, dirbuf, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0';
        return &d;
    }
    return NULL;
}