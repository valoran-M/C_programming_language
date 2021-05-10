# Chapter 3 exercises

## Exercice 3.1

    our binaray search makes two tests inside loop,
    when one would suffice (at the price of more tests outside).
    rite a version with only one test inside the loop and measure 
    the difference in run-time

## Exercice 3.2

    Write a function escape(s, t) that converts characters 
    like newline and tab into visible sequences like \n and \t 
    as it copies the string t to s. Use a switch. Write a function
    for the other direction as well, converting escape sequences
    into the real characters.

## Exercice 3.3

    Write a function expand(s1, s2) that expands shorthand 
    notations like a-z in the string s1 int the equivalent 
    complete list abc...xyz in s2. Allow for letters of either
    case and digits, and be prepared to handle cases
    like a-b-c and a-z 0-9 and -a-z. Arrange that a leading 
    or trailing - is taken literally

## Exercice 3.4

    In a two's complement number representation, our version of
    itoa does not handle the largest negative number, that is,
    the value of n equal to -(2^wordsize-1). Explain why not.
    Modify it to print the value correctly, regardless of the 
    machine on which it runs.

## Exercice 3.5

    Write the function itob(n, s, b) that convert the ineger n
    into a base b character representation in string s. In 
    particular, itob(n, s, 16) format n as hexadecimal 
    integer in s

## Exercie 3.6

    Write a version of itoa that accpets three arguments instead
    of two. The third argument is a minimum fiels width; the 
    converted number must be padded with blanks on the left
    if necessary to make it wide enough.