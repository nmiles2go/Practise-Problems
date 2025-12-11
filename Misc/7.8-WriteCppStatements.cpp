#include <iostream>
#include <array>

using std::array;

int main()
{
    array<char, 8> alphabet {'a', 'l', 'p', 'h', 'a', 'b', 'e', 't'};
    array<int, 8> grades {0};
    
    std::cout << alphabet[0];
    
    std::cin >> grades[4];

    std::cout << grades[4];
    
    return 0;
}