#include <iostream>
#include <array>

int main()
{
    const int rows{2};
    const int columns{3};
    
    std::array<std::array<int, columns>, rows> t = {1,2,3,4,5,6}; // Declaration of the array

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    t[0][1] = 0;
    std::cout << std::endl;
    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    t[0][0] = 0;
    t[0][1] = 0;
    t[0][2] = 0;
    t[1][0] = 0;
    t[1][1] = 0;
    t[1][2] = 0;
    std::cout << std::endl;

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    t[0][0] = 1;
    t[0][1] = 1;
    t[0][2] = 1;
    t[1][0] = 1;
    t[1][1] = 1;
    t[1][2] = 1;
    std::cout << std::endl;

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    for(int i{0}; i < t.size(); ++i)
    {
        for(int j{0}; j < t[rows].size(); ++j)
        {
            t[i][j] = 0;
        }
    }

    std::cout << std::endl;
    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    t[0][0] = 1;
    t[0][1] = 1;
    t[0][2] = 1;
    t[1][0] = 1;
    t[1][1] = 1;
    t[1][2] = 1;
    std::cout << std::endl;

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    for(auto &i: t)
    {
        for(auto &j: i)
        {
            j = 0;
        }
    }

    std::cout << std::endl;

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    for(auto &i: t)
    {
        for(auto &j: i)
        {
            std::cin >> j;
        }
    }

    std::cout << std::endl;

    for(int i = 0; i < rows; ++i)
    {
            
            for(int j = 0; j < columns; ++j)
            {
                std::cout << "(" << i << "," <<j << ")" << t[i][j] << "\t";
            }

            std::cout << std::endl;
    }

    int smallest{INT_MAX};
    for(auto &i: t)
    {
        for(auto &j: i)
        {
            if(j < smallest)
            {
                smallest = j;
            }
        }
    }

    std::cout << "\nSmallest number in the array: " << smallest << std::endl;

    for(auto &i: t[0])
    {
        std::cout << i;
    }

    std::cout << std::endl;

    int sum = 0;

    for (auto &row : t) 
    {
        sum += row[1];   
    }

    std::cout << "Sum of elements in the second column: " <<sum << std::endl;
    
    return 0;
}