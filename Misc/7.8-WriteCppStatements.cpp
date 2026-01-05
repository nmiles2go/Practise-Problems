#include <iostream>
#include <array>
#include <iomanip>

using std::array;

int main()
{
   
    array<char, 8> alphabet {'a', 'l', 'p', 'h', 'a', 'b', 'e', 't'};
    array<int, 8> grades {0};
    
   

    // const int length1 = 5;
    // array<int, length1> sameElements = {};

    // for (int &i : sameElements)
    // {
    //     i = 8;
    //     std::cout << i;

    // }

    // const int length3{100};
    // float sum {0.0f};

    // array<float, length3> addFloats = {0};
    
    // for(int i = 0; i < 100; ++i)
    // {
    //     addFloats[i] = static_cast<float>(1.0f + i);
    // }

    // for (float i: addFloats)
    // {
    //     std::cout << std::setw(2) << std::setprecision(2) << std::fixed << i;
    //     sum += i;
    // }

    // std::cout << sum;

    const int length4 = 11;
    const int length5 = 34;

    array<int, length4> a = {};
    array<int, length5> b = {};

    for(int i{0}; i < length4; ++i)
    {
        a[i] = 1;
    }

    for(int i{0}; i < length5; ++i)
    {
        b[i] = 5;
    }

    for(int i{0}; i < length4; ++i)
    {
        b[i] = a[i];
    }

    for(int i{0}; i < length5; ++i)
    {
        std::cout << b[i];
    }
    return 0;
}