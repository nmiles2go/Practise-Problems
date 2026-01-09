#include <iostream>
#include <iomanip>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time
#include <array>

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
    unsigned int myPoint{0};
    Status gameStatus;
    unsigned int sumOfDice{rollDice()};
    int rollCount = 1;  // Track the number of rolls in THIS game
 
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
       sumOfDice = rollDice();
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
        std::cout << i + 1 <<  " Rolls - > " << std::fixed << std::setprecision(2) << 
                                                static_cast<double>(gameWinStatistics[i])/10 <<  " % " << std::endl;
        sum1 +=  gameWinStatistics[i];
    }
    std::cout << "\nLOSS % with number of rolls: \n\n";
    for (size_t i = 0; i < countRolls; i++)
    {
        std::cout << i + 1 <<  " Rolls - > " << std::fixed << std::setprecision(2) <<
                                                static_cast<double>(gameLossStatistics[i])/10 << " % " << std::endl;
        sum2 += gameLossStatistics[i];
    }

    std::cout << "Total Win %: " << sum1/10;
}

// roll dice, calculate sum and display results
unsigned int rollDice() {
   int die1{1 + rand() % 6}; // first die roll
   int die2{1 + rand() % 6}; // second die roll
   int sum{die1 + die2}; // compute sum of die values
   return sum;
}


