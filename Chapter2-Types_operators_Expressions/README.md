# Chapter 2:
# Types, Operators and Expressions

### Data Types and Sizes:

```c
    char    // a single byte, capable of holding one
            // character in the local character set.
    
    int     // an integer, typically refecting the natural sier
            // of integers on the host machine.
    float   // single-precision floating point.
    double  // double-precision floating point.


    short   // 16 bits
    long    // 32 bits

    long int;
    short int;


    signed
    unsigned    // >= 0
```
exercice :

[size type](exercises/ex2-01.c)

### Constants

```c    
    1234            //int constant
    123456789L      //long constant
    123456789UL     //unsigned long constant
    123.4 || 1e-2   //double
    123.4L          //long double
    123.4F          //float

    31 == 037       //octal
    31 == 0x1F      //hex
    0xFUL           //unsigned long  15

    #define VTAB '\013'
    #define BELL '\007'

    #define VTAB '\xb'
    #define BELL '\x7'
```

|   |   |
|---|---|
|\a|alert|
|\b|backspace|
|\f|formfeed|
|\n|newline|
|\r|carriage return|
|\t|horizontal tab|
|\v|vertiacl tab|
|\0|character 0|
|\\\\|backslash|
|\\?|question mark|
|\\'|single quote|
|\\"|double quote|
|\\ooo|octal number|
|\xhh|hexadecimal number|

```c
    strlen("1234") == 4;

    int strlen(char s[]) // define in <string.h>
    {
        int i;

        while(s[i] != '0')
            i++;
        return i;
    }
```

```c
    enum boolean { NO, YES };
    NO == 0;
    YES == 1;

    enum escpaes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
                    NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

    enum months { JAN = 1, FAB, MAR, APR, MAY, JUN,
                  JUL, AUG, SEP, OCT, NOV, DEC };
```

### Delcarations

```c
    int lower, upper, step;
    char c, line[1000];

    char esc = '\\';
    int i = 0;
    int limit = MAXLINE + 1;
    float eps = 1.0e-5;

    const double e = 2.71828182845905;
    const char msg[] = "warning: ";

    int strlen(const char[]);
```

### Arithmetic Operators

    +, -, *, / and the modulus operator %.

### Relational and Logical Operators

    > >= < <=

    == !=

    ! invers 0 or 1.

return 0 or 1.

exercice :

[logical](exercises/ex2-02.c)

### TYPES CONVERSIONS

You can check 
1. [convert char* to int](01-convert_s_to_integer.c) 
1. [lower convertion](02-lower.c)

You can use cast opertor
        
    sqrt((double) n);

exercice :

[ex2.3 : hexa in sqrt](exercises/ex2-03.c)

### Increment and Decrement Operators

We have ++ and -- operator for Increment and Decrement.


We will see examples for the ++ valid for the --

prefix : 
```c
    n = 5;
    x = n++; // x = 5

    n = 5;
    x = ++n; //x = 6

    if(s[i] != c)
    {
        s[j] = s[i];
        j++;
    }
    // equivalent
    if(s[i] != c)
        s[j++] = s[i];
```

[squeeze](04-squeeze.c)
[strcat](05-strcat.c)

Exercices :

[ex2.3 : squeeze](exercises/ex2-04.c)
[ex2.3 : any](exercises/ex2-05.c)

### Bitwise Operator

applied to : char, short, int and long, signed or unsigned

    &   :   bitwise AND
    |   :   bitwise inclusive OR
    ^   :   bitwise exclusive OR
    <<  :   left shift
    >>  :   right shift
    ~   :   one's complement (unary)

&& and ||

    1 & 2 = 0
    1 && 2 = 1

    1 | 2 = 2
    1 || 2 = 1

[getbits](06-getbits.c)


Exercices :

[ex2.6 : setbits](exercises/ex2-06.c)
[ex2.7 : invert](exercises/ex2-07.c)
[ex2.8 : reightrot](exercises/ex2-08.c)


### Assignment Operators and Expressions

```c
    i = i + 2;
    i += 2:         // same
```

    exp1 op= exp2
    exp1 = exp1 op exp2

op :
    + - * / % << >> & ^ |

[bitcount](07-bitcount.c)

Exercice :

[ex2.9 : reightrot](exercises/ex2-09.c)

### Conditional Expressions

```c
    if(a > z)
        z = a;
    else
        z = b

    // ?: -> (expr1) ? expr2 : expr3

    z = (a > z) ? a : b;
```

### Precedence and Operator of Evaluation

|Operators|Associativity|
|---|---|
|() [] -> .| left to right|
|! ~ ++ -- + - * & (type) sizeof| right to left|
|* / %|left to right|
|<< >>|left to right|
|< <= > >=|left to right|
|== !=|left to right|
|&|left to right|
|^|left to right|
|\||left to right|
|&&|left to right|
|\|\||left to right|
|?:|right to left|
|= += -= *= /= %= &= ^= |= <<= >>=|right to left|
|,|left to right|

## all the exercises:

[Exercises](./exercises/README.md)