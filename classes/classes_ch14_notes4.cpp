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


/*

Even though print() does not try to modify a member vriable, our call to today.print()
is still a const violation. This happens because the print() member function itself
not declared as const. The compiler won't let us call a non-const member function
on a const object.

Const member functions
To address the above issue, we need to make print() a const member function.
A const member function is a member function that guarantees it will not modify
the object or call any non-const member functions (as they may modify the object).

Making print() a const member functio is easy -- we simply append the const keyword
to the function prototype, after the parameter list, but before the function body.

*/

// #include <iostream>

// struct Date
// {
//     int year {};
//     int month {};
//     int day {};

//     void print() const 
//     {
//         std::cout << year << '/' << month << '/' << day;
//     }
// };

// int main()
// {
//     const Date today {2020, 10, 14};
//     today.print();

//     return 0;
// }


/*
OK, so we have a const class type, so we need a const member function. 
What if we need to modify values in the member function?
*/

// struct Date
// {
//     int year {};
//     int month {};
//     int day {};

//     void incrementDay() const 
//     {
//         ++day; // already error here after typing out the code, compiler error
//     }
// }

/*
Because const member functions can be called on both const and non-const object,
if a member function does not modify the state of the object, it should be made const.

Best practice:
A member function that does not modify the state of the object should be made const,
so that it can be called on both const and non-const objects.

Be careful about what member functions you apply const to. Once a member function
is made const, that function can be called on const objects. Later removal of const
on a member function will break any code that calls that member function on a const
object. 



*/



