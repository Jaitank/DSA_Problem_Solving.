// question link: https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n1 = -1;
        int n2 = -2;
        int cnt1 = 0;
        int cnt2 = 0;

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == n1)
                cnt1++;
            else if (nums[i] == n2)
                cnt2++;
            else if (cnt1 == 0)
            {
                n1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                n2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        // verify now
        int verifyCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == n1)
                verifyCount++;
        }
        if (verifyCount > nums.size() / 3)
            ans.push_back(n1);
        verifyCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == n2)
                verifyCount++;
        }
        if (verifyCount > nums.size() / 3)
            ans.push_back(n2);
        return ans;
    }
};

int main()
{

    return 0;
}