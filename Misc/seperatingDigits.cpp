#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Find the number of digits
    int temp = number;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Print each digit from highest place to lowest
    for (int i = digits - 1; i >= 0; i--) {
        int divisor = pow(10, i);
        int digit = number / divisor;
        cout << digit << " ";
        number %= divisor;
    }

    cout << endl;
    return 0;
}
