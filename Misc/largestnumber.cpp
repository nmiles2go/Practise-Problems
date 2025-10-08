#include  <iostream>

using namespace std;
int main()
{

    int total{0};
    int input{0};
    std::cout << "\nEnter the total number of Numbers to be checked: ";
    std::cin >> total;
    int smallest{0};
    for(unsigned int i{0}; i < total; ++i)
    {   
        cout << "\n\nEnter a number: ";
        cin >> input;
        
        if(input < smallest)
        {
            smallest = input;
        }


    }

    cout << "\n\nSMALLEST VALUE IS " << smallest << " among all the numbers!!!";
    return 0;
}