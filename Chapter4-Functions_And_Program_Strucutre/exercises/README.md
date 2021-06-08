# Chapter 4 exercises

## Exercice 4.1

    Write the function strrindex(s,t), which returns the position
    of the rightmost occurrence of t in s, or -1 if there is none

## Exercice 4.2

    Extend atof to handle scientific notation of the from
        123.45e-6
    where a floating-point number may be followed by e or E 
    and optionally signed exponentù

## Exercice 4.3

    Given the basic framework, it's straightforward to extend
    the calculator. Add the modulus (%) operator and provision
    for negative numbers 

## Exercice 4.4 

    Add commands to print the top element of the stack without pop
    ping, to duplicate it, and to sawp the top two elements.
    Add a command to clear stack.

## Exercice 4.5

    Add access to library functions like sin, exp, and pow.
    See <math.h> in Appendix B, Section 4

## Exercice 4.6:

    Add commands for handling variables. 
    (It's easy to provide twenty-six varaibles 
    with single-letter names.) Add a varaible
    for the most recently printed value.

## Exercice 4.7:

    Write a routine unget(s) that will push back an 
    entire string onto the input. Should ungets know 
    about buf and bufp, or should it just use getch 
    ungetch ?

## Exercice 4.8:

    Suppose that ther will never bo more than one character 
    of pushback. Modify getch and ungetch accordingly. 