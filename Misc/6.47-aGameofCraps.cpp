// Modified craps game
// Uses Mersenne Twister random number generator
// Uses enum class for game status

#include <iostream>
#include <random>

enum class      Status          {CONTINUE, WON, LOST};  // all caps in constants
Status          CrapsGame       (std::mt19937 &engine); // One game of craps
void            Instructions    ();                     // display game instructions
unsigned int    rollDice        (std::mt19937 &engine);        // rolls dice, calculates and displays sum


int main() 
{   
    std::mt19937 engine {std::random_device{}()}; // Mersenne Twister engine seeded with random device
    
    int bankBalance {0b1111101000}; // initial bank balance in binary. Enjoy.
    int wager       {0b0};          // initial wager amount in binary. Enjoy.   
    
    std::cout << "Welcome to the game of Craps!\n\n";
    Instructions();
    
    char playAgain  {'y'};
    while ('y' == playAgain || 'Y' == playAgain)
    {
        std::cout<< "Enter your wager amount: $ ";
        std::cin >> wager;

        while(wager <= 0 || wager > bankBalance )
        {
            std::cout<< "\nInvalid wager amount. Please enter a valid amount: $";
            std::cin >> wager;
        }

        std::cout<< "\nYour initial bank balance is $" << bankBalance << "\nYour wager amount is: $ " << wager << '\n';

        if(bankBalance)
        {
            bankBalance -= wager;
            std::cout<< "Your new bank balance is: $ " << bankBalance << '\n';
            if(CrapsGame(engine) == Status::WON)
            {
                bankBalance += 2 * wager;
                std::cout<< "Your new bank balance is: $ " << bankBalance << '\n';
            }
            else
            {
                std::cout<< "Your new bank balance is: $ " << bankBalance << '\n';
            }

        }

        if(bankBalance > 0)
        {
            std::cout << "\n\nWould you like to play again? (y/n): ";
            std::cin  >> std::ws >> playAgain; // eat up any leading whitespace

            if('n' == playAgain || 'N' == playAgain)
            {
                std::cout<< "\nThank you for playing! You are leaving with $ " << bankBalance << '\n' << "Goodbye!\n";
            }

            if(false == std::isalpha(static_cast<unsigned char>(playAgain)))
            {
                std::cout<< "\nInvalid input. Exiting game. You are leaving with $ " << bankBalance << '\n' << "Goodbye!\n";
                return 0;
            }

        }
        
        else
        {
            std::cout << "You are out of money! Game over!\n";
            playAgain = 'n';
            return 0;
        }
    }
}

// roll dice, calculate sum and display results
unsigned int rollDice(std::mt19937 &engine) 
{
    
    std::uniform_int_distribution<int> distribution(1,6); // uniform distribution between 1 and 6
    
    int die1{distribution(engine)}; // first die roll
    int die2{distribution(engine)}; // second die roll
    
    // display results of this roll
    std::cout<< "\n\nPlayer rolled " << die1 << " + " << die2 << " = " << die1 + die2 << "\n";
         
    return die1 + die2; // return sum of dice
}

Status CrapsGame(std::mt19937 &engine)
{
    unsigned int myPoint{0};
    unsigned int sumOfDice{rollDice(engine)}; // point if no win or loss on first roll
    Status gameStatus; // can be CONTINUE, WON or LOST

    // determine game status and point (if needed) based on first roll
    switch (sumOfDice) 
    {
        case 7: // win with 7 on first roll
        case 11: // win with 11 on first roll           
            gameStatus = Status::WON;
            break;
        case 2: // lose with 2 on first roll
        case 3: // lose with 3 on first roll
        case 12: // lose with 12 on first roll             
            gameStatus = Status::LOST;
            break;
        default: // did not win or lose, so remember point
            gameStatus = Status::CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            std::cout<< "\n\nPoint is " << myPoint <<"\n";
            break; // optional at end of switch  
    }

    // while game is not complete
    while (Status::CONTINUE == gameStatus) 
    { 
        // not WON or LOST
        sumOfDice = rollDice(engine); // roll dice again

        // determine game status
        if (sumOfDice == myPoint) 
        {  
            // win by making point
            gameStatus = Status::WON;
            
        }
        else 
        {
            if (sumOfDice == 7) 
            { 
                // lose by rolling 7 before point
                gameStatus = Status::LOST;
            }
        }

    }

    return gameStatus;
}

void Instructions()
{
    std::cout<< "Instructions: \n\n ";
    std::cout<< "A player rolls two dice. On the first roll, a 7 or 11 wins, \n" 
         << "a 2, 3 or 12 loses, and any other roll establishes a point. \n"
         << "To win, you must continue rolling the dice until you re-roll \n"
         << "your point. You lose by rolling a 7 before making your point.\n\n\n"
         << "Good luck!\n\n";
}
