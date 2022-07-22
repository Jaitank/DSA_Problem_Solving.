// question link: https://leetcode.com/problems/path-sum-ii/



#include <bits/stdc++.h>
#include "001Tree.h"

using namespace std;

/*

 Here we are going to use DFS approach where we will track each path from root to leaf and stroe each element which comes on path in vector and when we are on leaf then we check that vector sum, if it is equal to targetSum then we push that vector or path to our ans matrix, and while changing path from left node to right node we will use pop back in vector(backtrack) so that now we can see path with another child

*/


class Solution {
private:
    void solve(Node* root, int targetSum, vector<vector<int>> &ans, vector<int> &path)
    {
        if(root == NULL)
            return;
        path.push_back(root -> data);
        
        // solve for left 
        solve(root -> left, targetSum, ans, path);
        // solve for right
        solve(root -> right, targetSum, ans, path);
        
        // checking the paths
        int size = path.size();
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += path[i];
        }
        if(sum == targetSum && root -> right == NULL && root -> left == NULL)
        {
            ans.push_back(path);
        }

        // backtracking because now we are now going to shift on another child node
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(Node* root, int targetSum) {
        
        
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, ans, path);
        return ans;
        
    }
};

int main()
{
    
    return 0;
}