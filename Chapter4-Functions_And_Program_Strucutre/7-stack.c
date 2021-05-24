#include <stdio.h>

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack*/

/* push: push f onto valu stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0.0;
}

/* clear: clear stack */
void clear(void)
{
    for (; sp > 0; sp--)
        ;
}

/* last : return last item in stack */
double last(void)
{
    if (sp > 0)
        return val[sp - 1];
    else
        printf("error: stack empty\n");
    return 0.0;
}

/* swap : the last two elements of the stack */
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