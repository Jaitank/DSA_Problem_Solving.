#include <bits/stdc++.h>
using namespace std;

// question link: https://leetcode.com/problems/subsets/

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans)
    {
        // base case
        if (index >= nums.size())
        {   // when we have reached to base case, means now we have our subset, so store them in ans vector
            ans.push_back(output);
            return;
        }
        
        // exclude : when we are not including element
        solve(nums, output, index+1, ans);
         
        // include : when we are including elements
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }
};

int main()
{
    
    return 0;
}