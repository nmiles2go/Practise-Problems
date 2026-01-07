#include <iostream>
#include <array>

using std::array;
int main()
{
    const int NUM_INTEGERS {15};
    const int NUM_DOUBLES {12};

    array<int, NUM_INTEGERS> counts = {0};
    array<int, NUM_INTEGERS> bonus = {0};
    array<int, 5> bestScores {100, 94, 52, 12, 63};

    array<double, NUM_DOUBLES> monthlyTemperature = {0};

    for(int i: counts)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for(int &i: bonus)
    {
        i++;
    }

    for(int i: bonus)
    {
        std::cout << i << " ";
    }

    for(double &i: monthlyTemperature)
    {
        std::cin >> i;
    }

    for(double i: monthlyTemperature)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    for(int i: bestScores)
    {
        std::cout << i << '\n';
    }

    return 0;
}