// Multithreading Basics in C++

#include <iostream>
#include <thread>

void function1()
{
    for (size_t i = 0; i < 200; i++)
    {
        /* code */
        std::cout << "+";
    }
    
}

void function2()
{
    for (size_t i = 0; i < 200; i++)
    {
        /* code */
        std::cout << "-";
        
    }
    
}
int main()
{

    std::thread worker1(function1);
    std::thread worker2(function2);
    // function1();
    // function2();
    system("pause>nul"); // Pause the console (Windows specific)
    return 0;
}