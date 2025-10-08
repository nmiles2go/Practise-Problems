#include <iostream>

int main()
{
    for (int side1{1}; side1 <= 500; ++side1)
    {
        for (int side2{1}; side2 <=500; ++side2)
        {
            for (int hypo{1}; hypo < 500; ++hypo)
            {
                if(hypo * hypo == side1 * side1 + side2 * side2)
                {
                    std::cout << side1 << "," << side2 << "," << hypo << "\n";
                }
            }
        }
    }
    return 0;
}