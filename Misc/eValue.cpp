#include <iostream>

int main()
{
    int number_of_terms{0};
    float e{1.0f};
    
    std::cin >> number_of_terms;

    if(number_of_terms == 1)
    {
        e = 1.0f;
    }

    else if (number_of_terms > 1)
    {
        int i {1};
        int factorial{2};
        while(i < number_of_terms)
        {
            
            e += 1/(factorial * i);
            i++;
        }
    }

    else
    {
        ;
    }

    std::cout << e;
    return 0;
}