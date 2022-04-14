// question link: https://leetcode.com/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>
using namespace std;


// Approach we have sorted array and we have to evaluate square of each element and store them in ans array
// in sorted manner. so 
// first we take our index to first positive value, then we compare, each value from left and right,
// and smaller one's square stored in ans array.


vector<int> sortedSquares(vector<int> &nums)
{

    vector<int> ans;
    int size = nums.size();

    // STep1: set index pointer on first positive value if present

    int st = 0;
    int end = size - 1;
    // we will check from both side becuase sorted array, if from starting positive comes, we break
    // and if from end negative comes we break
    while (st < end)
    {
        // means all positive if below condition pass on first time
        if (nums[st] >= 0)
            break;

        // if below condition pass on first time mean all negative
        if (nums[end] < 0)
            break;
        st++, end--;
    }


    int index;

    // if we get first positive number from starting then set index pointer on it
    if (nums[st] >= 0)
        index = st;

    // if we get first negative number from end then set index pointer on next of it. because we want to set on first positive
    else if (nums[end] < 0 && end != size - 1)
        index = end + 1;

    // if all are negatives then set index on end
    else if (end == size - 1)
        index = end;
    // above we did end + 1, becuase we want our index on positive element


    // Step 2: Now start checking both side left and right from index, and jo pehle chota milta jaye uska sqr save krate jao
    
    int left = index - 1;
    int right = index;
    while (left >= 0 && right < size)
    {
        if (abs(nums[left]) > nums[right])
        {
            int val = nums[right];
            ans.push_back(val * val);
            right++;
        }
        else
        {
            int val = nums[left];
            ans.push_back(val * val);
            left--;
        }
    }
    while (left >= 0)
    {
        int val = nums[left--];
        ans.push_back(val * val);
    }
    while (right < size)
    {
        int val = nums[right++];
        ans.push_back(val * val);
    }

    return ans;
}
int main()
{

    return 0;
}