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
#define BUFSIZE 100

int getop(char *);

void push(double);

double pop(void);

int getch(void);

void ungetch(int);

void printStackTop(void);

int bufp = 0;
char buf[BUFSIZE];
int sp = 0;
double val[MAXVAL];
double beforePrintVal = 0;

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

void printStackTop(void) {
    if (sp > 0) {
        printf("top of the stack is %g", val[sp - 1]);
    } else {
        printf("error: the stack is empty");
    }
}

/**
 * 复制栈顶元素
 * @return
 */
double peek(void) {
    if (sp > 0) {
        return val[sp - 1];
    } else {
        printf("error: the stack is empty, can't copy");
    }
}

void swapStackTopTwo(void) {
    if (sp >= 2) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("error: the stack don't have 2 elements");
    }
}

void clear(void) {
    sp = 0;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
/**
 * 4-8
 * @return
 */
int getch_v1(void) {
    return (bufp == 1) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void ungetch_v1(int c) {
    if (bufp >= 1)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char *s) {
    int i, c, d;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-') {
        d = getch();
        if (d == ' ')
            return c;
        else
            ungetch(d);
    }
    i = 0;
    if (isdigit(c) || c == '-')
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
//可以用ungetch，但如果超过大小会进行不必要地尝试。
void ungets(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (bufp >= BUFSIZE) {
            printf("ungets: too many characters\n");
            return;
        } else {
            buf[bufp++] = s[i]
        }
        i++;
    }
}

int main() {
    int type;
    double op2;
    char s[MAXOP];
    double cur;
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
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
            case '\n':
                cur = pop();
                printf("\t before: %.8g current:%.8g\n", beforePrintVal, cur);
                beforePrintVal = cur;
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
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}