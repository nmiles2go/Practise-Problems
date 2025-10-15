// Modified craps game

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <random>
using namespace std;

enum class Status {CONTINUE , WON , LOST }; // all caps in constants
Status CrapsGame(); // One game of craps
void Instructions(); // display game instructions
unsigned int rollDice(); // rolls dice, calculates and displays sum


int main() 
{
    // randomize random number generator using current time
    srand(static_cast<unsigned int>(time(0)));
    
    int bankBalance {0b1111101000}; // initial bank balance in binary. Enjoy.
    int wager       {0b0};          // initial wager amount in binary. Enjoy.   
    char playAgain  {'y'};

    cout << "Welcome to the game of Craps!\n\n";
    Instructions();
     
    while ('y' == playAgain || 'Y' == playAgain)
    {
        cout << "Enter your wager amount: $ ";
        cin >> wager;


        bool isValidWager = (wager < 0 || wager > bankBalance);

        while(isValidWager)
        {
            cout << "\nInvalid wager amount. Please enter a valid amount: $";
            cin >> wager;
        }
        

        cout << "\nYour initial bank balance is $" << bankBalance << "\nYour wager amount is: $ " << wager << '\n';

        if(bankBalance)
        {
            bankBalance -= wager;
            cout << "Your new bank balance is: $ " << bankBalance << '\n';
            if(CrapsGame() == Status::WON)
            {
                bankBalance += 2 * wager;
                cout << "Your new bank balance is: $ " << bankBalance << '\n';
            }
            else
            {
                cout << "Your new bank balance is: $ " << bankBalance << '\n';
            }

        }

        if(bankBalance > 0)
        {
            std::cout << "Would you like to play again? (y/n): ";
            cin >> std::ws >> playAgain; // eat up any leading whitespace

        }

        else
        {
            std::cout << "You are out of money! Game over!\n";
            playAgain = 'n';
        }

    }
    return 0;
}

// roll dice, calculate sum and display results
unsigned int rollDice() 
{
    std::mt19937 engine {std::random_device{}()}; // Mersenne Twister engine seeded with rd()
    std::uniform_int_distribution<int> distribution(1,6);

    
    int die1{distribution(engine)}; // first die roll
    int die2{distribution(engine)}; // second die roll
    int sum{die1 + die2}; // compute sum of die values

    // display results of this roll
    cout << "Player rolled " << die1 << " + " << die2
         << " = " << sum << endl;
    return sum;
}

Status CrapsGame()
{
    unsigned int myPoint{0};
    unsigned int sumOfDice{rollDice()}; // point if no win or loss on first roll
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
            cout << "Point is " << myPoint << endl;
            break; // optional at end of switch  
    }

    // while game is not complete
    while (Status::CONTINUE == gameStatus) 
    { 
        // not WON or LOST
        sumOfDice = rollDice(); // roll dice again

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

    // display won or lost message
    if (Status::WON == gameStatus) 
    {
        cout << "Player wins" << endl;
        return Status::WON;
    }
    else 
    {
        cout << "Player loses" << endl;
        return Status::LOST;
    }
}

void Instructions()
{
    cout << "Instructions: \n\n\n\n " << endl;
    cout << "A player rolls two dice. On the first roll, a 7 or 11 wins, \n" 
         << "a 2, 3 or 12 loses, and any other roll establishes a point. \n"
         << "To win, you must continue rolling the dice until you re-roll \n"
         << "your point. You lose by rolling a 7 before making your point.\n\n\n"
         << "Good luck!\n\n\n\n";
}
