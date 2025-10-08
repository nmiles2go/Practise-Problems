#include <iostream>

bool isEven(int);

int main()
{
    int number  {0}; // statement which declared and defined  
    int count   {0}; // 
    std::cout << "Enter the numbers: \n";

    do
    {
        std::cin >> number;
        std::cout << "Even?" << std::fixed << std::boolalpha << isEven(number) << "\n";
        ++count;
    }
    while(count < 10);

    return 0;
}

bool isEven (int number)
{
    if (number % 2 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}