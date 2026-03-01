// 🎰 Slot Machine
// Store symbols in an array (string symbols[] = {"🍒", "🍋", "⭐", "7"}), randomly pick 3 each spin, and check for matches with a loop. 
// Simple, satisfying, and great for arrays + random number generation.

#include <format>
#include <array>
#include <iostream>
#include <random>
using std::array;

const uint8_t NUM_ELEMENTS {4};
const uint8_t SLOTS {3};

array<std::string, NUM_ELEMENTS> symbols =  {"🍒", "🍋", "⭐", "❌"};
array<std::string, SLOTS> slotMachineDisplay {"🍒", "🍋", "⭐"};

int numberGenerator() 
{
    // Create a random device to seed the generator
    static std::random_device rd;
    
    // Create and seed the Mersenne Twister engine (only once)
    static std::mt19937 gen(rd());
    
    // Create a uniform distribution for the dice
    std::uniform_int_distribution<> distribution(0,SLOTS);
    
    // Generate and return the roll
    return distribution(gen);
}

void slotMachine()
{
    for (std::string &i : slotMachineDisplay)
    {
        int index = numberGenerator();
        i = symbols[index];
        
    }
    
}

int main()
{
    for (size_t j = 0; j < 10; j++)
    {
        slotMachine();
        for (std::string i : slotMachineDisplay)
        {
            std::cout << i;
        }

        std::cout <<std::endl;
        /* code */
    }
    
    return 0;
}