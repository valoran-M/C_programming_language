#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "10-calc.h"

#define MAXOP 100 /* max size of operand or operator*/

/*
    Compilation : 
        cc 6-polish_calc.c 7-stack.c 8-getop.c 9-getch.c -lm
*/

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    int line_i;
    char s[MAXOP], line[MAXOP];

    while (getLine(line, MAXOP) != 0)
    {
        line_i = 0;
        while ((type = getop(s, line, &line_i)) != '\0')
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

            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;

            case '~':
                push(sin(pop()));
                break;

            case 'e':
                push(exp(pop()));
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
                printf("\t%.8g\n", last());
                break;

            case VARSET: /* lower is for set */
                var_set(s[0] - 'A', pop());
                printf("\nvariable %c: %.3f\n", s[0], var_get(s[0] - 'A'));
                break;

            case VARGET: /* upper is for get */
                push(var_get(s[0] - 'A'));
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}