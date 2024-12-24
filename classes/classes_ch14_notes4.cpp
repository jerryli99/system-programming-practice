/*
(credit https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/)

Chapter 14.4 -- const class objects and const member functions

I find this chapter interesting.

All const variables must be initialized at time of creation.

const int x; //compile error: not initialized
const int y{}; //ok, value initialized.
const int z{5}; //list initialized. 

*/

// struct Date
// {
//     int year {};
//     int month {};
//     int day {};
// };


// int main()
// {
//     const Date today {2020, 10, 14}; //const class type object
//     return (0);
// }


/*

Modifying the data members of const objects is disallowed

So once a const class type object has been initialized, any attempt to modify the
data members of the object is disallowed, as it would violate the const-ness of
the object. This includes both changing member variables directly (if public) or
calling member functions that set the value of member variables.

*/

// struct Date 
// {
//     int year{};
//     int month{};
//     int day{};

//     void incrementDay()
//     {
//         ++day;
//     }
// };

// int main()
// {
//     const Date today {2020, 10, 14};
//     today.day += 1; //compiler error: cannot modify member of const object
//     today.incrementDay(); //compiler error: cannot call member function that modifies member of const object

//     return (0);
// }

