#include <array>
#include <iostream>

using std::cout;

const size_t arraySize{10};
void someFunction(const std::array<int, arraySize>&, size_t);

int main()
{
    std::array<int, arraySize> a = {1,2,3,4,5,6,7,8,9,10};

    std::cout << "The values in the array are: " << std::endl;

    someFunction(a, 0);

    std::cout << std::endl;
    return 0;
}

void someFunction(const std::array<int, arraySize>& b, size_t current)
{
    if (current < b.size())
    {
        someFunction(b, current + 1);
        std::cout << b[current] << " ";
    }
    
}