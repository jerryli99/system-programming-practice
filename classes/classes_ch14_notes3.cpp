/*
Chapter 14.3 Member functions

The separation of properties and actions:
Everywhere you look are objects, like books, food, table, human, etc. Real-life
objects have 2 major components to them: 

1. Some number of observable properties (weight, color, size, solidity, shape)
2. Some number of actions that they can perform or have performed on them 
(being opened, damaging something else, etc.) based on those properties.

These properties and actions are inseparable. In programming, we represent 
properties with variables, and actions with functions.

In addition to having member variables, class types (which includes structs, 
classes, and unions) can also have their own functions. Functions that belong
to a class type are called member functions.

*/

#include <iostream>

struct Date
{
    int m_year {};
    int m_month {};
    int m_day {};

    void print() // defines a member function named print
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.m_day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    return 0;
}