// question link: https://leetcode.com/problems/subarray-sum-equals-k/

/*
Approach: We have to maintain an unordered map in which we will store the previous all currSums, 
          Now we have to check by types

          if (currSum == target) => count++;

          if(currSum - k) if somewhere in unorderemap means previous currSum are equals to that value,
                          if that currSum is present already increase its count in value field of map => umap[curSum]++;
                          and if not present already then store with value 1. => umap[curSum] = 1;
                          basically we are storing occurence of that currSum

          e.g target = 14, arr = {1,2-3,3,5,1,3,5}: here till 2 ith values currSum was 3 somewhere stored in map like umap[3] = 1
          and till {1,2,-3,3} also has currSum = 3 so increase its occurence in its values field like umap[currSum]++;
          means umap[3] = 2 stored
          and till last we have currSum = 17, so if currSum - target = 17-14 = 3, and 3 is present in map 2 times,
          means when [1,2] make currSum 3 then subArray = [-3,3,5,1,3,5] and when second time 
          [1,2,-3,3] make currSum = 3, then subarray [5,1,3,5] (whose sum is equal to target), so total 2 subarray are there.



*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{

    int count = 0;
    unordered_map<int, int> umap;
    int currSum = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        currSum += nums[i];
        if (currSum == k)
        {
            // if currSum is equal then increase count by 1
            count++;
        }
        // now check our map that any more subarray till now equals or not, and increase count respectively
        if (umap.find(currSum - k) != umap.end())
        {
            int val = umap[currSum - k];
            count += val;
        }
        // if currSum is already in map then increase its value in which we are storing that cursum occurence
        if (umap.find(currSum) != umap.end())
        {
            umap[currSum]++;
        }
        // if any currsum occured first time then intialise it, with occurcne (value) 1.
        else
        {
            umap[currSum] = 1;
        }
    }
    return count;
}
int main()
{

    return 0;
}