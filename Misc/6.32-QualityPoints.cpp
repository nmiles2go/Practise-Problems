#include <iostream>
using namespace std;

int qualityPoints(int grade) {
    switch (grade/10) {
        case 9 :               return 4;
        case 8:                return 3;
        case 7:                return 2;
        case 6:                return 1;
       
        default:               return 0;          
    }
}
int main() {
    int n = 72;
    cout << qualityPoints(n);
   
    return 0;
}