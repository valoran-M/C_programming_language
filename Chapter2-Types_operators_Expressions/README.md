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
|\\\\|backslash|
|\\?|question mark|
|\\'|single quote|
|\\"|double quote|
|\\ooo|octal number|
|\xhh|hexadecimal number|
