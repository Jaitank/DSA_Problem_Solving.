// question link: https://leetcode.com/problems/running-sum-of-1d-array/
#include <bits/stdc++.h>
using namespace std;

// Approach: we first find overall sum, and then decrease from back one - one element value


vector<int> runningSum(vector<int> &nums)
{
    vector<int> ans;
    int size = nums.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
    }
    ans.insert(ans.begin(), sum);
    int remSum = sum;
    int e = size - 1;
    while (e > 0)
    {
        remSum = remSum - nums[e];
        ans.insert(ans.begin(), remSum);
        e--;
    }
    return ans;
}

int main()
{
    
    return 0;
}