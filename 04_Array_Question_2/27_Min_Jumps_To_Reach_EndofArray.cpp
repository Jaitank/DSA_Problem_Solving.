// question link: https://leetcode.com/problems/jump-game-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // lst index => end
        int end = nums.size() - 1;

        // if last index is also first index, measn only one element
        if (end == 0)
            return 0;

        // if first element is zero so we cant move forward from it.
        if (nums[0] == 0)
            return -1;

        // now find every time and acc to it. decide steps and make
        // jump ++ only when, once step becomes 0
        int maxRange = nums[0];
        int steps = nums[0];
        int jump = 0;

        // we have to go till end so in it, we cant increase jump for laszt
        // so we have to return jump+ 1 at last
        for (int i = 1; i < end; i++)
        {
            // step is set as maxRange
            steps--;
            maxRange = max(maxRange, nums[i] + i);

            // till all steps not finished we do not have to make jump
            if (steps == 0)
            {
                jump++;
                // when steps finished now update step as maxRange we have
                steps = maxRange - i;
                if (steps <= 0)
                    return -1; // -ve elements so cant move further
            }
        }

        return jump + 1;
    }
};

int main()
{

    return 0;
}