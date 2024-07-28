#include <stdio.h>
#include <assert.h>
#include "b1_structs_ex5.h"

void test_is_leap_year() {
    assert(is_leap_year(2020) == true);  // Leap year
    assert(is_leap_year(1900) == false); // Not a leap year (divisible by 100, not 400)
    assert(is_leap_year(2000) == true);  // Leap year (divisible by 400)
    assert(is_leap_year(2021) == false); // Not a leap year
}

void test_day_of_year() {
    Date date1 = {JANUARY, 1, 2024};
    assert(day_of_year(date1) == 1);

    Date date2 = {FEBRUARY, 28, 2023};
    assert(day_of_year(date2) == 59);

    Date date3 = {MARCH, 1, 2024}; // Leap year
    assert(day_of_year(date3) == 61);

    Date date4 = {DECEMBER, 31, 2024};
    assert(day_of_year(date4) == 366); // Leap year, last day of the year
}

void test_compare_dates() {
    Date date1 = {JANUARY, 1, 2024};
    Date date2 = {JANUARY, 1, 2024};
    assert(compare_dates(date1, date2) == SAME);

    Date date3 = {FEBRUARY, 29, 2024}; // Leap year
    assert(compare_dates(date1, date3) == EARLIER);

    Date date4 = {DECEMBER, 31, 2023};
    assert(compare_dates(date1, date4) == LATER);
}

int main() {
    test_is_leap_year();
    test_day_of_year();
    test_compare_dates();
    printf("All tests passed successfully.\n");

    return 0;
}