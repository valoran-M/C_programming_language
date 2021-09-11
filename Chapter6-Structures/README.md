# Chapter 6:
# Structures

### Basics of Structures

```c
struct point {
    int x;
    int y;
};

struct point pt;
struct point maxpt = {320, 200};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct rec screen;

screen.pt1.x;
```

### Structures and Functions

[point](01-point.c)

### Arrays of Structures

