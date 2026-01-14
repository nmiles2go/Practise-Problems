#include <iostream>
#include <random>
#include <array>

using std::array;

struct slipsData 
{
    int salesPersonNum;
    int productNum;
    int dayTotalValueProduct;
};

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
    
    std::cout << "                 "; 
    for (size_t j = 0; j < numProducts; j++)
    {
        std::cout << "P-" << j+1 << "    ";
    }
    
    std::cout << "Total Sales by Salesman\n"; 


    for (int i = 0; i < numSalesman; ++i) 
    {
        for (int j = 0; j < numProducts; ++j) 
        {
            
            sales[i][j] = valueDist(gen);

            
        }

        std::cout << "Salesman " << i + 1 << "       ";
        totalSalesPerSalesman = 0;
        for (size_t j = 0; j < numProducts; j++) 
        {   
            std::cout << sales[i][j] << "    ";
            totalSalesPerSalesman += sales[i][j];
        }
        
        std::cout << totalSalesPerSalesman;
        std::cout << std::endl;
    }
    
    std::cout << "Product Sales    ";
    
    for (size_t j = 0; j < numProducts; j++)
    {
        totalSalesPerProduct = 0;
    
        for (size_t i = 0; i < numSalesman; i++)
        {

            totalSalesPerProduct += sales[i][j];
            //std::cout << i << ", " << j << std::endl;
        }
        
        std::cout << totalSalesPerProduct << "   "; 
    }
    
    return 0;
}