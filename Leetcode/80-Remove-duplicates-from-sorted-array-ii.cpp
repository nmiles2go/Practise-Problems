#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int k = nums.size();
    if(k<2)
    {
        return k;
    } 
    int j = 2;
    for (int i = 2; i < k; i++) {
        if (nums[i] != nums[j - 2]) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}
};

int main()
{

    Solution SOLUTION;

    vector<int> vec1 = {0,0,1,1,1,1,2,3,3};

    std::cout << SOLUTION.removeDuplicates(vec1);
    return 0;
}