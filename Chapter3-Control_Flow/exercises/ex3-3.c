/**
 * Exercice 3.3
 * 
 *  Write a function expand(s1, s2) that expands shorthand 
 * notations like a-z in the string s1 int the equivalent 
 * complete list abc...xyz in s2. Allow for letters of either
 * case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading 
 * or trailing - is taken literally
 * 
 **/

#include <stdio.h>

int get_str(char str[], int limit);
void expand(char s1[], char s2[]);

int main()
{
    char str[100];
    char s2[1000];
    get_str(str, 100);
    expand(str, s2);
    printf("%s\n", s2);
    return 0;
}

int get_str(char str[], int limit)
{
    int c, i = 0;

    while (i < limit - 1 && (c = getchar()) != EOF)
        str[i++] = c;
    str[i] = '\0';

    return i;
}

void expand(char s1[], char s2[])
{
    char c, cEnd;
    int i, j;
    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] > c) {
            if (s1[i - 1] = '-')
                c++;
            i++;
            if(s1[i + 1] == '-')
                cEnd = s1[i] - 1;
            else
                cEnd = s1[i];
            while (c <= cEnd)
                s2[j++] = c++;
        }
    }
    s2[j] = '\0';
}