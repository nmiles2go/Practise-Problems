#include <iostream>

// Tower of Hanoi using Recursion

void TowerOfHanoi_WithRecursion(int n, char start, char end, char aux)
{
    if (n > 0)
    {
        TowerOfHanoi_WithRecursion(n - 1, start, aux, end);
        std::cout << "Move disk " << n << " from " << start << " to " << end << std::endl;
        TowerOfHanoi_WithRecursion(n - 1, aux, end, start);
    }
}

// The Iterative Algorithm: A Deep Dive
// The key insight for developing an iterative solution is recognizing patterns in the sequence of moves. After careful analysis, we can observe that:

// The total number of moves is always 2^n – 1
// There‘s a pattern based on the move number modulo 3 that determines which rods to move between
// The direction of optimal moves depends on whether n is odd or even


// The Core Algorithm
// Here‘s the step-by-step iterative algorithm:

// Calculate total moves: 2^n – 1
// If n is even, swap the auxiliary and destination poles
// For each move from 1 to total moves:
// If move % 3 == 1: Move between source and destination
// If move % 3 == 2: Move between source and auxiliary
// If move % 3 == 0: Move between auxiliary and destination
// For each move, always move the smaller disk onto the larger disk or empty rod


// Understanding the Modulo-3 Pattern
// This pattern ensures we always make a valid move. Let‘s understand why:

// Every third move involves the auxiliary and destination rods
// The moves in between alternate between source-destination and source-auxiliary
// This pattern guarantees we never violate the rules of the puzzle
// The beauty of this approach is that we don‘t need to explicitly track which disk is on which rod—we only need to know the current state of each rod and follow the pattern.
void TowerOfHanoi_WithIteration(int n, char start, char end, char aux)
{
    int total_moves = (1 << n) - 1; // Total moves = 2^n - 1
    for (int i = 1; i <= total_moves; i++)
    {
        int from_rod = (i & i - 1) % 3;
        int to_rod = ((i | i - 1) + 1) % 3;
        std::cout << "Move disk from rod " << from_rod << " to rod " << to_rod << std::endl;
    
    }
}

int main()
{
    int n = 4; // Number of disks
    TowerOfHanoi_WithIteration(n, 'A', 'C', 'B'); // A, B and C are names of rods
    TowerOfHanoi_WithRecursion(n, 'A', 'C', 'B');
    return 0;
}
