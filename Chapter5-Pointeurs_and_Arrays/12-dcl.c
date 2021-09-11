
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOK 100

enum
{
    NAME,
    PARENS,
    BRACKETS
};

void dcl(void);
void dirdcl(void);
int gettoken(void);
void err(char *err);

int tokentype, retrytoken = 0;
char token[MAXTOK],
    name[MAXTOK],
    datatype[MAXTOK],
    out[1000];

int main(void)
{
    while (gettoken() != EOF)
    {
        /* First token is datatype */
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            err("Syntax error");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void)
{
    int c;
    char *p = token;

    if (retrytoken)
    {
        retrytoken = 0;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}

void dcl(void)
{
    int star = 0;
    while (gettoken() == '*')
        star++;

    dirdcl();
    while (star-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;

    if (tokentype == '(') /* ( dcl ) */
    {
        dcl();
        if (tokentype != ')')
            err("Error: missing ')'");
    }
    else if (tokentype == NAME)
        strcpy(name, token);
    else
        err("Error: expected name or (dcl)");

    while ((type = gettoken()) == PARENS ||
           type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

void err(char *err)
{
    printf("%s\n", err);
    retrytoken = 1;
}