#include <stdio.h>

void suqeeze(char s[], char c);

void main()
{
    char s[] = "abcdecdefcdmlf";
    suqeeze(s, 'c');
    printf("%s\n", s);
}

/* squeez: delete all c from s */
void suqeeze(char s[], char c)
{
    int i, j;

    for( i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}