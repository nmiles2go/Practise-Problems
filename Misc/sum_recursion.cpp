#include <iostream>
#include <vector>
using namespace std;

// Method 1: Simple recursion (not optimized)
// Time complexity: O(n), Space complexity: O(n) - stack frames
int sumRecursive(int arr[], int n) {
    // Base case: if no elements, return 0
    if (n <= 0) {
        return 0;
    }
    // Recursive case: add first element with sum of the rest
    return arr[0] + sumRecursive(arr + 1, n - 1);
}

// Method 2: Recursion with index (more space efficient)
// Time complexity: O(n), Space complexity: O(n) - but less overhead
int sumRecursiveWithIndex(int arr[], int n, int index = 0) {
    // Base case: if we reach the end of array
    if (index >= n) {
        return 0;
    }
    // Recursive case: add current element with sum of the rest
    return arr[index] + sumRecursiveWithIndex(arr, n, index + 1);
}

// Method 3: Tail recursion - OPTIMIZED
// Time complexity: O(n), Space complexity: O(1) - optimized by compiler
int sumTailRecursive(int arr[], int n, int accumulator = 0) {
    // Base case: if no elements, return accumulator
    if (n <= 0) {
        return accumulator;
    }
    // Recursive case: add to accumulator and call recursively
    return sumTailRecursive(arr + 1, n - 1, accumulator + arr[0]);
}

// Method 4: Tail recursion with index
// Time complexity: O(n), Space complexity: O(1) - optimized by compiler
int sumTailRecursiveWithIndex(int arr[], int n, int index = 0, int accumulator = 0) {
    // Base case: if we reach the end of array
    if (index >= n) {
        return accumulator;
    }
    // Recursive case: add to accumulator and call recursively
    return sumTailRecursiveWithIndex(arr, n, index + 1, accumulator + arr[index]);
}

// Method 5: Divide and conquer
// Time complexity: O(n), Space complexity: O(log n) - height of recursion tree
int sumDivideAndConquer(int arr[], int start, int end) {
    // Base case: if only one element
    if (start == end) {
        return arr[start];
    }
    // Base case: if no elements
    if (start > end) {
        return 0;
    }
    
    // Divide array into two halves
    int mid = start + (end - start) / 2;
    
    // Conquer: recursively sum both halves
    return sumDivideAndConquer(arr, start, mid) + sumDivideAndConquer(arr, mid + 1, end);
}

// Helper function for divide and conquer method
int sumDivideAndConquerWrapper(int arr[], int n) {
    return sumDivideAndConquer(arr, 0, n - 1);
}

// Method 6: Iterative (for comparison)
// Time complexity: O(n), Space complexity: O(1)
int sumIterative(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to print array
void printArray(int arr[], int n) {
    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }
    
    int* arr = new int[n];
    
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    printArray(arr, n);
    cout << endl;
    
    // Test all methods
    cout << "Results using different methods:" << endl;
    cout << "=================================" << endl;
    
    cout << "1. Simple recursion: " << sumRecursive(arr, n) << endl;
    cout << "2. Recursion with index: " << sumRecursiveWithIndex(arr, n) << endl;
    cout << "3. Tail recursion: " << sumTailRecursive(arr, n) << endl;
    cout << "4. Tail recursion with index: " << sumTailRecursiveWithIndex(arr, n) << endl;
    cout << "5. Divide and conquer: " << sumDivideAndConquerWrapper(arr, n) << endl;
    cout << "6. Iterative (comparison): " << sumIterative(arr, n) << endl;
    
    cout << "\nComplexity analysis:" << endl;
    cout << "===================" << endl;
    cout << "Method 1-2: Time O(n), Space O(n)" << endl;
    cout << "Method 3-4: Time O(n), Space O(1) - optimized by tail recursion" << endl;
    cout << "Method 5: Time O(n), Space O(log n)" << endl;
    cout << "Method 6: Time O(n), Space O(1)" << endl;
    
    delete[] arr;
    return 0;
} 