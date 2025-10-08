#include <cmath>
#include <iostream>

double celcius(const double);
double fahrenheit(const double);

int main()
{
    double fahrenheitTemperature{212.0};
    double celciusTemperature{101.0};
    std::cout << celcius(fahrenheitTemperature) << " " << fahrenheit(celciusTemperature);
    return 0;
}

double celcius(const double temperature)
{
    return (temperature - 32) * (5.0/9);
}

double fahrenheit(const double temperature)
{
    return (9 * temperature/5.0) + 32;
}