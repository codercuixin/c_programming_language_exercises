//
// Created by cuixin on 2019/12/26.
//

//
// Created by cuixin on 2019/12/26.
//https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
//srand() — Set Seed for rand() Function.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(0));
    for(int i=0; i<5;i++){
        printf(" %d ", rand());
    }
    return 0;
}
//on my pc
//  880  26600  30718  7215  19311
//  906  14283  9791  3113  3524
//  929  23986  3769  7717  10190