// 🎯 Number Guessing Game (between 0 and 65535)
// The computer picks a random number, and the player guesses until they get it. 
// Use a while loop for repeated guessing and track the number of attempts in a variable. 
// Simple but great for loops and conditionals.

#include <format>
#include <iostream>
#include <random>

unsigned short numberGenerator() 
{
    // Create a random device to seed the generator
    static std::random_device rd;
    
    // Create and seed the Mersenne Twister engine (only once)
    static std::mt19937 gen(rd());
    
    // Create a uniform distribution for the dice
    std::uniform_int_distribution<> distribution(0,USHRT_MAX);
    
    // Generate and return the roll
    return distribution(gen);
}

int main()
{

    unsigned short randomNum = numberGenerator();
    unsigned short guess;
    
    std::cout << "Lets play Guess the Number Game!\n";

    do
    {
        std::cout << "Enter your guess! : ";
        std::cin >> guess;
    } while (randomNum != guess);

    std::cout << "You got it! correct number is " << randomNum << " !\n" ;
    
    return 0;
}
