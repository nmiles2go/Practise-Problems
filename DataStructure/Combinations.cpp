#include <iostream>

int factorial(int n)
{
    if(n < 2) return 1;
    else return n * factorial(n-1);
}

int CombinationsRecursion(int n, int r)
{
    int t1, t2, t3;

    t1 = factorial(n);
    t2 = factorial(n-r);
    t3 = factorial(r);

    return t1/(t2 * t3);
}

int CombinationsRecursionUsingPascalTriangle(int n, int r)
{
    if(0 == n || r == n) return 1;

    else
    {
        return CombinationsRecursion(n-1, r- 1) + CombinationsRecursion(n-1,r);
    }
}

int main()
{
    std::cout << CombinationsRecursion(5,3) << std::endl;
    std::cout << CombinationsRecursionUsingPascalTriangle(5,3) << std::endl;

    return 0;
}