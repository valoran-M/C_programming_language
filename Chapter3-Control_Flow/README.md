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

[binsearch](01-binsearch.c)

Exercice :

[ex3-1](exercises/ex3-01.c)

### Switch


    switch (expression)
        case const-expr: statements
        case const-expr: statements
        default: statements

[switch count](02-switch_count.c)

Exercice :

[ex3-2](exercises/ex3-02.c)

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

[atoi](03-atoi.c)
[shellsort](04-shellsort.c)
[reverse](05-reverse.c)

Exercice :

[ex3-3](exercises/ex3-03.c)

### Loops - Do while

```c

    do
        statement
    while (expression);
```

[itoa](06-itoa.c)

### Break and Continue

    break

exit from for, while, and do while

[tim](07-trim.c)

    continue

go to the next iteration of for, while, do

```c
    for (i + 0; i < n; i++)
        if (a[i] < 0) /* skipe negative elements */
            continue;
        /* do positive elements */
```

### Goto and Labels

```c
    for (...)
        for (...)
            if (disaster)
                goto error;

error:
    clean up the mess
```

real example :

```c
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (a[i] == b[j])
                goto found;
    /* didn't find any common element */
found
    /* got one: a[i] == b[j]*/
```

## all the exercises:

[Exercises](./exercises/README.md)