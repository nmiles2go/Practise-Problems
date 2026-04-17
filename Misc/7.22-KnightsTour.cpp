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
            std::cout << val << "\t";
        }
        std::cout << '\n';
    }
}

void KnightsTour()
{
    const int rows {8};
    const int columns {8};
    const int moves {8};
    const int numSquaresOnChessBoard {64};
    
    array<array<int, columns>, rows> chessBoard {0}; 

    array<int, moves> horizontalMoves   {2,1,-1,-2,-2,-1,1,2};
    array<int, moves> verticalMoves     {-1,-2,-2,-1,1,2,2,1};

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

    int moveNumber;
    int currentRow {0};
    int currentColumn {4};

    chessBoard[currentRow][currentColumn] = 1;

    for (size_t move = 2; move <= numSquaresOnChessBoard; move++)
    {
        moveNumber = valueDist(gen); 

        array<int, moves> triedMoves {-1,-1,-1,-1,-1,-1,-1,-1};
    
        bool validMoveFound = false;
        int testedCount = 0;

        while (!validMoveFound && testedCount < moves) 
        {
            if (triedMoves[moveNumber] != -1) 
            {
                moveNumber = (moveNumber + 1) % moves;
                continue;
            }

            triedMoves[moveNumber] = moveNumber;
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
            else
            {
                moveNumber = (moveNumber + 1) % moves; 
            }        
        }

        if (!validMoveFound) 
        {
            std::cout << "Tour stops at move " << move - 1 << std::endl;
            break;
        }
    }
    
    PrintKnightsTour(chessBoard);
}

int main()
{
    KnightsTour();
    return 0;
}

