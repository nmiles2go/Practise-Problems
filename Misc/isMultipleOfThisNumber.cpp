#include <iostream>
#include <iomanip>

bool isMultiple(int, int);

int main()
{
    std::cout << std::boolalpha << isMultiple(2,4) << std::endl;
    std::cout << std::boolalpha << isMultiple(2,5) << std::endl;

    std::cout << std::boolalpha << isMultiple(-2,4) << std::endl;
    std::cout << std::boolalpha << isMultiple(2,-5) << std::endl;

    std::cout << std::boolalpha << isMultiple(-2,-4) << std::endl;
    std::cout << std::boolalpha << isMultiple(2,-5) << std::endl;
    return 0;
}

bool isMultiple(int number1, int number2)
{
    if(0 == number2 % number1)
    {
        //std::cout << "Number2 is a multiple of Number1 \n";
        return true;
    }
      
    else
    {
        return false;
    }
}