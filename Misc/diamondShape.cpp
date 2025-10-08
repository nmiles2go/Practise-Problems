#include <iostream>

const int MIN{1};
const int MAX{19};

int main()
{
    int size;
    std::cout << "\nEnter the odd number of lines for the diamond: ";
    std::cin >> size;

    while(size % 2 == 0 || size <= MIN || size >= MAX )
    {
        if(size % 2 == 0)
        {
            std::cout << "\nEnter an odd number! ";
        }

        if(size <= MIN || size >= MAX)
        {
            std::cout << "\nEnter a number within the range! ";
        }

        std::cin >> size;
    }

    size = (1 + size)/2;
    
    // number of elements in a row
    int numElements{2 * size - 1};

    for(int row{1}; row <= size ; ++row)
    {
        for(int column{1}; column <= numElements; ++column)
        {
            if(row <= size && (column > size - row && column < size + row))
            {
                std::cout << '*';
            }
            
            else
            {
                std::cout << ' ' ;
            }
        }

        std::cout << '\n';
    }
    
    
    for(int row{1}; row <= size - 1 ; ++row)
    {
        std::cout << ' ';
        for(int column{1}; column <= numElements - 2; ++column)
        {
            if (row <= size && column >= row && column <= numElements - 1 - row)
            {
                std::cout << '*';
            }

            else
            {
                std::cout << ' ';
            }
        }

        std::cout << '\n';
    }
    return 0;
}