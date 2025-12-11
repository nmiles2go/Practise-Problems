#include <iostream>
#include <array>

using std::array;

int main()
{
    array<char, 8> alphabet {'a', 'l', 'p', 'h', 'a', 'b', 'e', 't'};

    std::cout << alphabet[6];
    return 0;
}