#include <iostream>

int main() {
    const int SIZE = 5;
    const int MIN = 1;
    const int MAX = 30;

    for (int i = 1; i <= SIZE; ++i) {
        int input = 0;

        std::cout << "Enter number " << i << " (between " << MIN << " and " << MAX << "): ";
        std::cin >> input;

        while (input < MIN || input > MAX) {
            std::cout << "Error: Number must be between " << MIN << " and " << MAX << ".\n";
            std::cout << "Enter number " << i << " again: ";
            std::cin >> input;
        }

        while(input)
        {
            std::cout << "*";
            input--;
        }
        
    }

    std::cout << "\nAll numbers entered successfully." << std::endl;

    return 0;
}
