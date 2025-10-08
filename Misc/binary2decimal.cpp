#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    size_t input_binary {0};
    int decimal_number  {0};
    int loop_counter    {0};
    int remainder       {0};
    
    
    cout << "Input the binary number: \t";
    cin >> input_binary;
    
    while(input_binary)
    {
        remainder = input_binary % 10;
        
        int index_of_binary{1};
        int test_loop = loop_counter;

        while(test_loop)
        {
            index_of_binary *= 2;
            test_loop--;
        }

        decimal_number  = decimal_number + index_of_binary * remainder;
        
        loop_counter++;

        input_binary /= 10;
    }

    cout << "\n\nDecimal number corresponding to the input binary: \t" << decimal_number;

    return 0;

}