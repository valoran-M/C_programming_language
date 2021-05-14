#include <stdio.h>
#define MAXLINE 1000

/*
    Compilation : 
        cc 1-grep.c 2-getline.c 3-strindex.c
*/

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* fund all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    return found;
}