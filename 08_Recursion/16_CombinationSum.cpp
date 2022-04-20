// question link: https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

// We have to either involve an element or not - and go further

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &candidates, int target, vector<int>&Sol)
    {
        // if target reduced to 0 means this is one solution, so push and return
        if(target == 0)
        {
            ans.push_back(Sol);
            return;
        }
        if(target < 0) // if target reduced to less than zero means that is not sol combination sum
            return;
        if(i == candidates.size()) // if i == size means we are now on last, so return from that also
            return;
        
        // skip the ith, skip ith elment
        solve(i+1, candidates, target, Sol);
        
        // involve the ith, involve ith element and so push that in sol and reduced target by it.
        Sol.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], Sol);
        // back track the sol
        Sol.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int>Sol;
        solve(0,candidates, target, Sol);
        return ans;
    }
};

int main()
{
    
    return 0;
}