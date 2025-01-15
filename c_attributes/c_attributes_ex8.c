//warn_unused_result

#include <stdio.h>

int compute() __attribute__((warn_unused_result));

int compute()
{
    return 42;
}

int main()
{
    compute();//will trigger a warning about the unused result in compile time
    return 0;
}