#include <iostream>
#include <array>
#include <iomanip>

using std::array;
using std::cout;
using std::endl;

int main()
{
    const int NUM_SALARY_RANGES {9};
    const int NUM_EMPLOYEES     {10};

    // Use 1D array
    array<int, NUM_SALARY_RANGES> salaryRangeCounts {0};
    array<int, NUM_EMPLOYEES > salesFigures {1000, 2342, 221, 521, 78575, 
                                              2964, 5000, 10000, 6669866, 88889879};

    int weeklySalary {0};
    
    cout << "Employee Salaries:\n";
    cout << std::string(40, '-') << endl;
    
    for (int sales  : salesFigures)
    {
        weeklySalary  = 200 + (9 * sales ) / 100;
        
        int index = (weeklySalary  < 1000) ? (weeklySalary / 100 - 2) : 8;
        if(index >= 0 && index < NUM_SALARY_RANGES)
        {
            ++salaryRangeCounts[index];
        }
        
        cout << "$" << weeklySalary  << endl;
    }

    // Display results
    cout << "\nSalary Range Distribution:\n";
    cout << std::string(40, '.') << endl;
    
    array<std::string, NUM_SALARY_RANGES> rangeLabels {
        "$200-$299", "$300-$399", "$400-$499", 
        "$500-$599", "$600-$699", "$700-$799",
        "$800-$899", "$900-$999", "$1000+"
    };
    
    for(int i = 0; i < NUM_SALARY_RANGES; ++i)
    {
        cout << std::setw(12) << std::left << rangeLabels[i] 
             << ": " << salaryRangeCounts[i] << " employee(s)\n";
    }

    return 0;
}