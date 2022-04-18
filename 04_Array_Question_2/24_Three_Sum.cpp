// question link: https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

/* Approach : - First sort the array
              - pick one element in one loop every time , consider it as first element
              - now try to seach another two numbers with whom we get sum == target
              - becuase we have sorted the array so we can find that two easily like we do in 12_two_sum.cpp
              - and eliminate duplicate elements 
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    // we have to return all triplets which are equal to zero
    vector<vector<int>> ans;
    // sort nums
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size < 3)
    {
        return ans;
    }
    for (int i = 0; i < size; i++)
    {
        int firstEle = nums[i];
        int remEle = 0 - firstEle;
        int s = i + 1;
        int e = size - 1;
        while (s < e)
        {
            int sum = nums[s] + nums[e];
            if (sum == remEle)
            {
                ans.push_back({firstEle, nums[s], nums[e]});
                while (s < e && nums[s] == nums[s + 1]) // eleminate duplicate elements 
                    s++;
                while (s < e && nums[e] == nums[e - 1]) // remove duplicates
                    e--;
                s++, e--;
            }
            else if (sum > remEle)
                e--;
            else
                s++;
        }
        while (i + 1 < size && nums[i + 1] == nums[i]) // remove duplicates
            i++;
    }
    return ans;
}

int main()
{

    return 0;
}