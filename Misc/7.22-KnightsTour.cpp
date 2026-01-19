#include <array>
#include <iostream>
#include <iomanip>
#include <random>

using std::array;

bool isValidMove(int row, int column, const auto& board) 
{
    return row >= 0 && row < 8 && column >= 0 && column < 8 &&  board[row][column] == 0;
}

void PrintKnightsTour(const auto& board)
{
   for (const auto& row : board) 
   {
        for (int val : row) 
        {
            std::cout << std::setw(3) << val << " ";
        }
        std::cout << '\n';
    }
}
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

    // To track Knights Position.
    int currentRow {0};
    int currentColumn {4};

    // First we have to store the value 1 in the current location of the Knight before starting the tour
    chessBoard[currentRow][currentColumn] = 1;

    for (size_t move = 2; move <= numSquaresOnChessBoard; move++)
    {
        // Generating a random move for the knight (from 0 to 7)
        moveNumber = valueDist(gen); 

        array<int, moves> testedMoves {-1,-1,-1,-1,-1,-1,-1,-1};
    
        // After storing the begin location, we want to check available squares out knight can move to
        bool validMoveFound = false;
        int testedCount = 0;

        while (!validMoveFound && testedCount < 8) 
        {
            if (testedMoves[moveNumber] == -1) 
            {
                testedMoves[moveNumber] = moveNumber;
                testedCount++;
                
                int tempRow = currentRow + verticalMoves[moveNumber];
                int tempColumn = currentColumn + horizontalMoves[moveNumber];
                
                if (isValidMove(tempRow, tempColumn, chessBoard)) 
                {
                    currentRow = tempRow;
                    currentColumn = tempColumn;
                    chessBoard[currentRow][currentColumn] = move;
                    validMoveFound = true;
                }
                    
            }
            
            if (!validMoveFound && testedCount < 8) 
            {
                moveNumber = valueDist(gen);
            }
        }
            
        // Handle failure case
        if (!validMoveFound) 
        {
            std::cout << "Tour failed at move " << move - 1 << std::endl;
            break;
        }
        
    }
    
    // Print the chess board with Knight's Tour
    PrintKnightsTour(chessBoard);
    return 0;
}

