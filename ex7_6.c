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
    int lineNo = 1;
    while(1) {
        p1 = fgets(line1, MAXLINE, f1);
        p2 = fgets(line2, MAXLINE, f2);
        if (p1 != NULL && p2 != NULL) {
           int cmp = strcmp(p1, p2);
            if (cmp != 0) {
                printf("%s and %s are not same\n", file1Name, file2Name);
                printf("%s line(%d): %s\n", file1Name, lineNo, p1);
                printf("%s line(%d): %s\n", file2Name, lineNo, p2);
                break;
            }
        } else if (p1 != NULL && p2 == NULL) {
            printf("%s and %s are not same\n", file1Name, file2Name);
            printf("%s line(%d): %s\n", file1Name, lineNo, p1);
            printf("%s line(%d) is emtpy\n", file2Name, lineNo);
            break;
        } else if (p1 == NULL && p2 != NULL) {
            printf("%s and %s are not same\n", file1Name, file2Name);
            printf("%s line(%d) is emtpy\n", file1Name, lineNo);
            printf("%s line(%d): %s\n", file2Name, lineNo, p2);
            break;
        } else {
            printf("%s and %s are same\n", file1Name, file2Name);
            break;
        }
        lineNo++;
    }
    //exit will close all files
    exit(0);
}
