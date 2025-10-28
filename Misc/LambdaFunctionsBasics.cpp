#include <iostream>
#include <vector>
#include <algorithm>

// Understanding Lambda Functions in C++
// A lambda function is an anonymous function that can be defined in-line.
// It can capture variables from its surrounding scope and can be used
// as a concise way to define small functions.

// Lambda function in simple terms:
// A lambda function is like a mini function that you can create right where you need it.
// It can use variables from outside its own body without needing to pass them as parameters.
// This makes your code cleaner and easier to read, especially for short operations.
// You can think of it as a quick way to define a function without giving it a name.

// Basic Syntax of a Lambda Function:
// [capture](parameters) -> return_type { body }
// - capture: Specifies which variables from the surrounding scope are accessible.
// - parameters: The input parameters for the lambda function.
// - return_type: (optional) The type of value returned by the lambda.
// - body: The code that defines what the lambda function does.

int main()
{
    // Example of a simple lambda function that prints "Hello, World!"
    // Define the lambda function
    auto greet = []() 
    {
        std::cout << "Hello, World!" << std::endl;
    };
    // Call the lambda function
    greet();

    // Example of a lambda function that takes parameters and returns a value
    auto add = [](int a, int b) -> int 
    {
        return a + b;
    };
    int sum = add(5, 3);
    std::cout << "Sum: " << sum << std::endl;

    // Example of a lambda function that captures variables from the surrounding scope
    int x = 10;
    int y = 20;
    auto multiply = [x, y]() -> int 
    {
        return x * y;
    };
    int product = multiply();
    std::cout << "Product: " << product << std::endl;
    

    
    // Example of a lambda function that modifies a captured variable by reference
    int counter = 0;
    auto increment = [&counter]() 
    {
        counter++;
    };
    increment();
    std::cout << "Counter: " << counter << std::endl;

    // Example of using a lambda function with the standard library (e.g., sorting a vector)
    std::vector<int> numbers = {5, 2, 8, 1, 4};
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) 
    {
        return a > b; // Sort in ascending order
    });

    std::cout << "Sorted numbers: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    std::for_each(v.begin(), v.end(),  [](int x){if (x % 2 == 0) std::cout << "Even\n"; 
        else 
            std::cout << "Odd\n" ;} );

    

    return 0;   
}