#include <iostream>
#include <random>
#include <ctime> 
using namespace std;

enum class SideofCoin {HEADS = 0, TAILS};

SideofCoin flip();

int main() {

    int i{0}, headsCounter{0};
    while(i < 100)
    {
        SideofCoin result = flip();
        cout << "\nToss " << i + 1 << ": " << (int)result;
        if(result == SideofCoin::HEADS)
        {
            headsCounter++;
        }
        
        i++;
    }
    
    cout << "\nNumber of Heads: " << headsCounter << "\nNumber of Tails: " << 100 - headsCounter << endl;
    return 0;
}


SideofCoin flip() // function to flip the coin. Unnessary use of enum. But still good practise on how to use enum.
{
    random_device random_number_generator;
    mt19937 engine2(random_number_generator()); // seed the generator using mersenne twister engine
   
    SideofCoin heads{SideofCoin::HEADS}, tails{SideofCoin::TAILS};
    
        
        SideofCoin side = static_cast<SideofCoin>(engine2() % 2);
        if (side == SideofCoin::HEADS)
        {  
           return heads;
        }
        else
        {
            return tails;    
        }

        cout << endl;

}