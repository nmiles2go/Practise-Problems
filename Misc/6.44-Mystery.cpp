#include <iostream>
#include <cmath>
using namespace std;

int multiply1(int, int); // function prototype
int multiply2(int, int);

int main() 
{
   cout << "Enter two integers: ";
   int x{0};
   int y{0};
   cin >> x >> y;
   cout << "The result is " << multiply2(x, y) << endl;
}

// Parameter b must be a positive integer to prevent infinite recursion
int multiply1(int a, int b) 
{
   
   b = fabs(b); // ensure b is non-negative-

   if (b == 1)
   { // base case
      return a;
   }

   else 
   { // recursion step
      //cout << "Multiply again";
      return  a + multiply1(a, b - 1);
   }
    
   
}

// Another way to write multiply using a different base case

int multiply2(int a, int b) 
{
   
   

   if (b == 0)
   { // base case
      return 0;
   }

   else if (b < 0)
   {
      return -multiply2(a, -b);
   }

   else
   { // recursion step
      
      return  a + multiply2(a, b - 1);
   }
    
   
}