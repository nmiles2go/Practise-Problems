#include <iostream>
 using namespace std;
int main() {
    // Your code goes here

    // make a square of stars
    // You should input size of square side

    int size{0};
    int i{0};

    std::cout << "Enter the size of the square: ";
    std::cin >> size;

    // size = 3
    // *** endline
    // * * endline
    // *** 
    // 

    while(i < size)
    {
        int j{0};
        while(j < size)
        {
            if(i == 0 || i == size -1 || j == 0 || j == size - 1) cout << "*";
            else(cout << " ");
            j++;
        }
        
        i++;
        cout << endl;
    }
    return 0;
}