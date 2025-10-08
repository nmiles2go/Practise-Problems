#include <iostream>

int main()
{
    int size;
    std::cin >> size;

    // number of elements in a row
    int numElements = 2 * size - 1;
    for(int row{1}; row <= size ; ++row)
    {
        for(int column{1}; column <= numElements; ++column)
        {
            if (row <= size && column >= row && column <= numElements + 1 - row)
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

    std::cout << '\n';
    for(int row{1}; row <= size ; ++row)
    {
        for(int column{1}; column <= 2*size - 1; ++column)
        {
            // if(row < size && column <= size - row)
            // {
            //     std::cout << "x";
            // }

            // else if (row < size && column >= size + row)
            // {
            //     std::cout << "x";
                
            // }

            // else{
            //     std::cout << '*';
            // }

            if(row <= size && (column > (size - row) && column < (size + row)))
            {
                std::cout << '*';
            }
            
            
            else
            {
                std::cout << ' ' ;
            }

            

            //std::cout << '(' << row << ',' << column << ')' << "\t"; 
        }
        std::cout << '\n';
    }
    return 0;
}