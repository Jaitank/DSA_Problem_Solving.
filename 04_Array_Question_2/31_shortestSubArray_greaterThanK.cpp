// question link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include <bits/stdc++.h>
using namespace std;

/* Approach : Like Kadannes algo find currSum while iteratinng and whenever we get greater than k 
              and when we get now we have our start pointer on first index, so shift st index in forward
              till we get smaller than k, and calculate length in each shift so that we can get min Length
*/

int smallestSubWithSum(int nums[], int n, int k)
{
    int minLength = INT_MAX;
    int currSum = 0;
    int length;
    int st = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        while (currSum > k && st < n)
        {
            length = i - st + 1;
            minLength = min(length, minLength);
            currSum -= nums[st++];
        }
    }
    return minLength;
}
int main()
{

    return 0;
}