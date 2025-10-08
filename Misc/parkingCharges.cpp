#include <cmath>
#include <iomanip>
#include <iostream>

double calculateCharges(double);

int main()
{
    double time     {0.0};
    double totalHours    {0.0};
    double totalCharge    {0.0};
    
    std::cout << "Car\t\t" << "Hours\t\t" << "Charge\n";

    for(int count{1}; count <= 3; ++count)
    {
        std::cout << "Enter the time for customer " << count << " in the log: ";
        std::cin >> time;
        totalHours += time;
        totalCharge += calculateCharges(time);
    }

    for(int count{1}; count <= 3; ++count)
    {
        std::cout << count << "\t\t" << time << "\t\t" << calculateCharges(time) << "\n";      
    }

    std::cout << "TOTAL\t\t" << totalHours  << "\t\t" << totalCharge << "\n";
    return 0;
}

double calculateCharges(double time)
{

    const double minimumCharge  {20.0}; // upto three hours
    const double hourlyCharge   {5.0};  // per hour or fraction of an hour
    const double maxCharge      {50.0}; // max for 24 hour period

    if(time <= 3.0 && time > 0.0)
    {
        return minimumCharge;
    }

    else if (time > 3.0 && time <= 9.0)
    {
        return (time - 3.0) * hourlyCharge + minimumCharge;
    }

    else
    {
        return maxCharge;
    }

}