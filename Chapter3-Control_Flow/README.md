# Chapter 3:
# Control FLow

### Statements and Blocks

```c
    {
        /* block */
        printf("hello");
    }

    for (...)
        printf("") // compound statement
```

### If-Else

```c
    if (expression)
        statement1
    else
        statement2
```

### Else-If

```c
    if (expression)
        statement
    else if(expression)
        statement
    else if(expression)
        statement
    else
        statement
```

[binsearch](1-binsearch.c)

Exercice :

[ex3-1](exercises/ex3-1.c)

### Switch


    switch (expression)
        case const-expr: statements
        case const-expr: statements
        default: statements

[switch count](2-switch_count.c)

Exercice :

[ex3-2](exercises/ex3-2.c)

### Loops - While and For

```c
    while (expression)
        statement

    for (expr1; expr2; expr3)
        statement
    
    // equivalent to

    expr1;
    while (expr2)
    {
        statment
        expr3;
    }
```

[atoi](3-atoi.c)
[shellsort](4-shellsort.c)
[reverse](5-reverse.c)

Exercice :

[ex3-3](exercises/ex3-3.c)

### Loops - Do while

```c

    do
        statement
    while (expression);
```

[itoa](6-itoa.c)

### Break and Continue

    break

exit from for, while, and do while

[tim](7-trim.c)

    continue

go to the next iteration of for, while, do

```c
    for (i + 0; i < n; i++)
        if (a[i] < 0) /* skipe negative elements */
            continue;
        /* do positive elements */
```