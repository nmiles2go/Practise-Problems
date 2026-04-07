#include<vector>
#include <iostream>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for (int i = m+n-1, a = m-1, b = n-1; b>=0; i--) 
        {
            if (a >= 0 && nums1[a] > nums2[b]) 
            {
                nums1[i] = nums1[a]; 
                a--;
            }
		    else 
            {
                nums1[i] = nums2[b];
                b--;
            }
    }
    }
};

int main()
{
    Solution SOLUTION1;

    vector<int> vec1 = {1,2,3,0,0,0};
    vector<int> vec2 = {2,5,6};

    
    SOLUTION1.merge(vec1, 3, vec2, 3);

    for (auto i : vec1)
    {
        std::cout << i << ", ";
    }
    
    return 0;

}
