# Chapter 2 exercises

## Exercice 2.1

    Write a program to determine the ranges of char, short, int 
    and long varaibles, both signed and unsigned, by printing appropriate
    values from standard headers and by direct computation.
    Harder if you compute them : determine the range of the various floating-
    point types.

## Exercice 2.2

    Write a loop equivalent to the  for loop above
    without using && or ||

## Exercice 2.3

    Write the fonction htoi(s), which converts a string of hexadcimal
    digits (including an optional 0x or 0X) int equivalent ineger value.
    The allowable digits are 0 through 9, a through f, and A through F.

## Exercice 2.4

    Write an alternate version of squeeze(s1, s2) that deletes in
    string s1 that matches any character in the string s2.

## Exercice 2.5

    Write the function any(s1, s2), wich returns the first loacation
    int the string s1 where any character from the string s2 occurs, or
    -1 is s1 contains no characteers from s2. (The standard library funtion)
    strpbrk does the same job but returns a pointer to location) 

## Exercice 2.6

    Write a function setbits(x, p, n, y) that return x with
    the n bits tha begin at position p set to the rightmost
    n bits of y, leaving the other bits unchanged.

## Exercice 2.7

    Wrtie a funtion invert(x, p, n) that return x with 
    the n that begin at position p set to the rightmost n
    bits of y, leaving the other bits unchanged.

## Exercice 2.8

    Write a function reightrot(x, n) that return the value of the
    integer x rotated to the right by n bit position

## Exercice 2.9

    In two's complement number systeme, x &= (x-1) delets
    the rigthmost 1-bit in x. Explain why. Use this observation 
    to write a faster version of bitcount()

## Exercice 2.10

    Rewrite the function lower, which converts
    upper case letters to lower case, with a conditional
    expression instead of if-else
