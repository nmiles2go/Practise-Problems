#include <iostream>
#include <iomanip>

int main()
{
    double sum1{0.0};
    double sum2{0.0};
    double pi  {0.0};

    for(int i{1}; i <= 400'000; i++)
    {
        if(i%2 != 0)
        {
            sum1 = sum1 + 1.0/((i * 2) - 1);
        }
        
        if (i%2 == 0) 
        {
            sum2 = sum2 + 1.0/((i * 2) - 1);       
        }
        
        pi = 4 * (sum1 - sum2);

        if(pi > 3.14159 && pi < 3.141595)
        {
            std::cout << i << std::endl;
            std::cout<< std::scientific << std::setprecision(9) << pi;
                        break;

        }
    }
    
    std::cout << "\n" << "\t\t" << std::scientific << std::setprecision(9) << pi;
    return 0;
}