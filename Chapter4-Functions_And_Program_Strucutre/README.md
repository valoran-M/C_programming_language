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