#include <unistd.h>
#include <stdio.h>

/* getchar unbuffered single character input */
int getchar(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

int main(int argc, char const *argv[])
{
    putchar(getchar());
    return 0;
}
