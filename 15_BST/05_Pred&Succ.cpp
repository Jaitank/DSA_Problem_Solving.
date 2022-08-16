#include <bits/stdc++.h>
#include "001_BST.h"
using namespace std;

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    
    // We know predecessor is the maximum one from left part of node
    // and successor is the minimum from right part of the node
    
    // Step 1: first we have to find key
    Node* temp = root;
    while(temp -> data != key)
    {
        if(temp-> data > key)
        {
            suc = temp;
            temp = temp -> left;
            
        }
        else
        {
            pre = temp;
            temp = temp -> right;
            
        }
    }
   
    // After this key has been finded now we have to set suc and pre
    // STEP 2: Pre : maximum of left sub tree of key's node
    Node* leftSubTree = temp -> left;
    while(leftSubTree != NULL)
    {
        pre = leftSubTree;
        leftSubTree = leftSubTree -> right;
    }
    
    // STEP 3: Suc : minimum of right sub tree of key's node
    Node* rightSubTree = temp -> right;
    while(rightSubTree != NULL)
    {
        suc = rightSubTree;
        rightSubTree = rightSubTree -> left;
    }
 
}
int main()
{
    
    return 0;
}