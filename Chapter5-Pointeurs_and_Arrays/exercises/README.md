# Chapter 5 exercises

## Exercice 5.1

    As written, getint treats a + or - not followed
    by a digit as a valid representation zero. 
    Fix it to push such a character back on the input. 

## Exercie 5.2

    Write getfloat, the floating-point analog
    of getint. What type does getfloat return as its
    function value?

## Exercice 5.3:

    Write a pointer version of the function strcat that 
    we showed in Chapter 2: strcat(s, t) copies the string t
    to the end of s.

## Exercice 5.4:

     Write the function strend(s, t), which returns 1
    if the string t occurs at the end of the string s,
    and zero otherwise.

## Exercice 5.5:

    Write a versions of the library function `strncpy`,
    `strncat`, and `strncmp`, which operate on at most
    the first n characters of thier argument strings.
    For example, strncpy(s,t,n) copies at most n 
    characters of t to s.

## Exercice 5.7:

    Rewrite readlines to store lines in an array 
    supplied by main, rather than calling alloc to 
    maintain storage. How much faster is the 
    progtam?