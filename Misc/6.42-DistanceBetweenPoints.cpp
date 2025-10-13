#include <iostream>
#include <cmath>

double distanceBetweenPoints(double x1, double y1, double x2, double y2) 
{
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
int main() 
{
    double dist = distanceBetweenPoints(1.0, 2.0, 4.0, 6.0);
    std::cout << "Distance between points: " << dist << std::endl;
    return 0;
}