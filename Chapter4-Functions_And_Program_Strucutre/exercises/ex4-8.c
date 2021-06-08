/**
 * Exercice 4.8:
 * 
 *  Suppose that ther will never bo more than one character 
 * of pushback. Modify getch and ungetch accordingly. 
 * 
 **/

#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);

int buf;

int main(void)
{
    buf = -1;

    ungetch('A');
    ungetch('b');
    printf("%c\n", getch());
    printf("%c\n", getch());
    ungetch('c');
    return 0;
}

int getch(void)
{
    int c;
    if (buf == -1)
        c = getchar();
    else
        c = buf;
    buf = -1;
    return c;
}

void ungetch(int c)
{
    if (buf != -1)
        printf("ungetch: Too many character\n");
    else
        buf = c;
}