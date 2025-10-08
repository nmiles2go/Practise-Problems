#include <iostream>
#include <cmath>

void isPerfect(int);

int main()
{
    for (size_t i = 1; i <= 1'000'000; i++)
    {
        
        isPerfect(i);
        /* code */
    }
    
    return 0;
}

void isPerfect(int number)
{
    int sum{0};
    int temp{number};

    for(int i{1}; i <= temp - 1; ++i)
    {
        if(temp % i == 0)
        {
            
            sum += i;
        }
    }

    if(sum == number)
    {
        std::cout  << number << " is a perfect number :))\n";
    }

   
}