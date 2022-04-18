// question link :  https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
using namespace std;

// approach  : same approach to find three sum, just maintain minimun diff with target and update ans accordingly
//              when we get min diff

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int minDif = INT_MAX;
    int ans;

    for (int i = 0; i < n; i++)
    {
        int firstEle = nums[i];
        int s = i + 1;
        int e = n - 1;
        while (s < e)
        {
            int sum = firstEle + nums[s] + nums[e];
            if (sum == target)
            {
                return sum;
            }
            else if (sum < target)
            {
                if (target - sum < minDif)
                {
                    minDif = target - sum;
                    ans = sum;
                }
                while (s < e && nums[s + 1] == nums[s])
                    s++;
                s++;
            }
            else
            {
                if (sum - target < minDif)
                {
                    minDif = sum - target;
                    ans = sum;
                }
                while (s < e && nums[e] == nums[e - 1])
                    e--;
                e--;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }
    return ans;
}
int main()
{

    return 0;
}