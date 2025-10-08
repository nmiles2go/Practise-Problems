#include <iostream>

using namespace std;

int main()
{
    int productID{0};
    float price{0.0f};
    int quantity{0};
    // Use switch to determine the price of the product.

    while (true)
    {

    cout << "\nEnter the Product ID (-1 to quit): ";
    cin >> productID;

    if(productID == -1) break;
    
    switch (productID)
    {
        case 1: 
        price = 2.98f;
        break;
        
        case 2:
        price = 4.50f;
        break;
        
        case 3:
        price = 9.98f;
        break;
        
        case 4:
        price = 4.49f;
        break;
        
        case 5:
        price = 6.87f;
        break;
        
        default:
        break;
    }
    
    cout << "\nEnter the Product Quantity (-1 to quit): ";
    cin >> quantity;

    cout << price * quantity;

    }
    return 0;
}