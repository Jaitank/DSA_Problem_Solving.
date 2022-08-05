// question link: https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>
#include "001_BST.h"
using namespace std;


/// Approach 1: We knom that Inorder traversal of every BST is always sorted , so store elements of BST in Inorder manner and check
// array is sorted or not, if yes BST is there and if not then no BST

// Time Complexity : O(n) becuase we have to traverse on all node 1 time and it users
// Space Cmp: O(n), we have used vector for store elements
class Solution1 {
private:
    void inOrder(Node* root, vector<int>& inOrderVec)
    {
        if(root == NULL)
            return;

        inOrder(root -> left, inOrderVec);
        inOrderVec.push_back(root -> data);
        inOrder(root -> right, inOrderVec);
        
        
    }
public:
    bool isValidBST(Node* root) {
        
        vector<int> inOrderVec;
        
        inOrder(root, inOrderVec);
        
        // Now check inOrderVec is sorted or not
        
        for(int i = 0; i < inOrderVec.size() - 1; i++)
        {
            if(inOrderVec[i] >= inOrderVec[i + 1])
                return false;
        }
        return true;
        
        
    }
};


// Approach 2: Without using extra vector Space Optimised one

class Solution2 {
private:
    bool validation(Node* root, int min, int max)
    {
        if(root == NULL)
            return true;
        
        if(root -> data > min && root -> data < max)
        {
            bool left = validation(root -> left, min, root -> data);
            bool right = validation(root -> right, root -> data, max);
            return left && right;
                
        }
        
        return false;
        
    }
public:
    bool isValidBST(Node* root) {
        
        // Some times when node val is greater than INT_MAX then this will give wrong answer
        return validation(root,INT_MIN, INT_MAX);
        
    }
};


// This could also be a solution if INT_MAX problem occur

class Solution3 {
private:
    bool isValidBST(Node* root, Node* minNode, Node* maxNode){
        
        if(!root){
            return true;
        }
        if(minNode && root->data <= minNode->data || maxNode && root->data >= maxNode->data){
            return false;
        }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
public:
    bool isValidBST(Node* root) {

        return isValidBST(root, NULL, NULL);
    }


};




int main()
{
    
    return 0;
}