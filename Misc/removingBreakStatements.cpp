

// Fig. 5.13: BreakTest.cpp
// break statement exiting a for statement. 
#include <iostream>
using namespace std;

int main() {
   unsigned int count; // control variable also used after loop 
   
   for (count = 1; count <= 10; count++) { // loop 10 times
      if (count == 5) {
            count = 10; // terminates loop if count is 5. Originally break was used.
      }

      cout << count << " ";
   }

   cout << "\nBroke out of loop at count = " << count << endl;
} 


