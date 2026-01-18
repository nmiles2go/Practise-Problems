#include <array>
#include <iostream>
#include <iomanip>
#include <random>

using std::array;

int main()
{
    const int rows {8};
    const int columns {8};
    const int moves {8};
    const int numSquaresOnChessBoard {64};
    
    array<array<int, columns>, rows> chessBoard {0}; 

    array<int, moves> horizontalMoves   {2,1,-1,-2,-2,-1,1,2};
    array<int, moves> verticalMoves     {-1,-2,-2,-1,1,2,2,1};

   

    int moveNumber;

    // To select a random move number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDist(0,7);

    // R/C    0   1   2   3   4   5   6   7  
    // 0    |   |   |   |   |   |   |   |   |
    // 1    |   |   |   | 2 |   | 1 |   |   |
    // 2    |   |   | 3 |   |   |   | 0 |   |           
    // 3    |   |   |   |   | N |   |   |   |        
    // 4    |   |   | 4 |   |   |   | 7 |   |
    // 5    |   |   |   | 5 |   | 6 |   |   |
    // 6    |   |   |   |   |   |   |   |   |
    // 7    |   |   |   |   |   |   |   |   |


    // For Knight to move to position 0, it has to:
    // 1. move 2 steps horizontally
    // 2. move 1 step vertically
    
    // The horizontalMoves array corresponds to this:
    // horizontalMoves[0] = 2, which corresponds to 2 steps in the right. (+2 as a number)
    // horizontalMoves[4] = -2, which corresponds to 2 steps to the left. (-2 as a number)

    // Similarly, for the array of verticalMoves,
    // verticalMoves[1] = -2, which means that knight moves 2 positions up.
    // verticalMoves[5] = 2, which means that knight moves 2 positions down.

    int currentRow {0};
    int currentColumn {4};

    for (size_t move = 1; move <= 64; move++)
    {
        // generating a moveNumber for the knight (from 0 to 7)
        moveNumber = valueDist(gen); 

        array<int, moves> testedMoves {-1,-1,-1,-1,-1,-1,-1,-1};
        
        if(move == 1)
        {
            // First we have to store the value 1 in the current location of the Knight before starting the tour
            chessBoard[currentRow][currentColumn] = move;
        }
        // After storing the begin location, we want to check available squares out knight can move to
        else
        {
            bool validMoveFound = false;
            int attempts = 0;

            do
            {
                if(testedMoves.at(moveNumber) == -1)
                {
                    testedMoves[moveNumber] = moveNumber;
                    attempts++;
                    
                    int tempRow = verticalMoves[moveNumber] + currentRow;
                    int tempColumn = horizontalMoves[moveNumber] + currentColumn;
                    
                    if(tempRow >= 0 && tempColumn >= 0 && tempRow < 8 && tempColumn < 8)
                    {
                        if(chessBoard[tempRow][tempColumn] == 0)
                        {
                            currentRow = tempRow;
                            currentColumn = tempColumn;
                            chessBoard[currentRow][currentColumn] = move;
                            validMoveFound = true;
                        }
                    }
                }
                
                
                moveNumber = valueDist(gen); // Generate new move number
            }
            while(!validMoveFound && attempts < 8);
        }

    }

// Print the chess board
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cout << std::setw(3) << chessBoard[i][j] << " ";
        }
        
        std::cout << std::endl;
    }
    return 0;
}
