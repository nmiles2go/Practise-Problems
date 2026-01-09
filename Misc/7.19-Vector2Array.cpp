#include <iostream>
#include <iomanip>
#include <vector>
#include <array>   
#include <stdexcept>
using namespace std;

int main() {

   const int sizeIntegers1Array{7}; 
   const int sizeIntegers2Array{10}; 
   array<int, sizeIntegers1Array> integers1 {}; // 7-element vector<int>  
   array<int, sizeIntegers2Array> integers2{}; // 10-element vector<int>

   // print integers1 size and contents
   std::cout << "Size of vector integers1 is " << integers1.size()
      << "\nvector after initialization: ";
   for (int i: integers1)
   {
        std::cout << i << " ";
    /* code */
   }
   

   // print integers2 size and contents
   std::cout << "\nSize of vector integers2 is " << integers2.size()
      << "\nvector after initialization: ";
   for (int i: integers2)
   {
        std::cout << i << " ";
    /* code */
   }
   // input and print integers1 and integers2
   std::cout << "\nEnter 17 integers:" << endl;
   
   for (int &i: integers1)
   {
        std::cin >> i;
    /* code */
   }

   for (int &i: integers2)
   {
        std::cin >> i;
    /* code */
   }

   std::cout << "\nAfter input, the vectors contain:\n" 
      << "integers1: ";
    for (int i: integers1)
   {
        std::cout << i << " ";
    /* code */
   }
   
   std::cout << "integers2: ";
   for (int i: integers2)
   {
        std::cout << i << " ";
    /* code */
   }

   // use inequality (!=) operator with actor objects
   std::cout << "\nEvaluating: integers1 != integers2" << endl;

   for (size_t i = 0; i < sizeIntegers1Array; i++)
   {
       if (integers1[i] != integers2[i]) {
          std::cout << "integers1 and integers2 are not equal" << endl;
          break;
       }
    /* code */
   }
   

   // create vector integers3 using integers1 as an         
   // initializer; print size and contents                  
   array<int, sizeIntegers1Array> integers3 = integers1; // copy constructor

   std::cout << "\nSize of vector integers3 is " << integers3.size()
      << "\nvector after initialization: ";
   for (int i: integers3)
   {
        std::cout << i << " ";
    /* code */
   }

   // use overloaded assignment (=) operator              
   std::cout << "\nAssigning integers2 to integers1:" << endl;
   for (size_t i = 0; i < sizeIntegers1Array; i++)
   {
       integers1[i] = integers2[i]; // assign integers2 to integers1
    /* code */
   }
   

   std::cout << "integers1: ";

   for (int i: integers1)
   {
        std::cout << i << " ";
    /* code */
   }
   
   std::cout << "integers2: ";

   for (int i: integers2)
   {
        std::cout << i << " ";
    /* code */
   }
   

   // use equality (==) operator with vector objects
   std::cout << "\nEvaluating: integers1 == integers2" << endl;

//    if (integers1 == integers2) {
//       cout << "integers1 and integers2 are equal" << endl;
//    }

   // use square brackets to use the value at location 5 as an rvalue
   std::cout << "\nintegers1[5] is " << integers1[5];

   // use square brackets to create lvalue
   std::cout << "\n\nAssigning 1000 to integers1[5]" << endl;
   integers1[5] = 1000;
   std::cout << "integers1: ";

   for (int i: integers1)
   {
        std::cout << i << " ";
    /* code */
   }

   // attempt to use out-of-range subscript                     
   try {
      std::cout << "\nAttempt to display integers1.at(15)" << endl;
      std::cout << integers1.at(15) << endl; // ERROR: out of range
   }
   catch (out_of_range& ex) {
      cerr << "An exception occurred: " << ex.what() << endl;
   }

   // changing the size of a vector
   std::cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
   //integers3.push_back(1000); // add 1000 to the end of the vector
   std::cout << "New integers3 size is: " << integers3.size() << endl;
   std::cout << "integers3 now contains: ";
   for (int i: integers3)
   {
        std::cout << i << " ";
    /* code */
   }
}








