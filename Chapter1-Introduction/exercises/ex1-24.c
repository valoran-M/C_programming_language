/**
 * Exercice 1.24
 * 
 *  Write a program to check a C program for rudimentary syntax
 * errors like unbalances parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This 
 * porgram is hard if you do it in full generality); 
 * 
 **/

#include <stdio.h>

#define MAXCHAR 1000

int get_str(char str[], int limit);
void check_syntax(char str[]);

void main()
{
    char str[MAXCHAR];

    get_str(str, MAXCHAR);
    check_syntax(str);
}

int get_str(char str[], int limit)
{
    int c, i = 0;
    while (i < limit - 1 && (c = getchar()) != EOF)
        str[i++] = c;

    str[i] = '\0';
    return i;
}

void check_syntax(char str[])
{
    int parentheses, brackets, braces;
    int single_quotes, double_quotes;

    int line_comment, block_comment;

    parentheses = brackets = braces = 0;
    single_quotes = double_quotes = 0;
    line_comment = block_comment = 0;

    int i;
    for (i = 0; str[i] != EOF; i++)
    {
        if (!single_quotes &&
            !double_quotes &&
            !line_comment &&
            !block_comment)
        {
            if (str[i] == '(')
                parentheses++;
            else if (str[i] == ')')
                parentheses--;
            else if (str[i] == '[')
                brackets++;
            else if (str[i] == ']')
                brackets--;
            else if (str[i] == '{')
                braces++;
            else if (str[i] == '}')
                braces--;
        }

        if (!line_comment && !block_comment)
        {
            if (str[i] == '\'' && !single_quotes && !double_quotes)
                single_quotes = 1;
            else if (single_quotes &&
                         str[i] == '\'' &&
                         str[i - 1] != '\\' ||
                     str[i - 2] == '\\')
                single_quotes = 0;

            if (str[i] == '"' && !single_quotes && !single_quotes)
                double_quotes = 1;
            else if (double_quotes &&
                         str[i] == '\"' &&
                         (str[i - 1] != '\\' ||
                     str[i - 2] == '\\'))
                double_quotes = 0;
        }

        if (!single_quotes && !double_quotes)
        {
            if (str[i] == '*' && str[i - 1] == '/' && !line_comment)
                block_comment = 1;
            else if (str[i] == '/' && str[i - 1] == '*')
                block_comment = 0;

            if (str[i] == '/' && str[i + 1] == '/' && !block_comment)
                line_comment = 1;
            else if (str[i] == '\n')
                line_comment = 0;
        }
    }
    if (parentheses)
        printf("Error: unbalanced parentheses.\n");

    if (brackets)
        printf("Error: unbalanced brackets.\n");

    if (braces)
        printf("Error: unbalanced braces.\n");

    if (single_quotes)
        printf("Error: unbalanced single quotes.\n");

    if (double_quotes)
        printf("Error: unbalanced double quotes.\n");

    if (block_comment)
        printf("Error: block comment not closed.\n");
}