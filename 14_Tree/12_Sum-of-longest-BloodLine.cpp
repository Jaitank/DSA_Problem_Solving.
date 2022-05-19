// question link:  https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

// we have to find sum of longest path of (root -> leaft)
// we have to go through every path and calculate sum and its length, and have to maintain maxLen and maxSum

class Solution
{
private:
    void solve(Node* root, int len, int &maxLen, int sum, int &maxSum)
    {
        // base case
        if(root == NULL)
        {
            if(len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen)
                maxSum = max(sum, maxSum);
            return;
        }
        
        sum += root -> data;
        solve(root -> left, len+1, maxLen, sum, maxSum);
        solve(root -> right, len+1, maxLen, sum, maxSum);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = 0;
        
        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};


int main()
{
    
    return 0;
}