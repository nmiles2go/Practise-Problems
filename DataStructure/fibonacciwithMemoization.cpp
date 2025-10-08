#include <iostream>

long long F[61]; // Recursion with memoization

long long Fibonacci(int number)
{
    if (number <= 1)
    {
        return number;
    }

    if (F[number] != -1 )
    {
        return F[number];
    }

    else
    {
        F[number] = Fibonacci(number-2) + Fibonacci(number-1); 
        return F[number];
       
    }
}
int main()
{

    for(int i{0}; i < 61; ++i )
    {
        F[i] = -1;
    }

    int number{1};

    std::cin >> number;

    std::cout << Fibonacci(number);
    return 0;
}