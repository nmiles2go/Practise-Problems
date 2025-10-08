#include <iostream> 

using namespace std;

int main()
{
    int counter{0};
    int largest{0};
    int number {0};

    //largest = number;

    while(counter < 10)
    {
        cout << "Enter the sales number for the employee: ";
        cin >> number;
        
        // if the value entered is larger than the largest
        if(number > largest)
        {
            // set largest =  number and increase counter
            largest = number;
            ++counter;
        }

        else 
        {
            ++counter;
        }

    }

    cout << "\n\nThe Largest sales figure is: " << largest;

    return 0;
    // Counter Controlled iteration because 10 inputs
    // input all numbers and figure out a way to print out the largest
    // salesperson who sells the most, wins.
}