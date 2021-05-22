# Chapter 4:
# Focntion And Program Structure

### Basic of Function

```
    return-type function-name(argument declaration)
    {
        declaration and statements
        return expression;
    } 
```

[grep](1-grep.c)
[getline](2-getline.c)
[strindex](3-strindex.c)

Exercice:

[ex4-1](exercises/ex4-1.c)

### Functions Returning Non-integers

```c
    void main()
    {
        double sum, atof(char s[]); // atof :   function return double
                                    //          and take char * in 
                                    //          parameter 
    }
```

[atof](4-atof.c)
[rudimentary calculator](5-rud_calc.c)

```c
    /* atoi: convert string s to integer using atof*/
    int atoi(char s[])
    {
        double atof(char s[]);

        return (int) atof(s);
    }
```

[ex4-2](exercises/ex4-1.c)

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