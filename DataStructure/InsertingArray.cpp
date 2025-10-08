#include <iostream>
using namespace std;
 
class Array{
private:
    int *A;
    int size;
    int length;
public:
    Array(int sz);
    void create();
    void display();
    void append(int x);
    void insert(int index, int x);
    ~Array();
};
 
Array::Array(int sz){
    sz = size;
    A = new int [sz];
}
 
void Array::create(){
    cout<<"enter length for array: ";
    cin>>length;
    cout<<"enter elements for array: "<<endl;
    for(int i{0}; i<length; i++){
        cout<<"array at "<<i<<" : ";
        cin>>A[i];
    }
}
void Array::display(){
    for(int i{0}; i<length; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
 
void Array::append(int x){
    if(length < size){
        A[length] = x;
        length++;
    }
}
 
void Array::insert(int index, int x){
    if(length < size){
        for(int i{length}; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}
 
Array::~Array(){
    delete [] A;
}
 
 
int main(){
    Array arr(10);
    arr.create();
    arr.display();
    arr.append(69);
    arr.display();
    arr.insert(10, 66);
    arr.display();
    return 0;
}