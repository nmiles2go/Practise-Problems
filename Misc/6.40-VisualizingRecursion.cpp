#include <iostream>

using namespace std;


unsigned long factorial(unsigned long number, unsigned long depth = 0);


int main() 
{
   cout << factorial(4);
}

// recursive definition of function factorial   
unsigned long factorial(unsigned long number, unsigned long depth) 
{
   
   unsigned long result{0};
   

   if (number <= 1) 
   { // test for base case   

      for (unsigned int i = 0; i < depth; i++)
         cout << "  ";

      cout << "Base Case factorial(" << number << ") called and returns 1" << endl;  
      result = 1; 
   }

   else 
   {
      unsigned long i{0};
      while(i < depth)
      {
         cout << "  "; ++i;
      }
      
      
      cout << "factorial(" << number << ") called. Entering recursive call " << number << " x factorial(" << number - 1 << ")." << endl;
      
      // recursive step
      result = number * factorial(number - 1, depth + 1); 
   }

   unsigned long i{0};
   while(i < depth)
   {
      cout << "  "; ++i;
   }

   cout << "factorial(" << number << ") returns " << result << endl;
   return result;
}



