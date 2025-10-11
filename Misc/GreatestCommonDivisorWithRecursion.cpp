#include <iostream>

unsigned int GreatestCommonDivisor_Recusion(unsigned int a, unsigned int b, unsigned int depth = 0)
{

    unsigned int result{0};

    if(a >= b)
    {
        
        if (b == 0)
        {
            for (unsigned int i = 0; i < depth; i++)
            {
                std::cout << "  ";

            }
            
            result = a;

        }
        
        else
        {
            for (unsigned int i = 0; i < depth; i++)
                std::cout << "  ";

            std::cout << "GCD(" << b << ", " << a%b << ")" << std::endl;
            result = GreatestCommonDivisor_Recusion(b, a % b, depth + 1);
        }

    }

    else
    {
        std::cout << "ERROR: a should be greater than b" << std::endl;
        return 0; // Error: a should be greater than b
    }

    for (unsigned int i = 0; i < depth; i++)
    {
        std::cout << "  ";

    }
    std::cout << "End of recursive call GCD(" << a << ", " << b << ")" << std::endl;
    return result;
}

int main()
{
    std::cout << GreatestCommonDivisor_Recusion(10,3) << std::endl;
    return 0;
}

