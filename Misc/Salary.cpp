#include <iostream> 

using namespace std;

int main()
{
    // We want to determine the gross pay for each of the several employees

    int working_hours{0};
    int hourly_rate{0};

    cout << "\n\n Enter the working hours of the employee (-1 to quit):  ";
    cin >> working_hours;
    
    // while the number is not the sentinal value
    while(working_hours != -1)
    {
        
        // Prompt the user to enter the hourly rate
        cout << "\n\n Enter the hourly rate of the employee:  ";
        // Input the hhourly rate
        cin >>  hourly_rate;
        
        // if the hourly rate is less or equal to 40
        if(working_hours <= 40)
        {
            // print out hourly rate * number of hours
            cout << "\n\n Salary of the employee:  " << hourly_rate * working_hours << endl;
        }

        // else
        else
        {
            // print out hourly rate * 40 + (1.5*hourly rate) * (number of hours - 40)
            cout << "\n\n Salary of the employee:  " << hourly_rate * 40 + (1.5 * hourly_rate) * (working_hours - 40)  << endl;
        }

        
        // Prompt the user to enter the number of hours

        cout << "\n\n Enter the number of hours the employee worked (-1 to quit):  ";
        // input the number of hours
        cin >> working_hours;
    }
        

    return 0;
    
}