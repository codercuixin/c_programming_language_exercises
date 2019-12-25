//
// Created by cuixin on 2019/11/18.
// https://www.quora.com/What-is-EOF-in-C#
// EOF means end of file. It's a sign that the end of a file is reached, and that there will be no data anymore.
// On Linux systems and OS X,the character to input to cause an EOF is CTRL+D. For Windows, it's CTRL+Z.
// Depending on the operating system, this character will only work if it's the first character on a line,
// i.e. the first character after an ENTER. Since console input is often line-oriented,
// the system may also not recognize the EOF character until after you've followed it up with an ENTER And yes,
// if that character is recognized as an EOF, then your program will never see the actual character. Instead, a C program will get a -1 from getchar().
#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("fahr changed to celsius\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr, celsius);
        fahr = fahr + step;
    }
}

