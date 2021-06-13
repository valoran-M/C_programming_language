/**
 * Exercice 4.13:
 * 
 *  Write a recursive version of the function reverse(s),
 * which reverses the string s int place. 
 * 
 **/

#include <stdio.h>

void revers(char s[], int size);

int main()
{
    char al[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", al);
    revers(al, 26);
    printf("%s\n", al);

    return 0;
}

void revers(char s[], int size)
{
    void reversr(int pos, char s[], int max);
    reversr(0, s, size - 1);
}

void reversr(int pos, char s[], int max)
{
    if(pos > max / 2)
        return;

    char temp = s[pos];
    s[pos] = s[max - pos];
    s[max - pos] = temp;
    reversr(pos + 1, s, max);
}