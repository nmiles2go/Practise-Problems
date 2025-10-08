#include<iostream>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    std::cout << "\nElements are: \n";

    for(i=0;i<arr.length;++i)
    {
        std::cout << arr.A[i];
    }
}

int main()
{
    struct Array arr;
    int n,i;
    
    std::cout << "Enter Size of an array: ";
    std::cin >> arr.size;
    arr.A = new int[arr.size]; // created arrat in heap
    arr.length = 0;

    std::cout << "\nEnter the number of numbers: ";
    std::cin >> n;

    std::cout << "\nEnter all elements";
    for(i = 0; i<n; ++i)
    {
        std::cin >> arr.A[i];
    }
    arr.length = n;

    Display(arr);

    return 0;
}