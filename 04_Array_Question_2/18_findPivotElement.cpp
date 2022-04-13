// question link: https://leetcode.com/problems/find-pivot-index

// we have to check does from an element left sum == right sum if yes return that index,
// check from left side and return that type of left most index


//so we will maintain leftsum and right sum left sum starting calculating from 0th index wiht iterating
// and rightsum initial is equal to totalSum and while iterating, we will substract iterating element so we can get right sum from it.

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int leftSum = 0;
    int rightSum = 0;
    int totalSum = 0;
    int n = nums.size();

    // finding total sum
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
    }

    // right sum initialy when we are checking for 1st element
    rightSum = totalSum - nums[0];
    if (rightSum == leftSum)
        return 0;

    // then maintaing rightsum by substracting element, and leftsum by adding    
    for (int i = 1; i < n; i++)
    {
        leftSum = leftSum + nums[i - 1];
        rightSum = rightSum - nums[i];
        if (leftSum == rightSum)
            return i;
    }
    return -1;
}

int main()
{

    return 0;
}