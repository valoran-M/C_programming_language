# Chapter 4:
# Functions And Program Structure

### Basic of Function

```
    return-type function-name(argument declaration)
    {
        declaration and statements
        return expression;
    } 
```

[grep](01-grep.c)
[getline](02-getline.c)
[strindex](03-strindex.c)

Exercice:

[ex4-1](exercises/ex4-01.c)

### Functions Returning Non-integers

```c
    void main()
    {
        double sum, atof(char s[]); // atof :   function return double
                                    //          and take char * in 
                                    //          parameter 
    }
```

[atof](04-atof.c)
[rudimentary calculator](05-rud_calc.c)

```c
    /* atoi: convert string s to integer using atof*/
    int atoi(char s[])
    {
        double atof(char s[]);

        return (int) atof(s);
    }
```

[ex4-2](exercises/ex4-02.c)

### External Variables

>"extranl" is used in contrast to "internal"

#### Exemple (Polish Notation) :

(1 - 2) * (4 + 5) <=> 1 2 - 4 5 + *

```c
    while (next operator or operand is not end-of-file indicator)
        push it
    else if (operator)
        pop operands
        do opzeation
        push result
    else if (newline)
        pop and print top of stack
    else
        error
```

- code translation

```c
    #include
    #define

    // function declrations for main

    main() { ... }

    // extranal variables for push and pop

    void push(double f) { ... }
    double pop(void) { ... }

    int gettop(char s[]) { ... }

    // routines called by getop()
```

[polish calc](06-polish_calc.c)
[stack](07-stack.c)
[getop](08-getop.c)
[getch](09-getch.c)

Exercices:

[ex4-3](exercises/ex4-03.c)
[ex4-4](exercises/ex4-04.c)
[ex4-5](exercises/ex4-05.c)
[ex4-6](exercises/ex4-06.c)
[ex4-7](exercises/ex4-07.c)
[ex4-8](exercises/ex4-08.c)
[ex4-9](exercises/ex4-09.c)
[ex4-10](exercises/ex4-10.c)

### Scope Rules

```c
    main() { ... }

    int sp = 0;
    double val[MAXVAL];

    void push(double f) { ... }

    double pop(void) { ... }
```

sp and val are not accessible in the hand and in other files

##### extern

```c
// file 1

    // defined
    extern int sp;
    extern double val[];

    void push(double f) { ... }

    double pop(void) { ... }

// file 2

    // initialized
    int sp = 0;
    double val[MAXVAL];
```

### Header Files


You can write your declarations in a ".h" header file and you can include it with #include "path"

[header](10-calc.h)

### Static Variables

```c
static
```

The static keyword reduces the visibility of the element.

* For global static variables they are only accessible in the file.

* For local static variables it acts like global variables accessible only in the block

Exercice:

[ex4-11](exercises/ex4-11.c)

### Register Variables

```c
register
```

Indicates to the compiler to reserve a processor register for the management of this variable.

*very little advised*

### Block Structure

```c
{
    // in the block
}
// outside the block
```

example with variables

```c
if( n > 0 )
{
    int i;  /* declare a new i */

    for ( i = 0; i < n; i++)
        ...
}
```

the variable i is accessible in the block and in the for loop because it is declared before

```c
int x;
int y;

f(double x)
{
    double y;
    ...
}
```

in f the variables x and y are the variables declared with double. Outside we find the int declare above.

### Initialization

Scalar variables may be initialized when they are defined, by foloowing the name withe an equals sign and an expression.

```c
    int x = 1;
    char squote = '\'';
    long day = 1000L * 60L* 60L * 24L;
```

For example, the initializations of the binary search program could be written as

```c
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    ...
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    ...
}
```

##### Array

```c
int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


char pattern[] = "ould"
// equivalent
char pattern[] = { 'o', 'u', 'l', 'd', '\0' };
```

### Recursion

C functions may be used recursively; thaht is, a function may call itself either directly or indirectly.

Example:

[printd](11-printd.c)
[qsort](12-qsort.c)

Exercices:

[ex4-12](exercises/ex4-12.c)
[ex4-13](exercises/ex4-13.c)

### The C preprocessor

#### File inclusion

```c
#include "filename"

// or

#include <filename>
```

Is remplece by the contents of the file *filname*.

* If the *filname* is quoted searching for the file typically
begins where the source program was found

* If bale is enclosed in < and >, searching fllolw and implementation-defined rule to find the file.

#### Macro Substitution

```c
#define name replacement text

#define forever for (;;) /* infinite loop */

#define max(A, B) ((A) > (B) ? (A) : (B))

x = max(p+q, r+s)

// replaced by the line

x = ((p+q) > (r+s) ? (p+q) : (r+s))
```

Names may be undifined with `#undef`, usually to ensure that a routine is really a function, not a macro.

```c
    #undef getchar()

    int getchar(void) { ... }
```

when we put # in front of the parameter is put in quotes

```c
    #define printd(expr) printf(#expr " = %g\n", expr)

    // when this is invoked, as in

    printd(x/y);

    // the macro is expanded into

    printf("x/y" " = %g\n", expr);

    // and the strings are concatenated, so the effect is

    printf("x/y = %g\n", expr);
```

In the definition of a macro, the ## operator concatenates two arguments

```c
    #define paste(front, back) front ## back

    paste(L, 23) // => "L23"
```

#### Conditional Inclusion

condition at the front of the headers to avoid multiple inclusion

```c
#if !define(HDR)
// or
#ifndef HDR

#define HDR

/* contents of hdr.h go here */

#endif
```

We can also chain the conditions

```c
#if SYSTEM = SYSV
    #define HDR "sysv.h"
#elif SYSTEM = BSD
    #define HDR "bsd.h"
#elif SYSTEM = MSDOS
    #define HDR "msdo.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```