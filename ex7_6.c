//
// Created by cuixin on 2019/12/26.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a.exe ex7_6_test.txt ex7_6_test2.txt
//对于Clion里面的运行需要填写完整路径
#define MAXLINE 1000

int main(int argc, char *argv[]) {
    char *programName = argv[0];
    if (argc < 3) {
        fprintf(stderr, "%s need two arguments", programName);
        exit(1);
    }

    FILE *f1;
    FILE *f2;
    char *file1Name = *++argv;
    char *file2Name = *++argv;

    if ((f1 = fopen(file1Name, "r")) == NULL) {
        fprintf(stderr, "%s cannot open %s\n", programName, file1Name);
        exit(2);
    }
    if ((f2 = fopen(file2Name, "r")) == NULL) {
        fprintf(stderr, "%s cannot open %s\n", programName, file2Name);
        exit(3);
    }
    char line1[MAXLINE];
    char line2[MAXLINE];
    char *p1;
    char *p2;
    while(1) {
        p1 = fgets(line1, MAXLINE, f1);
        p2 = fgets(line2, MAXLINE, f2);
        if (p1 != NULL && p2 != NULL) {
           int cmp = strcmp(p1, p2);
            if (cmp != 0) {
                printf("the two file isn't same\n");
                printf("%s line: %s\n", file1Name, p1);
                printf("%s line: %s\n", file2Name, p2);
                break;
            }
        } else if (p1 != NULL && p2 == NULL) {
            printf("the two file isn't same\n");
            printf("%s line: %s\n", file1Name, p1);
            printf("%s line has reach end\n", file2Name);
            break;
        } else if (p1 == NULL && p2 != NULL) {
            printf("the two file isn't same\n");
            printf("%s line has reach end\n", file1Name);
            printf("%s line: %s\n", file2Name, p2);
            break;
        } else {
            printf("the two file is same\n");
            break;
        }
    }
    //exit will close all files
    exit(0);
}
