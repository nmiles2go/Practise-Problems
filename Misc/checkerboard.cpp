#include <iostream>

int main()
{
    int size{0};
    std::cout << "\n\nEnter the size of the checkerboard you want to create: ";
    std::cin >> size;
    std::cout << "\n\n";

    int outerloopCounter{0};
    while(outerloopCounter < size)
    {
        
        if(outerloopCounter % 2 != 0)
        {
            std::cout << ' ';
        }
        
        else
        {
            ;
        }
        
        int innerloopCounter{0};
        while(innerloopCounter < size)
        {   
            std::cout << "* ";
            innerloopCounter++;
        }

        std::cout << std::endl;
        outerloopCounter++;
    }

    std::cout << "\n";
    return 0;
}