// Fig. 5.6: Interest.cpp
// Compound-interest calculations with for.
#include <iostream>
#include <iomanip>
#include <cmath> // for pow function
using namespace std;

int main() {
   // set floating-point number format
   cout << fixed << setprecision(2);

   double principal{1000.00}; // initial amount before interest
   int rate{0}; // interest rate

   cout << "Initial principal: " << principal << endl;
   cout << "    Interest rate:    " << rate << endl;

   // display headers
   for (int rate{5}; rate <= 10; rate++)
   {
        cout << "\nRate" << setw(20) << "Year" << setw(20) << "Amount on deposit" << endl;
        // calculate amount on deposit for each of ten years
        for (unsigned int year{1}; year <= 10; year++) {
           // calculate amount on deposit at the end of the specified year
           double amount = principal * pow(1.0 + rate/100.0, year);
     
           // display the year and the amount
           cout << rate << "%" << setw(4) << year << setw(20) << amount << endl;
        } 

    }
}






