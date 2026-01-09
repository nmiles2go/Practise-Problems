#include <iostream>
#include <array>

const size_t arraySize{10};

int whatIsThis(const std::array<int, arraySize>&, size_t);

int main()
{
    std::array<int, arraySize> a { 1,2,3,4,5,6,7,8,9,10};
    int result {whatIsThis(a, arraySize)};
    std::cout  << "Result is " << result << std::endl;

    return 0;
}

// This Function adds elements in the array
int whatIsThis(const std::array<int, arraySize>& b, size_t size)
{
    if(1 == size)
    {
        return b[0];
    }

    else
    {
        return b[size-1] + whatIsThis(b, size-1);
    }
}