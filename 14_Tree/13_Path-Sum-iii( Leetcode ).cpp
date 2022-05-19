// question link:   https://leetcode.com/problems/path-sum-iii/


#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

//  here we have to find no. of paths which is equal to targetSum , this path can start from any node and can stop at any node
// we will use concept of no of subarrays equals to k



class Solution {
private:
    long long solve(Node* root, int targetSum, long long sum, int &ansCount, unordered_map<int,int>m)
    {
        if(root == NULL)
            return 0;
        
        sum += root -> data;
        if(sum == targetSum)
            ansCount++;
        if(m.find(sum - targetSum) != m.end())
            ansCount+= m[sum - targetSum];
        m[sum]++;
        
        solve(root -> left, targetSum, sum, ansCount, m);
        solve(root -> right, targetSum, sum, ansCount, m);
        return sum;
    }
public:
    int pathSum(Node* root, int targetSum) {
        
        long long sum = 0;
        int ansCount = 0;
        unordered_map<int,int>m;
        solve(root, targetSum, sum, ansCount, m);
        return ansCount;
    }
};

int main()
{
    
    return 0;
}