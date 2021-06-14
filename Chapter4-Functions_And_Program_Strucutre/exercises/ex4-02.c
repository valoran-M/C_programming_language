/**
 * Exercice 4.2
 * 
 *  Extend atof to handle scientific notation of the from
 *      123.45e-6
 *  where a floating-point number may be followed by e or E 
 * and optionally signed exponent
 * 
 **/

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int main()
{
    double sum, atof(char s[]);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", atof(line));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        while (exp)
        {
            if (exp_sign == -1)
                power *= 10;
            else
                power /= 10;
            --exp;
        }
    }
    return sign * val / power;
}