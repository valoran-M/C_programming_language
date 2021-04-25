#include <stdio.h>

void main()
{
    int c, nl, nt, nb;

    nl = 0;
    nt = 0;
    nb = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            nl++;
        else if(c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
    }
    printf("\nnl = %d nb = %d nt = %d\n", nl, nb, nt);
}
