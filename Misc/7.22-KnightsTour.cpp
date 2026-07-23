#include <array>
#include <iostream>
#include <iomanip>
#include <random>

using std::array;

//#define PART1
#define PART2
//#define PART3


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

void KnightsTourRandomWalk()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDist(0,7);
    
    const int rows {8};
    const int columns {8};
    const int moves {8};
    
    const int numSquaresChessBoard {rows*columns};
    
    array<array<int, columns>, rows> chessBoard {0}; 

    array<int, moves> horizontalMoves   {2,1,-1,-2,-2,-1,1,2};
    array<int, moves> verticalMoves     {-1,-2,-2,-1,1,2,2,1};

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

    int moveNumber {0};
    int currentRow {0};
    int currentColumn {0};

    chessBoard[currentRow][currentColumn] = 1;

    for (size_t move = 2; move <= numSquaresChessBoard; move++)
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

void KnightsTourHEURISTIC()
{
    array<array<int, 8>, 8> chessBoard {0}; 
    
    int currentRow{0};
    int currentColumn{0};
    int totalMoves{1};
    
    const array<int, 8> h{ 2,  1, -1, -2, -2, -1,  1,  2};
    const array<int, 8> v{-1, -2, -2, -1,  1,  2,  2,  1};

    // Accessibility heuristic: how many squares can reach each square.
    array<array<int, 8>, 8> accessibility =
        {{{2, 3, 4, 4, 4, 4, 3, 2},
          {3, 4, 6, 6, 6, 6, 4, 3},
          {4, 6, 8, 8, 8, 8, 6, 4},
          {4, 6, 8, 8, 8, 8, 6, 4},
          {4, 6, 8, 8, 8, 8, 6, 4},
          {4, 6, 8, 8, 8, 8, 6, 4},
          {3, 4, 6, 6, 6, 6, 4, 3},
          {2, 3, 4, 4, 4, 4, 3, 2}}};

    chessBoard.at(currentRow).at(currentColumn) = totalMoves;

    
    
    // Accesibility HEURISTIC for Knight's Tour
    
    // We solve this problem using a HEURISTIC. 
    // A heuristic does not ensure success. But....
    // A carefully developed heuristic improves the chance of it.
    
    // HEURISTIC DEVELOPMENT
    
    // We notice that the corner squares are probably the most difficlult to work with.
    // When we do not start from anywhere else ompared to the corners, the corners are difficult
    // to fill up.  
    
    // We can develop an "Accessibility Heuristic". 
    //      1) Classify each square according to how accessible it is.
    //      2) Always moving the Knight to the square that is least accessible.
    
    // This is the chessboard with its accessibility values indicated.

    // R/C     0   1   2   3   4   5   6   7  

    // 0     | 2 | 3 | 4 | 4 | 4 | 4 | 3 | 2 |
    // 1     | 3 | 4 | 6 | 6 | 6 | 6 | 4 | 3 |
    // 2     | 4 | 6 | 8 | 8 | 8 | 8 | 6 | 4 |           
    // 3     | 4 | 6 | 8 | 8 | 8 | 8 | 6 | 4 |        
    // 4     | 4 | 6 | 8 | 8 | 8 | 8 | 6 | 4 |
    // 5     | 4 | 6 | 8 | 8 | 8 | 8 | 6 | 4 |
    // 6     | 3 | 4 | 6 | 6 | 6 | 6 | 4 | 3 |
    // 7     | 2 | 3 | 4 | 4 | 4 | 4 | 3 | 2 |

    // At any time, the Knight should move to the lowest accesibility square.

    
    do
    {
        int bestMove{-1};
        int lowestAccessibility{9};   // every real value is 8 or less

        // Find the legal move whose destination is hardest to reach
        for (int moveCounter = 0; moveCounter < 8; ++moveCounter)
        {
            int tempRow    = currentRow + v[moveCounter];
            int tempColumn = currentColumn + h[moveCounter];

            if (tempRow >= 0 && tempRow < 8
                && tempColumn >= 0 && tempColumn < 8
                && chessBoard.at(tempRow).at(tempColumn) == 0
                && accessibility.at(tempRow).at(tempColumn) < lowestAccessibility)
            {
                lowestAccessibility = accessibility.at(tempRow).at(tempColumn);
                bestMove = moveCounter;
            }
        }

        if (bestMove == -1) break;   // dead end

        currentRow    += v[bestMove];
        currentColumn += h[bestMove];

        ++totalMoves;
        chessBoard.at(currentRow).at(currentColumn) = totalMoves;

        // The square we just occupied can no longer be reached, so every
        // square that could jump to it loses one unit of accessibility.
        for (int moveCounter = 0; moveCounter < 8; ++moveCounter)
        {
            int tempRow    = currentRow + v[moveCounter];
            int tempColumn = currentColumn + h[moveCounter];

            if (tempRow >= 0 && tempRow < 8
                && tempColumn >= 0 && tempColumn < 8)
            {
                --accessibility.at(tempRow).at(tempColumn);
            }
        }
    }
    while (totalMoves < 64);

    std::cout << "Squares visited: " << totalMoves << "\n\n";

    PrintKnightsTour(chessBoard);
}

int main()
{
    #ifdef PART1
        KnightsTourRandomWalk();
    #endif

    #ifdef PART2
        KnightsTourHEURISTIC();
    #endif
    
    return 0;
}

