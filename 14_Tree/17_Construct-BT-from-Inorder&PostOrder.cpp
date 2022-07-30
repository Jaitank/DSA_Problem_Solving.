// question link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/


#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;


// For Revision, babbar's L-66



class Solution {
private:
    void createMapping(vector<int> inorder,map<int, int> &nodeToIndex)
    {
        for(int i = 0; i < inorder.size(); i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve(vector<int>& inorder, vector<int>& postorder, int n, int &index, int inorderStart, int inorderEnd, map<int, int>&nodeToIndex)
    {
        // base case
        if(index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element = postorder[index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        // here we have to build tree from right part first, becuase we select root here from postroder index where, after a node 
        // while traverse reverse in postorder array we get right part first after root node
        root -> right = solve(inorder, postorder, n, index, position + 1, inorderEnd, nodeToIndex);
        root -> left = solve(inorder, postorder, n, index, inorderStart, position -1, nodeToIndex);
        
        
        return root;
            
    }
public:
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // create mapping of inorder
        map<int, int>nodeToIndex;
        createMapping(inorder, nodeToIndex);
        
        // preorder vector size
        int n = postorder.size();
        
        // set postOrderIndex
        int postOrderIndex = postorder.size() - 1;
        
        // now solve the question
        Node* ans = solve(inorder, postorder, n, postOrderIndex, 0, n-1, nodeToIndex);
        
        return ans;
        
    }
};


int main()
{
    
    return 0;
}