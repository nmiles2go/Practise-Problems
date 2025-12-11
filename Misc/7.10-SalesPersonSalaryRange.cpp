#include <iostream>
#include <array>

using std::array;
using std::cout;
int main()
{
    // USe 1D array
    array<int, 9> Counters {0};

    for (int element : Counters)
    {
        cout << element << std::endl;
    }
    // Earning/week = 200 + 0.09 (gross sales/week)

    // Array of Counters


    return 0;
}