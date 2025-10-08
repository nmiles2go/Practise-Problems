#include <iostream>

using namespace std;

int main()
{
    cout << "Input a number: ";
    
    int number;
    cin >> number;
    
    int original_number = number;
    int reversed_number{0};
    while(number)
    {
        int remainder = number % 10;
        cout << remainder << endl;
        
        reversed_number = 10 * reversed_number  + remainder;
        number/=10;

    }

    if(reversed_number == original_number)
    {
        cout << "\n\nThe number is a Palindrome!";
    }

    else
    {
        cout << "\n\nThe number is NOT a Palindrome!";
    }
    

    //cout << number_length;
    return 0;
}