#include <iostream>

int tripleByValue(int x) 
{
    x = x * 3;
    return x;
}

int tripleByReference(int &x) 
{
    x = x * 3;
    return x;
}

int main() 
{
    int x = 5;
    int y = 10;

    std::cout << "Before tripleByValue: " << x << std::endl;
    tripleByValue(x);
    std::cout << "After tripleByValue: " << x << std::endl;
    

    std::cout << "Before tripleByReference: " << y << std::endl;
    tripleByReference(y);
    std::cout << "After tripleByReference: " << y << std::endl;
    

    return 0;
}