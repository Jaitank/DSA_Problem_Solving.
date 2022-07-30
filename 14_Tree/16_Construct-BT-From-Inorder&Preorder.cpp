// question link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;


// For Revision purpose, check babbar's Lecture 66 


class Solution {
    private:
    void createMapping(map<int, int>&nodeToindex, vector<int>inorder)
    {
        for(int i = 0; i < inorder.size(); i++)
            nodeToindex[inorder[i]] = i;
    }
    
    
    Node* solve(vector<int>& preorder, vector<int>& inorder,int n, int &index, int inorderStart, int inorderEnd, map<int, int>&nodeToindex)
    {
        if(index >= n || inorderStart > inorderEnd)
            return NULL;
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = nodeToindex[element];
        
        root -> left = solve(preorder, inorder, n, index, inorderStart, position -1, nodeToindex);
        root -> right = solve(preorder, inorder, n, index, position + 1, inorderEnd, nodeToindex);
        
        return root;
        
    }
public:
    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // first map inorder i/p with index so that when we wanna search we can do
        int n = preorder.size();
        map<int, int> nodeToindex;
        createMapping(nodeToindex, inorder);
        int preOrderindex = 0;
        // now solve
        Node* ans = solve(preorder, inorder, n, preOrderindex, 0, n -1, nodeToindex);
        
        return ans;
    }
};


int main()
{
    
    return 0;
}