#include <iostream>
#include <cmath>

int timeInSeconds(int hours, int minutes, int seconds);

int main()
{
    std::cout << timeInSeconds(12, 10, 0);
    return 0;
}

int timeInSeconds(int hours, int minutes, int seconds)
{
    if(hours < 12 && minutes < 60 && seconds < 60)
    {
        return hours * 3600 + minutes * 60 + seconds;

    }

    else
    {
        std::cout << "Enter the correct values!\n";
        return -1;
    }
}
