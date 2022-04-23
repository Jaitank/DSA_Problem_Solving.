// question link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <bits/stdc++.h>
using namespace std;

// we will calculate sum for every sliding window

// for more explanation, can check faraz youtube for this question

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int size = cardPoints.size();

        // sum of first sliding window
        int slidSum = 0;
        for (int i = 0; i < k; i++)
        {
            slidSum += cardPoints[i];
        }
        int maxSum = slidSum;

        // now every time we will substract one from left and add one from right end
        int left = k - 1;
        int right = size - 1;
        while (left >= 0)
        {
            slidSum = slidSum + cardPoints[right--] - cardPoints[left--];
            maxSum = max(maxSum, slidSum);
        }
        return maxSum;
    }
};
int main()
{

    return 0;
}