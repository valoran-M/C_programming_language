/**
 * Exercice 4.5:
 * 
 *  Add access to library functions like sin, exp, and pow.
 * See <math.h> in Appendix B, Section 4
 * 
 **/

/*
    Compilation : 
        cc ex4-5.c ../7-stack.c ../8-getop.c ../9-getch.c -lm
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include "../10-calc.h"

#define MAXOP 100 /* max size of operand or operator*/

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
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}