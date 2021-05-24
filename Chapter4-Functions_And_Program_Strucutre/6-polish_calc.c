#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "10-calc.h"

#define MAXOP 100 /* max size of operand or operator*/

/*
    Compilation : 
        cc 6-polish_calc.c 7-stack.c 8-getop.c 9-getch.c
*/

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
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
                push((long)pop() % (long)op2);
            else
                printf("error: zero divisor\n");
            break;

        case 'c':
            clear();
            printf("clear\n");
            break;

        case 's':
            swap();
            printf("swap\n");
            break;

        case '?':
            printf("\t%.8g\n", last());
            break;

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}