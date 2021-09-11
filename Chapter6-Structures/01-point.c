#include <stdio.h>

#define XMAX 1920
#define YMAX 1080

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point
{
    int x;
    int y;
};

struct point pt;
struct point maxpt = {320, 200};

struct rect
{
    struct point pt1;
    struct point pt2;
};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two point*/
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 uf not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x &&
           p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalise coordinate of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}

int main(int argc, char const *argv[])
{
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    struct point origine, *pp;
    origine = makepoint(10, 10);

    pp = &origine;
    printf("origine is (%d, %d)\n", (*pp).x, (*pp).y);
    printf("origine is (%d, %d)\n", pp->x, pp->y);

    struct rect r, *rp = &r;

    /*
    r.pt1.x
    rp->pt1.x
    (r.pt1).x
    (rp->pt1).x
    */

    struct
    {
        int len;
        char *str;
    } * p;

    ++p->len;
    ++(p->len);

    return 0;
}
