#include <stdio.h>

struct Array 
{
    int A[10];
    int size;
    int length;
};

// Function prototypes
void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int LinearSearch(struct Array *arr, int key);
void swap(int *x, int *y);
int BinSearchIteration(struct Array arr1, int key);
int BinSearchRecurion(struct Array arr1, int low, int high, int key);

int main() 
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    printf("%d  %d", BinSearchIteration(arr1, 2), BinSearchRecurion(arr1, 0, arr1.length - 1, -1));
    //printf("%d", BinSearchIteration(arr1, 2));
    Display(arr1);
    return 0;
}

void Display(struct Array arr) 
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++) 
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x) 
{
    if (arr->length < arr->size) 
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void Insert(struct Array *arr, int index, int x) 
{
    int i;
    if (index >= 0 && index <= arr->length) 
    {
        for (i = arr->length; i > index; i--) 
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) 
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length) 
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++) 
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinSearchIteration(struct Array arr1, int key)
{
    int low = 0;
    int high = arr1.length - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (key == arr1.A[mid])
        {
            return mid;
        }
        else if (key < arr1.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
        
    return -1;
}

int BinSearchRecurion(struct Array arr1, int low, int high, int key)
{

    if(low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr1.A[mid])
        {
            return mid;
        }
        else if (key < arr1.A[mid])
        {
            return BinSearchRecurion(arr1, low, mid - 1, key);
        }
        else
        {
            return BinSearchRecurion(arr1, mid + 1, high, key);
        }
    }
    return -1;
}
