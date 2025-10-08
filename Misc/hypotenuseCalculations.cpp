#include <cmath>
#include <iostream>
#include <iomanip>

inline double hypotenuse (const double, const double);

int main()
{
    std::cout << std::fixed << std::setprecision(2) << hypotenuse(3.0,4.0)  << std::endl;
    std::cout << std::fixed << std::setprecision(2) << hypotenuse(5.0,12.0) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << hypotenuse(8.0,15.0) << std::endl;

    return 0;
}

double hypotenuse (const double side1, const double side2)
{
    return sqrt(pow(side1,2) + pow(side2, 2));
}