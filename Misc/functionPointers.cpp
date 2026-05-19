#include <iostream>
#include <utility> // for std::swap
#include <functional> // for std::function

int foo()
{
    return 1;
}

int foo1(int x)
{
    return x;
}



int goo()
{
    return 2;
}

// Callback Functions
bool ascending(int x, int y);
bool descending(int x, int y);
bool evensFirst(int x, int y);

// Making Function pointers pretty
using ValidateFunctionRaw = bool(*)(int, int);
using ValidateFunction = std::function<bool(int,int)>;

// Note our user-defined comparison is the third parameter
// 1. void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int) = ascending) // Default parameter for comparison function
// 2. We can also write
//void selectionSort(int* array, int size, ValidateFunctionRaw comparisonFcn = ascending) // The syntax for function pointer is much clear now.
// 3. Using std::function. NOTE: std::function only allows calling the function via implicit dereference (e.g. fcnPtr()), not explicit dereference (e.g. (*fcnPtr)()).

void selectionSort(int* array, int size, ValidateFunction comparisonFcn = ascending)

{
    if (!array || !comparisonFcn)
        return;

    // Step through each element of the array
    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex{ startIndex };

        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
            {
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

// Here is a comparison function that sorts in ascending order
// (Note: it's exactly the same as the previous ascending() function)
bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y; // swap if the second element is greater than the first
}

bool evensFirst(int x, int y)
{
	// if x is even and y is odd, x goes first (no swap needed)
	if ((x % 2 == 0) && !(y % 2 == 0))
		return false;

	// if x is odd and y is even, y goes first (swap needed)
	if (!(x % 2 == 0) && (y % 2 == 0))
		return true;

        // otherwise sort in ascending order
	return ascending(x, y);
}

// This function prints out the values in the array
void printArray(int* array, int size)
{
    if (!array)
        return;

    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    
    // int (*fcnPtr)(){ &foo }; // fcnPtr points to function foo
    // std::cout << fcnPtr() << " ";

    // fcnPtr = &goo; // fcnPtr now points to function goo
    // std::cout << fcnPtr()<< " ";
    
    
    // int (*fcnPtr1)(int){ &foo1 }; // Initialize fcnPtr with function foo
    // std::cout << (*fcnPtr1)(3) << " "; // call function foo(5) through fcnPtr1 through explicit deference

    // std::cout << fcnPtr1(4); // call function foo(5) through fcnPtr1 through implicit deference

    // if (fcnPtr1) // make sure fcnPtr isn't a null pointer
    //     std::cout << fcnPtr1(5) << " ";  // otherwise this will lead to undefined behavior
    
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
    printArray(array, 9);

    // Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    printArray(array, 9);

    // Sort the array in ascending order using the evensFirst() function
    selectionSort(array, 9, evensFirst);
    printArray(array, 9);

    selectionSort(array, 9);// No comparison function explicit, so defaulted to ascending.
    printArray(array,9);
    
    return 0;
}


