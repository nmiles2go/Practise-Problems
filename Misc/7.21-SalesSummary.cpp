#include <iostream>
#include <random>
#include <array>
#include <iomanip>
#include <string>

using std::array;

int main() 
{
    const int numSalesman {4};
    const int numProducts {5};
    const int numSlips {0};

    int totalSalesPerSalesman {0};
    int totalSalesPerProduct {0};
    
    array<array<int, numProducts>, numSalesman> sales {};
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDist(150, 500);
    
    // Header row
    std::cout << std::setw(15) << std::left << " "; 
    for (size_t j = 0; j < numProducts; j++)
    {
        std::cout << std::setw(8) << std::right << ("P-" + std::to_string(j+1));
    }
    std::cout << std::setw(10) << std::right << "total\n"; 

    // Sales data rows
    for (int i = 0; i < numSalesman; ++i) 
    {
        for (int j = 0; j < numProducts; ++j) 
        {
            sales[i][j] = valueDist(gen);
        }

        std::cout << std::setw(15) << std::left << ("Salesman " + std::to_string(i + 1));
        totalSalesPerSalesman = 0;
        
        for (size_t j = 0; j < numProducts; j++) 
        {   
            std::cout << std::setw(8) << std::right << sales[i][j];
            totalSalesPerSalesman += sales[i][j];
        }
        
        std::cout << std::setw(10) << std::right << totalSalesPerSalesman;
        std::cout << std::endl;
    }
    
    // Product totals row
    std::cout << std::setw(15) << std::left << "Product Sales";
    
    for (size_t j = 0; j < numProducts; j++)
    {
        totalSalesPerProduct = 0;
    
        for (size_t i = 0; i < numSalesman; i++)
        {
            totalSalesPerProduct += sales[i][j];
        }
        
        std::cout << std::setw(8) << std::right << totalSalesPerProduct; 
    }
    
    std::cout << std::endl;
    
    return 0;
}