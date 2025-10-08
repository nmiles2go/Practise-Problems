#include <iostream>

double ePowerx(int x , int n)
{
    static double result{1};

    if(0 == n)
    {
        return result;
    }

    else
    {
        result = 1 + (x * result)/ n;
        return ePowerx(x, n-1);
    }
}

int main()
{
    std::cout << ePowerx(1, 10);

   return 0;
}