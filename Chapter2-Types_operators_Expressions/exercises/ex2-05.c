/**
 *  Exercie 2.5
 * 
 *  Write the function any(s1, s2), wich returns the first loacation
 * int the string s1 where any character from the string s2 occurs, or
 * -1 is s1 contains no characteers from s2. (The standard library funtion)
 * strpbrk does the same job but returns a pointer to location) 
 * 
 **/

#include <stdio.h>

int any(char s1[], char s2[]);

void main()
{
    char s1[] = "abcdefgh\n\n";
    printf("%d\n", any(s1, "abd"));
    printf("%d\n", any(s1, "efc"));
    printf("%d\n", any(s1, "z"));

}

int any(char s1[], char s2[])
{
    int i, y;

    for (i = 0; s1[i] != '\0'; i++)
        for(y = 0; s2[y] != '\0'; y++)
            if(s2[y] == s1[i])
                return i;
    return -1;
}