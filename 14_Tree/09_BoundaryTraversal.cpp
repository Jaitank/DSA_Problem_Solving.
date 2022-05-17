// question link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/

#include <bits/stdc++.h>
#include"001Tree.h"
using namespace std;


class Solution {
private:
    void leftTraversal(Node* root, vector<int> &ans)
    {
        // if leaft or on NULL return we do not have to include leaf on leftTraversal for boundary
        if( (root == NULL) || (root -> left == NULL && root -> right == NULL) )
            return;
        
        ans.push_back(root -> data);

        // if some node does not have left node, then its right node considered as boundary   
        if(root -> left)
            leftTraversal(root -> left, ans);
        else
            leftTraversal(root -> right, ans); // left node not exist so right is boundary
    }
    
    void leafTraversal(Node* root, vector<int> &ans)
    {
        if(root == NULL)
            return;

        // only have to store values of leaves  
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> data);
            return;
        }
            
        leafTraversal(root -> left, ans);
        leafTraversal(root -> right, ans);
   
    }
    
    void rightTraversal(Node* root, vector<int> &ans) // same logic as left have, one and only change we have to store values while
                                                        // returning again from leaf
    {
        if( (root == NULL) || (root -> left == NULL && root -> right == NULL) )
            return;
            
        if(root -> right)
            rightTraversal(root -> right, ans);
        else
            rightTraversal(root -> left, ans);
            
        ans.push_back(root -> data);
    }
public:
    vector <int> boundary(Node *root)
    {
        // this question can solve in three Steps
        // 1. first print all left nodes from root except leaf
        // 2. then print all leaf from left to right
        // 3. then print all right in reverse except leaf
        
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        ans.push_back(root -> data);
            
        // 1. Print left part
        leftTraversal(root -> left, ans);
        
        // 2. Leaf part (becuase we have covered root part so we have send left part of tree and right part of tree)
        
        // a. leaves of left part of tree
        leafTraversal(root-> left, ans);
        // b. leafes of right part of tree
        leafTraversal(root -> right, ans);
        
        // 3. Now right part in reverse so store while returning from leaf node
        rightTraversal(root -> right, ans);
        
        return ans;
    }
};



int main()
{
    
    return 0;
}