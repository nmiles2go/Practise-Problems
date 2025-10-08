#include <iostream>
#include <random>
#include <ctime> 
using namespace std;

int GenerateRandomNumber();
void GuessTheNumberGame();

int main() {

    GuessTheNumberGame();
    
    return 0;
}

int GenerateRandomNumber()
{
    random_device random_number_generator;
    mt19937 engine(random_number_generator()); // seed the generator using mersenne twister engine
    
    return engine() % 1000 + 1; // generates a number between 1 and 100
    
}

void GuessTheNumberGame()
{
    int random_number = GenerateRandomNumber();
    char choice = 'y';
    bool continueGame = ('y' == choice || 'Y' == choice);
    int numGuesses{0};

    cout << "Welcome to the Guess The Number Game!\n";

    do
    {
        int user_guess;
        cout << "Enter your guess (between 1 and 1000): ";
        cin >> user_guess;

        if (user_guess < random_number) {
            cout << "Too low! Try again.\n";
        } else if (user_guess > random_number) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the number " << random_number << " correctly!\n";
            cout << "Do you want to play again? (y/n): ";
            cin >> choice;

            if(continueGame)
            {
                random_number = GenerateRandomNumber(); // generate a new number for the next game

            }

           if ('n' == choice || 'N' == choice)
           {
               continueGame = false;
            }
            
            
        }
        ++numGuesses;
        
    } while (continueGame);
    
    if (numGuesses > 10)
    {
        cout << "You should be able to do better! \n";
    }
    
    else  
    {
        if (numGuesses == 10)
        {
            cout << "Aha! You know the secret!\n";
        }
        else
        {
            cout << "Either you know the secret or you are just lucky!\n";
        }
        
    }
    
    cout << "Thank you for playing! Goodbye!\n";

}