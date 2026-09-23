#include "fibonacci.hpp"

int fibonacci_recursive(const int value) 
{ 
    if (value == 1) return 1;
    if (value == 2) return 1;

    return fibonacci_recursive(value - 1) + fibonacci_recursive(value - 2);
}

int fibonacci_iterative(const int value) 
{ 
    int n1 = 0;
    int n2 = 1;
    for (int i = 1; i < value; i++)
    {
        int temp = n1 + n2;

        n1 = n2;
        n2 = temp;
    }

    return n2;
}