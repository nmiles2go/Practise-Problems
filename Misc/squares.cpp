#include <iostream>

void SquareOfAsterisks(int);
void SquareOfAnyCharacter(int ,char);

int main()
{
    int side{0};
    char randomChar{'a'};
    std::cout << "Enter the number of side of the square: ";
    std::cin >> side >> randomChar;
    SquareOfAsterisks(side);

    SquareOfAnyCharacter(side, randomChar);
    return 0;
}

void SquareOfAsterisks(int side)
{
    for (int row{1}; row <= side; row++)
    {
        for(int column{1}; column <= side; column++)
        {
            std::cout << '*';
        }

        std::cout << std::endl;
    }
}

void SquareOfAnyCharacter(int side, char randomChar)
{
    for (int row{1}; row <= side; row++)
    {
        for(int column{1}; column <= side; column++)
        {
            std::cout << randomChar;
        }

        std::cout << std::endl;
    }
}