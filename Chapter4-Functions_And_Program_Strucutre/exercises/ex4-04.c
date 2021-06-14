/**
 * Exercice 4.4:
 * 
 *  Add commands to print the top element of the stack without pop
 * ping, to duplicate it, and to sawp the top two elements.
 * Add a command to clear stack.
 * 
 **/

/*
    Compilation : 
        cc ex4-4.c ../7-stack.c ../8-getop.c ../9-getch.c
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "../10-calc.h"

#define MAXOP 100 /* max size of operand or operator*/

/* function written in this exercise in another file

// clear: clear stack 
void clear(void)
{
    for (; sp > 0; sp--)
        ;
}

// last : return last item in stack
double last(void)
{
    if (sp > 0)
        return val[sp - 1];
    else
        printf("error: stack empty\n");
    return 0.0;
}

// swap : the last two elements of the stack
void swap(void)
{
    double op = val[sp - 1];
    if (sp > 1)
    {
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = op;
    }
    else
        printf("error: stack is not big enough\n");
}

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