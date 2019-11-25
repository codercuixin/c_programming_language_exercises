//
// Created by cuixin on 2019/11/25.
//
#include "stdio.h"
int binsearch(int , int [], int );
int main(){
    int x = 4;
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ret= binsearch(4, v, 8);
    printf("%d", ret);
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (v[mid] == x) {
        return mid;
    }
    return -1;
}