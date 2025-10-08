#include <iostream>
#include <cmath>
#include <random>
#include <ctime>


int main()
{
    
    srand(static_cast<unsigned int>(time(0)));

    int n1 = 1 + rand() % 2;
    int n2 = 1 + rand() % 100;
    int n3 = rand() % 10;
    int n4 = 1000 + rand() % 113;
    int n5 = -1 + rand() % 3;
    int n6 = -3 + rand() % 15;
    int n7 = 2*(1 + rand() % 5);
    int n8 = 3 + (rand() % 5) * 2;
    int n9 = 6 + (rand() % 5) * 4;
    
    std::cout << n9 << std::endl;
    
    return 0;
}