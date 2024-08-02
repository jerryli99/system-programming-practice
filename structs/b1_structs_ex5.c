#include "b1_structs_ex5.h"

// Definition of the external array
const int MONTH_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Computes the total days elapsed since January 1.
 * 
 * @param date a constant struct of typedef Date in b1_structs_ex5.h.
 * 
 * @return Returns the number of days of the year up to the user input date.
 */
int day_of_year(const Date date) {
    int month, total_days = date.day;

    for (month = 0; month < date.month - 1; month++) {
        total_days = total_days + MONTH_DAYS[month];

        if ((month == FEBRUARY - 1) && (is_leap_year(date.year) == true)) { // Adjust for 0-index
            total_days++;
        }
    }

    return total_days;
}

/**
 * @brief compares date1 and date2.
 * 
 * @param date1 a constant struct of typedef Date in b1_structs_ex5.h.
 * @param date2 a constant struct of typedef Date in b1_structs_ex5.h.
 * 
 * @return if date1 is less than date2, then return EARLIER; 
 *         if greater, return LATER; 
 *         else, return SAME. 
 * 
 */
int compare_dates(const Date date1, const Date date2) {
    int comparison = 0;

    /* Compare Years */
    if (date1.year < date2.year) {
        comparison = EARLIER;
    } else if (date1.year > date2.year) {
        comparison = LATER;
    } else { /*Years are the same so compare num days in year */
        int d1_days = day_of_year(date1);
        int d2_days = day_of_year(date2);

        if (d1_days < d2_days) {
            comparison = EARLIER;
        } else if (d1_days > d2_days) {
            comparison = LATER;
        } else {
            comparison = SAME;
        }
    }

    return comparison;
}

/**
 * @brief Checks if the given input year is a leap year or not.
 * 
 * @param year a constant integer.
 * 
 * @return Returns true if the given year is a leap year, else false.
 *  
 */
bool is_leap_year(const int year) {
    // Check if the year is divisible by 400
    if (year % 400 == 0) {
        return true;
    }

    // Check if the year is divisible by 100
    if (year % 100 == 0) {
        return false;
    }

    // Check if the year is divisible by 4
    if (year % 4 == 0) {
        return true;
    }

    // If none of the above conditions are met, it's not a leap year
    return false;
}