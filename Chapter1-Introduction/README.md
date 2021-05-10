# Chapter 1 : 
# INTRODUCTION 


### Getting Started

```c
main()
{
    /* program */
}
```

1. [exercice 1](./exercises/ex1-1.c)
1. [exercice 2](./exercises/ex1-2.c)

### Variables and Arithmetic Expressions

```c
    (Type) varaible_name;
    vairalbe_name = value;
    
    char    /* Character - a single byte */
    short   /* Short integer */
    long    /* long integer */
    double  /* double - precision floating point */

    while(/* condition */)
    {
        /* instruction */
    }
```

1. [exercice 3](./exercises/ex1-3.c)
1. [exercice 4](./exercises/ex1-4.c)

### The For Statement

```c
    for( variable; condition; increment)
    {
        /* instruction */
    }
```

1. [exercice 5](./exercises/ex1-5.c)

### Symbolic Constants

```c
#define name value
```

### Character Input and Output

```c
    #include <stdio.h>

    c = getchar();
    putchar(c);
```

###### File Copying

1. [exercice 6](./exercises/ex1-6.c)
1. [exercice 7](./exercises/ex1-7.c)

###### Line counting

1. [exercice 8](./exercises/ex1-8.c)
1. [exercice 9](./exercises/ex1-9.c)
1. [exercice 10](./exercises/ex1-10.c)

###### Wrod counting

1. [exercice 11](./exercises/ex1-11.c)
1. [exercice 12](./exercises/ex1-12.c)

### Arrays

```c
    int ndigits[10];

    if (condition_1)
        statement_1
    else if (condition_2)
        statement_2
    ...
    else
        statement_n
```

1. [exercice 13](./exercises/ex1-13.c)
1. [exercice 14](./exercises/ex1-14.c)

### Functions

```c
    return_type function_name(parameter declarations, if any)
    {
        declarations
        statements
    
        return expression;
    }
```

1. [exercice 15](./exercises/ex1-15.c)

### Arguments-Call by value

```c
int power(int base, int n)
{
    /*
    base and n are copies
    */
}
```

### Chracter Arrays

```c
    char line[MAXCHAR];
```

1. [exercice 17](./exercises/ex1-17.c)
1. [exercice 18](./exercises/ex1-18.c)
1. [exercice 19](./exercises/ex1-19.c)


### External Variables and Scope

```c
    int var;

    main()
    {
        extern int var;
        /* Same as the one above and modiable */
    }

    int pow()
    {
        extern int var;
        /* Same variable and modifiable */

    }

```

1. [exercice 20](./exercises/ex1-20.c)
1. [exercice 21](./exercises/ex1-21.c)
1. [exercice 22](./exercises/ex1-22.c)
1. [exercice 23](./exercises/ex1-23.c)
1. [exercice 24](./exercises/ex1-24.c)


## all the exercises:

[Exercises](./exercises/README.md)
