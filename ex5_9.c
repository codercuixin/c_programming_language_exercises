//
// Created by cuixin on 2019-12-22.
//

//
// Created by cuixin on 2019-12-22.
//
#include <stdio.h>
// compound literal https://www.geeksforgeeks.org/compound-literals-c/
// https://gcc.gnu.org/onlinedocs/gcc/Compound-Literals.html
static char *daytab[2] = {(char[]) {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          (char[]) {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

//返回是该年的第多少天
int day_of_year(int year, int month, day) {
    int i, leap;
    if (year < 1) {
        printf("error: year cannot be %d", year);
        return -1;
    }
    if (month < 1 || month > 12) {
        printf("error: month cannot be %d", month);
        return -1;
    }
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if (day > *(daytab[leap] + month) || day < 1) {
        printf("error: year=%d month=%d cannot have %d", year, month, day);
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += *(daytab[leap] + i);
    }
    return day;
}

//将某年第多少天转换成某月某日的表示形式
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    if (year < 1) {
        printf("error: year cannot be %d", year);
        return;
    }
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if (yearday > (365 + leap) || yearday < 0) {
        printf("error: year=%d cannot have yearday %d", year, yearday);
        return;
    }
    for (i = 1; yearday > *(daytab[leap] + i); i++) {
        yearday -= *(daytab[leap] + i);
    }
    *pmonth = i;
    *pday = yearday;
}

int main() {
    int res = day_of_year(2019, 12, 31);
    printf("%d\n", res);

    int i;
    int j;
    month_day(2019, 365, &i, &j);
    printf("%d, %d\n", i, j);
}