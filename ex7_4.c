//
// Created by cuixin on 2019/12/25.
//
#include <stdio.h>
#include <stdarg.h>
void minsscanf(char *format, ...) {
    va_list ap;//依次指向每个无名参数
    char *p, *cval;
    int *ival;
    double *dval;
    va_start(ap, format);// 将ap指向第一个无名参数
    for (p = format; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int*);
                scanf("%d", ival);
                break;
                //scanf cannot handle %f
//            case 'f':
//                dval = va_arg(ap, double *);
//                scanf("%f", dval);
//                break;
            case 'c':
                cval = va_arg(ap, char *);
                scanf("%c", cval);
                break;
            default:
                break;
        }
    }
    va_end(ap); //结束时的清理工作
}

int main(){
    int i;
//    float f;
    char c;
    minsscanf("%d  %c", &i, &c);
    printf("%d\n", i);
    printf("%c\n", c);
}