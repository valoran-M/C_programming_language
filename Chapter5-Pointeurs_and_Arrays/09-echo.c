#include <stdio.h>

/* acho command-line arguments; 2nd version */
int main(int argc, char const *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}
