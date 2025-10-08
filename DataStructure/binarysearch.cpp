#include<iostream>

using std::cout;
using std::endl;

struct Array
{
    int A[50];
    int size;
    int length;
};

void display(Array arr)
{
    for(int i{0}; i<arr.length; i++){
        cout<< arr.A[i]<<" ";
    }
    cout<<endl;
}

int BinarySearchIterative(Array arr, int key)
{
    int l{0};
    int h{arr.length -1};
    int mid;

    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            h = mid -1;
        }
        else{
            l = mid +1;
        }
    }
    return -1;
}



int main()
{
    
    Array arr {{2,3,4,5,6,11,12, 18, 20, 35, 46, 47, 49, 53, 55},20,15};
    cout << "Original Array: ";
    display(arr);

    int key = 20;
    
    int index = BinarySearchIterative(arr, key);
    if(index != -1){
        cout << "Element " << key << " found at index " << index << " using Iterative Binary Search." << endl;
    }
    else{
        cout << "Element " << key << " not found using Iterative Binary Search." << endl;
    }

    

    return 0;
}