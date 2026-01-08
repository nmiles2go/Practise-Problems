#include <iostream>
#include <array>

using std::array;
int main()
{
    const int NUM_TOTAL_ELEMENTS {20};
    int NUM_UNIQUE_ELEMENTS {0};

    array<int, NUM_TOTAL_ELEMENTS> array1 = {0};
    array<int, NUM_TOTAL_ELEMENTS> uniqueArray = {0};

    for (int i = 0; i < NUM_TOTAL_ELEMENTS; i++)
    {
        std::cin >> array1[i];

        while(array1[i] < 1 || array1[i] > 100)
        {
            std::cout << "\nEnter a valid Number!\n";
            std::cin >> array1[i];
        }

        
    }
    
    for (int i = 0; i < NUM_TOTAL_ELEMENTS; i++)
    {
        bool isDuplicate = false;

       
        for (int j = 0; j < i; j++)
        {
            if (array1[i] == uniqueArray[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if(!isDuplicate)
        {
            uniqueArray[NUM_UNIQUE_ELEMENTS] = array1[i];
            ++NUM_UNIQUE_ELEMENTS;
        }
    }
    
    // Printing the unique elements
    std::cout << "\nUnique elements: ";

    for (int i = 0; i < NUM_UNIQUE_ELEMENTS; i++)
    {
        std::cout << uniqueArray[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

// Most efficient solution in terms of space

// #include <iostream>
// #include <array>

// using std::array;

// int main()
// {
//     const int NUM_ELEMENTS {20};
//     const int MAX_VALUE {101};
    
//     array<bool, MAX_VALUE> seen {false};  // Only 101 bools!

//     std::cout << "Enter 20 numbers (1-100):\n";

//     for (int i = 0; i < NUM_ELEMENTS; i++)
//     {
//         int input;
//         std::cin >> input;

//         while(input < 1 || input > 100)
//         {
//             std::cout << "Enter a valid Number (1-100)!\n";
//             std::cin >> input;
//         }

//         seen[input] = true;  // Mark as seen
//     }

//     // Print unique elements in order
//     std::cout << "\nUnique elements: ";
//     for (int i = 1; i <= 100; i++)
//     {
//         if (seen[i])
//         {
//             std::cout << i << ' ';
//         }
//     }
//     std::cout << std::endl;

//     return 0;
// }
