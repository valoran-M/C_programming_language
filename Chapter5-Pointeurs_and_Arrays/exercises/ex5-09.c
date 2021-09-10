/**
 * Exercise 5.9:
 * 
 *  Rewrite the routines day_of_year and mounth_day
 * with pointers instead of indexing
 * 
 **/

#include <stdio.h>

static char year_month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year_month_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[2] = {year_month_days, leap_year_month_days};

/* day_of_year: set day of year from mounth & day */
int day_of_year(int year, int mounth, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    if (mounth > 12 || mounth < 1)
        printf("%d invalide argument", mounth);
    else if (day > daytab[leap][mounth] || day < 1)
        printf("%d invalide argument", day);
    else
    {
        for (i = 1; i < mounth; i++)
            day += daytab[leap][i];
        return day;
    }
    return -1;
}

/* mounth_day: set mounth, day from day of year */
void mounth_day(int year, int yearday, int *pmounth, int *pdays)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    if ((yearday > 366 && leap) || (yearday > 365 && !leap) || yearday < 1)
    {
        printf("%d invalide argument\n", yearday);
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmounth = i;
    *pdays = yearday;
}

int main()
{
    int day, mounth;
    int days_count = day_of_year(2002, 10, 15);
    mounth_day(2002, days_count, &mounth, &day);
    printf("%d, %d\n", day, mounth);
    mounth_day(2000, 366, &day, &mounth);
    mounth_day(2001, 366, &day, &mounth);
    mounth_day(2001, 0, &day, &mounth);

    return 0;
}