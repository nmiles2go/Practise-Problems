#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double value = 123.02;

    cout << "High precision output of 123.02 stored in a double:\n";
    
    // Display the value with increasing precision to identify representational error
    for (int precision = 1; precision <= 20; ++precision) {
        cout << "Precision " << setw(2) << precision << ": ";
        cout << fixed << setprecision(precision) << value << endl;
    }

    return 0;
}
