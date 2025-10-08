#include <iostream>

void TowerofHanoi(int numTiles, char A, char B, char C)
{
    if(numTiles > 0)
    {
        TowerofHanoi(numTiles-1, A, C, B);
        std::cout <<"Move from " << "( " << A << " )" << " to " << "( " <<B << " )\n";
        TowerofHanoi(numTiles-1, B, C, A);
    }
}
int main()
{

    TowerofHanoi(4, 'a', 'b', 'c');

    return 0;
}