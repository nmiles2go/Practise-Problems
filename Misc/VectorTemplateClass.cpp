#include <iostream>
#include <vector>
#include <iomanip>
#include <array>
#include <stdexcept>

void outputVector(const std::vector<int>&);
void inputVector(std::vector<int>&);

int main()
{
   std::vector<int> integers1(7); // This is a 7 element vectir <int>
   std::vector<int> integers2(10); // This is a 10 element vector <int>

   std::cout << "Size of Vector integers1 is: " << integers1.size() << "\nVector after initialization: ";
   outputVector(integers1);

   std::cout << "\nSize of Vector integers2 is: " << integers2.size() << "\nVector after initialization: ";
   outputVector(integers2);

   std::cout << "\nEnter 17 integers: " << std::endl;
   inputVector(integers1);
   inputVector(integers2);
   
   std::cout << "After input, the vectors contain:\n" << "integers1: ";
   outputVector(integers1);
   std::cout << "\nintegers2: ";
   outputVector(integers2);
    
   std::cout << "\n\nEvaluating: integers1 != integers2" << std::endl;

   if(integers1 != integers2)
   {
       std::cout << "integers1 and integers2 are not equal" << std::endl;
   }

    std::vector<int> integers3{integers1}; // invokes copy constructor

    std::cout << "\nSize of Vector integers3 is: " << integers3.size() << "\nVector after initialization: ";
    outputVector(integers3);

    std::cout << "\nAssigning integers2 to integers1:" << std::endl;
    integers1 = integers2; // test overloaded assignment operator

    std::cout << "integers1: ";
    outputVector(integers1);
    std::cout << "\nintegers2: ";
    outputVector(integers2);

    if(integers1 == integers2)
    {
        std::cout << "\n\nintegers1 and integers2 are equal" << std::endl;
    }

    std::cout << "\nintegers1[5] is " << integers1[5] << std::endl;

    std::cout << "\n\nAttempting to assign 1000 to integers1[15]" << std::endl;
    integers1[15] = 1000; // ERROR: out of range index

    std::cout << "intergers1:";
    outputVector(integers1);

    // Attempt to use out of range subscript

    try
    {
        std::cout << "\nAttempting to display integers1.at(15)" << std::endl;
        std::cout << integers1.at(15) << std::endl; // ERROR: out of range
    }
    catch(std::out_of_range &ex)
    {
        std::cerr << "An exception occurred: " << ex.what() << std::endl;
    }
    

    std::cout << "\nCurrent integers3 size is: " << integers3.size() << std::endl;
    integers3.push_back(1000);
    std::cout << "New integers3 size is: " << integers3.size() << std::endl;
    std::cout << "integers3 now contains: ";
    outputVector(integers3);
    
    return 0;


}

void outputVector(const std::vector<int> &items)
{
    for(int item : items)
    {
        std::cout << item << " ";
    }
}

void inputVector(std::vector<int> &items)
{
    for(int &item : items)
    {
        std::cin >> item;
    }
}