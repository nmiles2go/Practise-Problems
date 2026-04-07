#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int k = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
    }
};

int main()
{

    Solution SOLUTION;

    vector<int> vec1 = {0,0,1,1,1,2,2,3,3,4};

    std::cout << SOLUTION.removeDuplicates(vec1);
    return 0;
}