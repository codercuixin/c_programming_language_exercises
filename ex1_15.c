//
// Created by cuixin on 2019/11/18.
//

#include <stdio.h>
float celsisuToFahr(float celsius);
int main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 100;
    step = 10;

    celsius = lower;
    printf("celsius changed to fahr\n");
    while (celsius <= upper) {
        fahr = celsisuToFahr(celsius) ;
        printf("%3.0f %6.1f\n",celsius, fahr);
        celsius = celsius + step;
    }
}

float celsisuToFahr(float celsius){
    return  (9.0 / 5.0) * (celsius + 32.0);
}
