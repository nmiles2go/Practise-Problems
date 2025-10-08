// C++ Code to swap two numbers using bitwise XOR

#include <iostream>
using namespace std;

int main() {
    int a = 2, b = 3;
    cout << "a = " << a << " b = " << b << endl;   
   
    a = a ^ b; // Step 1: a now becomes 1 (2^3)
    b = a ^ b; // Step 2: b becomes 2 (1^3)
    a = a ^ b; // Step 3: a becomes 3 (1^2)
  
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}