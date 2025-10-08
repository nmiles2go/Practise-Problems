#include <iostream>
using namespace std;

int main()
{
    double one{0.0}, two{0.0}, three{0.0};
    while(one && two && three < 0)
    cin >> one;
    cin >> two;
    cin >> three;

    if(one + two > three && two + three > one && one + three > two)
    {
        cout << "yes\n\n";
    }

    else
    {
        cout << "no";
    }
}