/**
 * Exercice 3.2
 * 
 *  Write a function escape(s, t) that converts characters 
 * like newline and tab into visible sequences like \n and \t 
 * as it copies the string t to s. Use a switch. Write a function
 * for the other direction as well, converting escape sequences
 * into the real characters.
 * 
 **/

#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
    char t[] = "fljsqdlfq\tlkjhqlsdkjfq\nflkqjshfq\n\nn";
    char s[1000];
    escape(s, t);
    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;

    for (j = i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\t':
            s[j] = '\\';
            s[++j] = 't';
            break;
        case '\n':
            s[j] = '\\';
            s[++j] = 'n';
            break;
        default:
            s[j] = t[i];
            break;
        }
        j++;
    }
}