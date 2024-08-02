#ifndef B1_STRUCTS_EX5_H
#define B1_STRUCTS_EX5_H

#include <stdbool.h>

#define EARLIER -1
#define SAME 0
#define LATER 1

typedef struct date_ {
    int month;
    int day;
    int year;
} Date;

enum month_ {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

extern const int MONTH_DAYS[12]; // Declaration of the external array

int day_of_year(const Date date);
int compare_dates(const Date date1, const Date date2);
bool is_leap_year(const int year);

#endif
