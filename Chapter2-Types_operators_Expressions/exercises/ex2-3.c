/**
 * Exercice 2.3:
 * 
 *  Write the fonction htoi(s), which converts a string of hexadcimal
 * digits (including an optional 0x or 0X) int equivalent ineger value.
 * The allowable digits are 0 through 9, a through f, and A through F.
 * 
 **/
#include <stdio.h>

#define MAXCHAR 100

int htoi(char s[]);
int my_getline(char s[], int lim);

void main()
{
    char s[MAXCHAR];
    int i;

    my_getline(s, MAXCHAR);
    i = htoi(s);
    printf("%d\n", i);
}

int htoi(char s[])
{
    if (s[0] == '0' && (s[1] == 'X' || s[1] == 'X'))
    {
        
    }
    else
    {
        printf("Error : begin with 0x / 0X");
        return 0;
    }
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}