#include <iostream>
#include <iomanip>
#include <array>
#include <random>



int rollDice(int sides = 6) {
    // Create a random device to seed the generator
    static std::random_device rd;
    
    // Create and seed the Mersenne Twister engine (only once)
    static std::mt19937 gen(rd());
    
    // Create a uniform distribution for the dice
    std::uniform_int_distribution<> distribution(1, sides);
    
    // Generate and return the roll
    return distribution(gen);
}

int main()
{
    const int NUM_SUM {11}; 

    //Index 0 -> counter for 2
    //Index 1 -> counter for 3
    //Index 2 -> counter for 4
    //Index 3 -> counter for 5
    //Index 4 -> counter for 6
    //Index 5 -> counter for 7
    //Index 6 -> counter for 8
    //Index 7 -> counter for 9
    //Index 8 -> counter for 10
    //Index 9 -> counter for 11
    //Index 10 -> counter for 12

    const int NUM_ROLLS {36'000'000};

    // Simulation of 2 dice rolls 
    std::array<int, NUM_SUM> sumCounts {};

    for (size_t rolls = 0; rolls < NUM_ROLLS; rolls++)
    { 
        int sum = rollDice() + rollDice();
        ++sumCounts[sum - 2];
        
    }
    
    // Display results with percentages
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < NUM_SUM; ++i)
    {
        double percentage = (sumCounts[i] * 100.0) / NUM_ROLLS;
        std::cout << "Sum " << std::setw(2) << (i + 2) << ": " 
                  << std::setw(10) << sumCounts[i] 
                  << " (" << std::setw(5) << percentage << "%)\n";
    }


    
    return 0;
}