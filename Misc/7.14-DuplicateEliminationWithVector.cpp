#include <iostream>
#include <vector>

using std::vector;

int main()
{
    const int NUM_TOTAL_ELEMENTS {20};
    
    vector<int> array1;
    vector<int> uniqueArray;

    // Input phase
    for (int i = 0; i < NUM_TOTAL_ELEMENTS; i++)
    {
        int value;
        std::cin >> value;

        while(value < 1 || value > 100)
        {
            std::cout << "\nEnter a valid Number!\n";
            std::cin >> value;
        }

        array1.push_back(value);
    }
    
    for (const int& element : array1)
    {
        bool isDuplicate = false;

        for (const int& unique : uniqueArray)
        {
            if (element == unique)
            {
                isDuplicate = true;
                break;
            }
        }

        if(!isDuplicate)
        {
            uniqueArray.push_back(element);
        }
    }
    
    // Printing the unique elements
    std::cout << "\nUnique elements: ";

    for (int i = 0; i < uniqueArray.size(); i++)
    {
        std::cout << uniqueArray[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}