#include <iostream>

int main()
{
    int number{0};
    while(number <= 0)
    {   
        std::cout << "\nEnter a positive number: ";
        std::cin >> number;
    }

    int product{1};
    while(number > 0)
    {
        product *= number;
        number--;
    }

    std::cout << product;
    return 0;
}