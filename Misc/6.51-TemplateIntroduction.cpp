#include <iostream>

template <typename T>

T minimum(T a, T b) 
{
    return (a < b) ? a : b;
}
    
template <typename dataType>
dataType maximum(dataType a, dataType b) 
{
    return (a > b) ? a : b;
}

int main() 
{

    std::cout << "Minimum of 164 and 20008:                 " << minimum(164, 20008) << std::endl;
    std::cout << "Minimum of 5.5543 and 24.3532.5:          " << minimum(5.5543, 24.3532) << std::endl;
    std::cout << "Minimum of '-' and '*':                   " << minimum('-', '*') << std::endl;
    
    std::cout << "Maximum of 164 and 20008:                 " << maximum(164, 20008) << std::endl;
    std::cout << "Maximum of 5.5543 and 24.3532.5:          " << maximum(5.5543, 24.3532) << std::endl;
    std::cout << "Maximum of '-' and '*':                   " << maximum('-', '*') << std::endl;
    
    return 0;
}