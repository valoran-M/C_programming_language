#include <stdio.h>
#include <time.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

void main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        printf("%d\n", rand());
}

/* rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
    next = seed;
}