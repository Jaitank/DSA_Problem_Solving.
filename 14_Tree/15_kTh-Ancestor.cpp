// question link: https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1



#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;


Node* solve(Node* root, int node, int &k)
{
    if(root == NULL)
        return NULL;
    if(root -> data == node)
        return root;
        
    Node* leftAns = solve(root -> left, node, k);
    Node* rightAns = solve(root -> right, node, k);
    
    // wapas ate time
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    
    Node* ans = solve(root, node, k);
    if(ans == NULL || ans -> data == node)
        return -1;
    else
        return ans -> data;
    
}


int main()
{
    
    return 0;
}