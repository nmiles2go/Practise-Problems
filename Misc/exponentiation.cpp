#include <iostream>

int integerPowerRecursion           (int, unsigned int);
int integerPowerForLoopIteration    (int, unsigned int);

int main()
{
    std::cout << integerPowerRecursion(2,4) << std::endl;
    std::cout << integerPowerForLoopIteration(2,4) << std::endl;

    return 0;
}

int integerPowerForLoopIteration(int base, unsigned int exponent)
{
    int product{1};

    for (;exponent > 0; --exponent)
    {
        product = base * product;
    }

    return product;
}

int integerPowerRecursion(int base, unsigned int exponent)
{
    int product{1};
    
    // base case
    if(exponent <= 0)
    {
        return product;
    }

    else
    {
        return base * integerPowerRecursion(base, --exponent);
    }

}


