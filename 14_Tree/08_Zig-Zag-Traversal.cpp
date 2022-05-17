// Question link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// For revise again : Lecture 64: Binary Tree 

#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        
        vector<vector<int>>result;
        if(root == NULL)return result;
        queue<Node*>q;
        q.push(root); 

        // we have to maintain a flag by which we can check we have to store values from queue left to right -> right -> left;
        bool leftToRight = true;
        
        while(!q.empty())
        {
            
            int size = q.size();
            vector<int>ans(size);

            for(int i = 0; i < size; i++)
            {
                Node* frontNode = q.front();
                q.pop();
                int index = leftToRight ? i : size - i -1;
                ans[index] = frontNode -> data;

                if(frontNode -> left) q.push(frontNode -> left);
                if(frontNode -> right) q.push(frontNode -> right);

            }
            
            leftToRight = !leftToRight;
            result.push_back(ans);

        }
        
        return result;
        
    }
};
int main()
{
    
    return 0;
}