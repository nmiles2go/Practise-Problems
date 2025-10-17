#include <iostream>

#define PI 3.14159265358979323846 // as defined in corecrt_math_defines.h

inline double areaCircle(int radius)
{
    return PI * radius * radius;
}

int main()
{
    int radius{1};

    std::cout << "Area of circle with radius " << radius << " is " << areaCircle(radius) << std::endl;
    return 0;
}