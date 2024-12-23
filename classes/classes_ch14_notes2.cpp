/**
 * Chapter 14.2
 * 
 */
// #include <iostream>

// struct Date
// {
//     int day{};
//     int month{};
//     int year{};
// };

// void printDate(const Date& date)
// {
//     std::cout << date.day << '/' << date.month << '/' << date.year; // assume DMY format
// }

// int main()
// {
//     Date date{ 4, 10, 21 }; // initialize using aggregate initialization
//     printDate(date);        // can pass entire struct to function

//     return 0;
// }

#include <iostream>

class Date       // we changed struct to class
{
public:          //an access specifier
    int m_day{};
    int m_month{};
    int m_year{};
};

//not a member function. 
void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    printDate(date);

    return 0;
}


/*

Given some set of values (ages, address numbers, etc…), 
we might want to know what the minimum and maximum values are in that set. 
Since the minimum and maximum values are related, we can organize them in a 
struct, like so:

struct minMax
{
    int min; // holds the minimum value seen so far
    int max; // holds the maximum value seen so far
};

However, as written, this struct has an unspecified class invariant. 
What is the invariant?

Answer to the question:
Well there is no guarantee in this code that can show that min is always storing
the value less than or equal to max. Thus, if min > max, we have a problem.

*/