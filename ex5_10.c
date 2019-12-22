//
// Created by cuixin on 2019/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100

int getop(char *);

void push(double);

double pop(void);

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        exit(1);
        //return 0.0;
    }
}

int getop(char *s) {
    if(isdigit(s[0])){
        return NUMBER;
    }else{
        return s[0];
    }

}

int main(int argc, char *argv[]) {
    int type;
    double op2;
    while (--argc> 0 && (type = getop(*++argv)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(*argv));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: division by zero\n");
                break;
            case 's': //sin
                push(sin(pop()));
                break;
            case 'c': //cos
                push(cos(pop()));
                break;
            case 'p'://pow
                op2 = pop();
                double op1 = pop();
                if ((op1 == 0 && op2 <= 0) || (op1 < 0)) {
                    printf("error: pow args wrong");
                } else {
                    push(pow(op1, op2));
                }
                break;
            default:
                printf("error: unknown command ");
                break;
        }
    }
    printf("\tresult:%.8g\n", pop());
    return 0;
}