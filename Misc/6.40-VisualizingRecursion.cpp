
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial(unsigned long); // function prototype

int main() {
   // calculate the factorials of 0 through 10
   // for (unsigned int counter{0}; counter <= 10; ++counter) {
   //    cout << setw(2) << counter << "! = " << factorial(counter)
   //       << endl;
   // }

   cout << factorial(10);
}

// recursive definition of function factorial   
unsigned long factorial(unsigned long number) {
   
   static unsigned long N{number}; // static local variable
   //cout << N << endl;
   
   if (number <= 1) { // test for base case     
      return 1; // base cases: 0! = 1 and 1! = 1
   }
   else 
   { // recursion step  
      //cout << N << endl;
      unsigned long i{0};
     while(i < N - number)
     {
        cout << "  "; ++i;
     }
      
      
      cout << "factorial(" << number << ") called and recursive parameter " << number << " x factorial(" << number - 1 << ") called." << endl;
      
      return number * factorial(number - 1);
   }
}



