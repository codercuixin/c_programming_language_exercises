//
// Created by cuixin on 2019/11/18.
//

#include <stdio.h>

int main() {
    int c;
    int countPerLowerAlpha[26];
    int countPerHigherAlpha[26];
    for (int i = 0; i < 26; i++) {
        countPerLowerAlpha[i] = 0;
        countPerHigherAlpha[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            countPerLowerAlpha[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            countPerHigherAlpha[c - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (countPerLowerAlpha[i] > 0) {
            printf("%c count: %d\n", ('a' + i), countPerLowerAlpha[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (countPerHigherAlpha[i] > 0) {
            printf("%c count: %d\n", ('A' + i), countPerHigherAlpha[i]);
        }
    }


}