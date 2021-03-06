# Chapter 5:
# Pointers and Arrays

### Pointers and Addresses

If c is a char and p is a pointer:

<h1 align="center">
    <img src="./diagram/pointeurPC.png">
</h1>

The unary operator & gives the adress of an object

```c
    p = &c

    int x = 1, y = 2, z[10];
    int *ip;        /* ip is a pointer to int */

    ip = &x;        /* ip now points to x */
    y = *ip;        /* y is now 1 */
    *ip = 0         /* x is now 0 */
    ip = &z[10];    /* ip now points to z[0] */

    // Function

    atof(char *);

    // Operator

    *ip = *ip + 10;

    y = *ip + 1;

    *ip += 1;

    ++*ip;
    (*ip)++;

    iq = ip;
```

### Pointers and Function Arguments

```c
void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py
    *py = temp;
}
```

Example:

[getint](01-getint.c)

Exercices:

[ex 5.1](exercises/ex5-01.c)
[ex 5.2](exercises/ex5-02.c)

### Pointers and Arrays

<h1 align="center">
    <img src="./diagram/array_c.png">
</h1>

pa[i] ⬄ *(pa + i)

Example:

[strlen](02-strlen.c)

### Adress Arithmetic

<h1 align="center">
    <img src="./diagram/alloc.png">
</h1>

Exemple:

[alloc](03-alloc.c)
[strlen](04-strlen.c)

### Character Pointers and Function

A string constant, written as :

    "I am a string"

```c
    char amessage[] = "new is a time";  /* an array */
    char *pmessage = "now is the time"; /* a pointer */
```

<h1 align="center">
    <img src="./diagram/pmessage.png">
</h1>

Example:

[strcpy](05-strcpy.c)
[strcmp](06-strcmp.c)

Exercice:

[ex5.3](exercises/ex5-03.c)
[ex5.4](exercises/ex5-04.c)
[ex5.5](exercises/ex5-05.c)
[ex5.6](exercises/ex5-06.c)

### Pointer Arrays; Pointer to Pointers

* Process:

        Read all the lines of input
        sort them
        print them in order

[row sorter](07-pointer_pointer.c)

Exercice:

[ex5.7](exercises/ex5-07.c)

### Multi-dimensional Arrays

[date converter](08-date_converter.c)

Exercice:

[ex5.8](exercises/ex5-08.c)

### Initialization of Pointer Arrays

```c
/* mounth_name: return name of n-th mounth */
char *mounth_name(int n)
{
    static char *name[] = {
        "Illegal mounth",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    retrun (n < 1 || n > 12) ? name[0] : name[n];
}
```

### Pointer vs Multi-dimensional Arrays

```c
int a[10][20];
int *b[10];
```

a[*row*][*col*] : 20 * *row* + *col*

Exercice:

[ex5.9](exercises/ex5-09.c)


### Command-line Arguments

```c
main(argc, *argv[])
```

[echo](09-echo.c)
[find](10-find.c)

Exercice:

[ex5.10](exercises/ex5-10.c)
[ex5.11](exercises/ex5-11.c)
[ex5.12](exercises/ex5-12.c)
[ex5.13](exercises/ex5-13.c)

### pointer to functions

[qsort](11-sort.c)

Exercice:

[ex5.14](exercises/ex5-14.c)
[ex5.15](exercises/ex5-15.c)
[ex5.16](exercises/ex5-16.c)
[ex5.17](exercises/ex5-17.c)


### Complicated Declarations

```c
char **argv
```
argv: pointer ro pointer to char

```c
int (*daytab)[3]
```
daytab: pointer to array[13] of int

```c
int *daytab[3]
```
daytab: array[13] of pointer to int

```c
void *comp()
```
comp: function returning to void

```c
void (*comp)()
```
comp: pointer to function returning void

```c
char (*(*x())[])[]
```
x: function retruning pointer to array[] of
pointer to function returning char

```c
char (*(*x[3])())[5]
```
x: array[3] of pointer to function returning
pointer to array[5] of char

Exercice:

[ex5.14](exercises/ex5-18.c)
[ex5.15](exercises/ex5-19.c)
[ex5.16](exercises/ex5-20.c)