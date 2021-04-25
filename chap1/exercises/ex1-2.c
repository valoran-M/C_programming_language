#include <stdio.h>

/*
Experiment to find out what happens when printf's 
argument strinf contains \c
*/
void main()
{
    printf("hello world\c");
    printf("hello world\z");
    printf("hello world\d");
}
