#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

/* day_of_year: set day of year from mounth & day */
int day_of_year(int year, int mounth, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
    for (i = 1; i < mounth; i++)
        day += daytab[leap][i];
    return day;
}

/* mounth_day: set mounth, day from day of year */
void mounth_day(int year, int yearday, int *pmounth, int *pdays)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
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
    return 0;
}