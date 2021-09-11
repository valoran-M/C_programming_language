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

## Exercice 5.8:

    There is no error checking in day_of_year
    or mounth_day.
    Remedy this defect

## Exercise 5.9:

    Rewrite the routines day_of_year and mounth_day
    with pointers instead of indexing

##    Exercice 5.10:

     Write a programs entab and detab (written as exercises on
    Chapter 1) to accept a list of tab stops as arguments.
    Use the default tab set tings if ther are no argument. 
    For example,

         expr 2 3 4 + *

    evaluates 2 * ( 3 + 4)

## Exercice 5.11

     Modify the programs entab and detab (written
    as exercices in Chapter 1) to accept a list of tab stops as arguments.
    Use the default tab settings is there are no arguments.

## Exercice 5.12

     Extend entab and detab to accept the shorthand 
    
         entab -m +n

    to mean tab stops every n columns, starting at column m.
    Choose convenient (for the user) default behavior

## Exercice 5.13

     Write the program tail wich prints the last n lines of
    its input. By default, n is 10, let us say, but it can 
    be changed by an optional argument, so that

         tails -n

    printd the last n lines. The program shoul behave 
    rationally no matter how unreasonable the input 
    of the value of n. Write the program so it makes the best
    use of avaible storage line should be sotred as in 
    the sorting program of Section 5.6, not
    int two-dimensional array of fixed size.  

## Exercice 5.14

     Modify the sort program to handel
    a -r flag, wich indicates sorting in
    reverse (decreasing order). Be sur that -r
    works with -n

## Exercice 5.15

     Add the option -f to fold upper and lower case
    together, so that case distinctions are not
    made during sorting; for exemple, a and A compare
    equal.