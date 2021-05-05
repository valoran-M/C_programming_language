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

unsigned int htoi(char s[], int len);
int my_getline(char s[], int lim);

void main()
{
    char s[MAXCHAR];
    unsigned int i;
    int len;

    len = my_getline(s, MAXCHAR);
    i = htoi(s, len);
    printf("%d\n", i);
    printf("%x\n", i); // verification
}

unsigned int htoi(char s[], int len)
{
    unsigned int number = 0, pow = 1, place;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        for (place = len - 1; place > 1; place--)
        {
            if (s[place] >= '0' && s[place] <= '9')
                number += (s[place] - '0') * pow;
            else if (s[place] >= 'A' && s[place] <= 'F')
                number += (s[place] - 'A' + 10) * pow;
            else if (s[place] >= 'a' && s[place] <= 'f')
                number += (s[place] - 'a' + 10) * pow;
            else
                printf("Error : %c is incompatible chractere\n", s[place]);
            pow *= 16;
        }
    }
    else
    {
        printf("Error : begin with 0x / 0X\n");
        return 0;
    }
    return number;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    s[i] = '\0';
    return i;
}