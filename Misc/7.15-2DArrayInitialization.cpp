#include <iostream>
#include <array>

using std::array;
int main()
{
    const int ROWS    {3};
    const int COLUMNS {5};

    // 2D Array 
    array<array<int, COLUMNS>,ROWS> sales;

    std::cout << "sales.size()" << sales.size() << std::endl;
    std::cout << "sales[0].size()" << sales[0].size() << std::endl;
    
    for (size_t rows{0}; rows < sales.size(); ++rows)
    {
        for (size_t columns{0}; columns < sales[rows].size(); ++columns)
        {

            sales[rows][columns] = 0;
            std::cout << rows << ", " << columns << " -> " << sales[rows][columns] << std::endl;
        }
        
        /* code */
    }
    
    
    return 0;
}