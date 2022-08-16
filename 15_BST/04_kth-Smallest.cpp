#include <bits/stdc++.h>
#include "001_BST.h"
using namespace std;

// we know inorder traversal of BST is sorted so we can return kth elemnt from that inorder traversal

class Solution {
private:
    void inOrder(Node* root, int &k, int&Ans)
    {
        if(root == NULL)
            return;
        
        inOrder(root -> left, k, Ans);
        k--;
        if(k == 0)
        {
            Ans = root -> data;
            return;
        }
            
        inOrder(root -> right, k , Ans);
    }
public:
    int kthSmallest(Node* root, int k) {
        
        int Ans;
        inOrder(root,k, Ans);
        return Ans;
        
    }
};


int main()
{
    
    return 0;
}