#include <iostream>

int main() 
{
    // What is the difference between enum and enum class in C++?
    // Enum class provides better scoping and prevents name clashes.
    // Enum class also requires explicit casting to int if needed.
    // Enum class is generally preferred for better type safety.

    // Example usage of enum class
    enum class Color 
    {
        RED,
        GREEN,
        BLUE
    };
    Color myColor = Color::GREEN;

    // Example usage of enum
    enum Shape 
    {
        CIRCLE,
        SQUARE,
        TRIANGLE
    };
    Shape myShape = SQUARE;

    // Demonstrating the difference
    if (myColor == Color::GREEN) 
    {
        std::cout << "The color is green." << std::endl;
    }

    if (myShape == SQUARE) 
    {
        std::cout << "The shape is square." << std::endl;
    }

    // The following line would cause a compilation error due to type safety
    // if (myColor == myShape) {}
    // Uncommenting the above line will result in an error

    // To convert enum class to int
    int colorValue = static_cast<int>(myColor);
    std::cout << "Color value as int: " << colorValue << std::endl;

    // To convert enum to int
    int shapeValue = myShape; // Implicit conversion

    // Output the shape value
    std::cout << "Shape value as int: " << shapeValue << std::endl;

    // Conclusion: Use enum class for better type safety and scoping.

    // Use enum when backward compatibility or implicit conversions are needed.
    // Use enum class for new code to avoid name clashes and improve type safety.

    // End of demonstration
    return 0;
}