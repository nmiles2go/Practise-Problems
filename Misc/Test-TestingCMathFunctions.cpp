#include <iostream>
#include <cmath>

float RangeOfInputs()
{
    for (float i = -10.0; i <= 10.0; i += 0.5) 
    {
        return i;
    }

    return 0;
}

int main() 
{
    std::cout << "Functions from cmath\n";
    for (float i = -10.0; i <= 10.0; i += 0.5) 
    {
        std::cout << "Smallest integer not less than the number for    " << i << ": " << ceil(i) << '\n';
        std::cout << "Cosine for                                       " << i << ": " << cos(i) << '\n';
        std::cout << "Exponential for                                  " << i << ": " << exp(i) << '\n';
        std::cout << "Absolute Value for                               " << i << ": " << fabs(i) << '\n';
        std::cout << "Greatest integer not greater than the number for " << i << ": " << floor(i) << '\n';
        std::cout << "Logarithm natural for                            " << i << ": " << log(i) << '\n';
        std::cout << "Logarithm base 10 for                            " << i << ": " << log10(i) << '\n';
        std::cout << "Sine for                                         " << i << ": " << sin(i) << '\n';
        std::cout << "Square root for                                  " << i << ": " << sqrt(i) << '\n';
        std::cout << "Tangent for                                      " << i << ": " << tan(i) << '\n';

        std::cout << "\n\n----------------------------------\n";
    }

    for (float i = -2.0; i <= 2.0; i += 0.1) 
    {
        for (float j = -2.0; j <= 2.0; j += 0.1) 
        {
            std::cout << "Power for                                        " << i << "^" << j << ": " << pow(i, j) << '\n';
            std::cout << "Remainder for x/y as float for                   " << i << "/" << j << ": " << fmod(i,j) << '\n';
            std::cout << "\n\n----------------------------------\n";
        }
        
    }
}