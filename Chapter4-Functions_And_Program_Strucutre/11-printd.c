#include <stdio.h>

void printd(int n);

int main()
{
    printd(10);
    putchar('\n');
    printd(30);
    putchar('\n');
    printd(28);
    putchar('\n');
}

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}