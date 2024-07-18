Chapter13 String practice problems from the book C Programming: A Modern Approach 2nd edition by K.N.King. (b1) means book1


After learning some pointers and pointer_and_arrays, I need to improve some coding styles.

1. No magic numbers like variable1 * 60 + 60 etc, either use a macro or constant

2. All variables would be good to not be named like i, j, p, etc... name the variables at least 4 letters long.

3. Write const int *something_ptr or int const *something_ptr etc in function parameters if something is not expected to change

4. Put descriptive comments in necessary places. (could use Doxygen as reference)

5. Try to write some basic tests (no need to do that for every single problem since that will be too much)

6. Do not write "if (*flush)", write something like "if (*flush == true)", etc. Make it clear whether it is true or false condition.

7. Try not to write something like money -= dollar / FIFTY_DOLLAR_BILL. We could write money = money - (dollar / FIFTY_DOLLAR_BILL).

8. For functions, create and assign tmp variables with parameter values instead of using the variables directly from the parameters.