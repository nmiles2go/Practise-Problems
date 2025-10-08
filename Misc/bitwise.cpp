#include <iostream>
using namespace std;

bool isEven(int n)
{   
    // taking bitwise and of n with 1 
    if ((n & 1) == 0) // n = 4 -> 100 & 001 = 000
        return true;
    else
        return false; // n = 5 -> 101 & 001 = 001
}

int main()
{
    int n = 15;
    if (isEven(n) == true)
        cout << "true";
    else
        cout << "false";

    return 0;
}