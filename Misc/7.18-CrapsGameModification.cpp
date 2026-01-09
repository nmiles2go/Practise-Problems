#include <iostream>
#include <iomanip>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <array>
#include <random>


using namespace std;

unsigned int rollDice(); // rolls dice, calculates and displays sum

int main() {
   // scoped enumeration with constants that represent the game status 
   enum class Status {CONTINUE, WON, LOST}; // all caps in constants

   size_t countGames {1000};
   const int countRolls {21};

    std::array<int, countRolls> gameWinStatistics = {0}; 
    std::array<int, countRolls> gameLossStatistics = {0}; 

    // gameStatistics[0] - > After 1 roll
    // gameStatistics[1] - > After 2 roll
    // gameStatistics[2] - > After 3 roll
    // gameStatistics[3] - > After 4 roll
    // gameStatistics[4] - > After 5 roll
    // gameStatistics[n] - > After n+1 roll
    // gameStatistics[19] - > After 20 roll
    // gameStatistics[20] - > After 21 roll and above

   // randomize random number generator using current time
   srand(static_cast<unsigned int>(time(0)));

   for (int gameNum = 0; gameNum < countGames; gameNum++)
{
    int rollCount = 1;  // Track the number of rolls in THIS game
    unsigned int myPoint{0};
    Status gameStatus;
    unsigned int sumOfDice{rollDice() + rollDice()};
 
    switch (sumOfDice) {
       case 7:
       case 11:           
          gameStatus = Status::WON;
          ++gameWinStatistics[0];  // Won on roll 1
          break;
       case 2:
       case 3:
       case 12:             
          gameStatus = Status::LOST;
          ++gameLossStatistics[0];  // Lost on roll 1
          break;
       default:
          gameStatus = Status::CONTINUE;
          myPoint = sumOfDice;
          break;
    }
 
    while (Status::CONTINUE == gameStatus) {
       sumOfDice = rollDice() + rollDice();
       ++rollCount;  // Increment roll count for each additional roll
 
       if (sumOfDice == myPoint) { 
          gameStatus = Status::WON;
          int index = (rollCount > 20) ? 20 : rollCount - 1;
          ++gameWinStatistics[index];
       }
       else if (sumOfDice == 7) {
          gameStatus = Status::LOST;
          int index = (rollCount > 20) ? 20 : rollCount - 1;
          ++gameLossStatistics[index];
       }
    }
}

    int sum1 {0};
    int sum2 {0};

   
    std::cout << "\nWINS % with number of rolls: \n\n";
    for (size_t i = 0; i < countRolls; i++)
    {
        std::cout << i + 1 <<  " Rolls - > " << gameWinStatistics[i] << std::endl;
        sum1 +=  gameWinStatistics[i];
    }
    std::cout << "\nLOSS % with number of rolls: \n\n";
    for (size_t i = 0; i < countRolls; i++)
    {
        std::cout << i + 1 <<  " Rolls - > " << gameLossStatistics[i] << std::endl;
        sum2 += gameLossStatistics[i];
    }

    std::cout << "\nTotal Win %: " << sum1/10;
    std::cout << "\nAverage number of rolls per game: " << std::fixed << std::setprecision(2);

    int totalRolesInAGame{0};
    for(int rollIndex = 0; rollIndex < countRolls; rollIndex++)
    {
        totalRolesInAGame += (rollIndex + 1) * (gameLossStatistics[rollIndex] + gameWinStatistics[rollIndex]);
        /* code */
    }
    
    std::cout << static_cast<double>(totalRolesInAGame) / countGames;

}

// roll dice, calculate sum and display results
unsigned int rollDice() 
{
    int sides = 6;
    // Create a random device to seed the generator
    static std::random_device rd;
    
    // Create and seed the Mersenne Twister engine (only once)
    static std::mt19937 gen(rd());
    
    // Create a uniform distribution for the dice
    std::uniform_int_distribution<> distribution(1, sides);
    
    // Generate and return the roll
    return distribution(gen);
}


