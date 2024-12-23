/*
credit: https://www.learncpp.com/cpp-tutorial/introduction-to-object-oriented-programming/

Objects:
In C++, direct memory access is discuraged. Instead, we access memory indirectly
through an object. An object represents a region of storage (typically RAM or a
CPU regist) that can hold a value. Objects also have associated properties.


In procedural programming, the functions and the data those functions operate on
are separate entities. The programmar is responsible for combining the functions
and the data together to produce the desired result.

In object-oriented programming, the focus is on creating program defined data types
that contain both properties and a set of well defined behaviors. 

i.e. you.eat(apple);

This makes it clearer who the subject is (you), what behavior is being invoked (eat),
and what objects are accessories to that behavior (apple)

Because the properties and behaviors are no longer seperate, objects are easier
to modularize, which makes our progrms easier to write and understand, and also 
provides a higher degree of code resuability. These objects also provide a more 
intuitive way to work with our data by allowing us to define how we interact with
the objects, and how they interact with other objects.

*/

// #include <iostream>
// #include <string_view>

// enum AnimalType
// {
//     cat,
//     dog,
//     chicken,
// };

// constexpr std::string_view animalName(AnimalType type)
// {
//     switch (type)
//     {
//         case cat: return "cat";
//         case dog: return "dog";
//         case chicken: return "chicken";
//         default:  return "";
//     }
// }

// constexpr int numLegs(AnimalType type)
// {
//     switch (type)
//     {
//         case cat: return 4;
//         case dog: return 4;
//         case chicken: return 2;
//         default:  return 0;
//     }
// }


// int main()
// {
//     constexpr AnimalType animal{ cat }; //or just write constexpr AnimalType animal = cat;
//     std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

//     return (0);
// }


/*
While the program works fine, if we need to update this program, so that our
animal is a snake, we will need to modify AnimallType, numLegs(), animalName(). 

If we need to update this 10000 times, it will be a nightmare.
*/

#include <iostream>
#include <string_view>

struct Cat 
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};


struct Dog 
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};


struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    const Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return (0);
}


/*
OK, so structs can be useful, but have a number of deficiencies that can present
challenges when trying to build large complex programs. 


The class invariant problem
Perhaps the biggest difficulty with structs is that they do not provide an effective
way document and enforce class invariants (invariant means a condition thhat must
be true while some component is executing). 


In the context of class types (which include structs, classes, and unions), a class
invariant is a condition that must be true throughout the lifetime of an object
in order for the object to remain in a valid state. An object that has a violated
class invariant is said to be in an invalid state, and unexpected or undefined
behavior may result from further use of that object.


First, we have:
struct Pair
{
    int first {};
    int second {};
};

The first and second members cna be independently set to any value, so Pair struct
has no invariant. 

struct Fraction
{
    int numerator {0};
    int denominator {1}; //class invariant, should never be 0
};

Well, we know that division by 0 is not valid, so we need to ensure that the denomiator
is never set to 0. If it is, then that fraction object is in an invalid state, and 
undefined behabior may result from future use of that object. 

void printFractionValue(const Fraction& f)
{
     std::cout << f.numerator / f.denominator << '\n';
}

int main()
{
    Fraction f { 5, 0 };   // create a Fraction with a zero denominator
    printFractionValue(f); // cause divide by zero error

    return 0;
}

*/



