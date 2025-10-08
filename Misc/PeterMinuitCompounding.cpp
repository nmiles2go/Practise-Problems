// Fig. 5.6: Interest.cpp
// Compound-interest calculations with for.
#include <iostream>
#include <iomanip>
#include <cmath> // for pow function
using namespace std;

int main() {
   // set floating-point number format
   cout << fixed << setprecision(2);

   double buyPriceManhatten{24.00}; // initial amount before interest
   //int rate{0}; // interest rate

   cout << "Initial principal: " << buyPriceManhatten << endl;
   //cout << "    Interest rate:    " << rate << endl;

   // display headers
   
   //calculate the interest by varying the interest rate
   for(unsigned int rate{5}; rate <= 7; rate++)
   {
       cout << "\nYear" << setw(30) << "Amount on deposit at " << rate << '%' << endl;
       for (unsigned int year{1}; year <= 390; year++) {
          // calculate amount on deposit at the end of the specified year
          double amount = buyPriceManhatten * pow(1.0 + rate/100.0, year);
    
          // display the year and the amount
          cout << setw(4) << year << setw(30) << scientific << amount << endl;
       } 

   }
   // calculate amount on deposit for each of ten years
}

