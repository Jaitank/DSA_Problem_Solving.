// question link: https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
using namespace std;

// Solution: Time complexity - O(n) and space - O(1)
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;

    // Step1: first sort interval vector
    sort(intervals.begin(), intervals.end());

    // Now insert first value of interval as it is in ans vector:
    int size = intervals.size();

    ans.push_back(intervals[0]);

    // now we have to compare starting from index 1th of intervals with ans array
    int i = 1;
    while (i < size)
    {
        if (ans.back()[1] >= intervals[i][0]) // if we get that last interval in ans has ending value of interval less greater
        // then intervals ith first value then we have to change that last interval value with the larger one of that both
        // index (ans/back(), interval[i]) because in each iteration we are comparing both of them
        {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
        i++;
    }
    // return ans;
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> ans = merge(intervals);

    return 0;
}