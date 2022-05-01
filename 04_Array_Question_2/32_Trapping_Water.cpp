// quesion link: https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

// naive approach : calculate water quantity for each index, so calculate rightMax, and leftMax from that index

// TC: O(n^2) and SC: O(1)
int maxWater(int arr[], int n)
{

    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    return res;
}
/*
A bit more optimisation that make all test cases passed in leetcode with beating 5% of solution

calcuate first leftMax and rightMax for 1st index, and then at each iteration check if that index is greater than leftMax
then update and when we cross rightMax index then again check rightMax from that,
by that we do not have to calculate leftMax and rightMax at every iteration but, at worst case it can be slow

    TC: O(n^2) and SC: O(1) in worst condition and, in best case TC: O(n) and SC: O(1)
*/

int trap(vector<int> &height)
{
    int n = height.size();

    if (n < 3)
        return 0;
    int result = 0;

    int left = height[1];
    for (int j = 0; j < 1; j++)
        left = max(left, height[j]);

    int right = height[1];
    for (int j = 2; j < n; j++)
        right = max(right, height[j]);

    for (int i = 1; i < n - 1; i++)
    {
        if (height[i] > left)
            left = height[i];
        if (height[i - 1] == right && i >= 0)
        {
            left = right;
            right = height[i];
            for (int j = i + 1; j < n; j++)
                right = max(right, height[j]);
        }

        result += (min(left, right) - height[i]);
    }

    return result;
}

/*
Now lets save leftMax and rightMax for every index as prefix and suffix
   in Prefix we will store leftMax till respective index
   in Suffix we will store rightMax till respective index (start stroring from end and then reverse that array make that suffix array)

   and Now start iterating on given heights and apply leftMax and rightMax from that prefix and suffix

   TC: O(n) and SC: O(2n)
*/

int trap(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    if (n < 3)
        return 0;
    vector<int> prefix;
    vector<int> suffix;
    int maxP = INT_MIN;
    int maxS = INT_MIN;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        maxP = max(maxP, height[i]);
        prefix.push_back(maxP);

        maxS = max(maxS, height[j]);
        suffix.push_back(maxS);
    }

    reverse(suffix.begin(), suffix.end());

    for (int i = 0; i < prefix.size(); i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < suffix.size(); i++)
    {
        cout << suffix[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n - 1; i++)
    {
        int left = prefix[i];
        int right = suffix[i];

        res += (min(left, right) - height[i]);
    }

    return res;
}

/*
Optimised Approach : For better intution see strivers video on that question

TC: O(n) and SC: O(1)
*/

int trap(vector<int> &height)
{
    int n = height.size();
    int res = 0;
    if (n < 3)
        return 0;
    int st = 0;
    int end = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    while (st < end)
    {
        if (height[st] <= height[end])
        {
            if (height[st] > leftMax)
                leftMax = height[st++];
            else
                res += leftMax - height[st++];
        }
        else
        {
            if (height[end] > rightMax)
                rightMax = height[end--];
            else
                res += rightMax - height[end--];
        }
    }
    return res;
}
int main()
{

    return 0;
}