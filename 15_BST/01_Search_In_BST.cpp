#include <bits/stdc++.h>
#include "001_BST.h"
using namespace std;


// This approach have large time complexity like in average case O(n) and in best case - O(log n) it is in recursive way and it has also 
// space complexity O(H), H: Height of tree
Node *searchBST(Node *root, int val)
{
    Node *ansNode = NULL;
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        ansNode = root;
        return ansNode;
    }

    else if (root->data > val)
        ansNode = searchBST(root->left, val);
    else
        ansNode = searchBST(root->right, val);

    return ansNode;
}

// becasue aboved way has space complexity due to recusion, now we have to do that serach in iterative way
Node* searchBST(Node* root, int val) {
    
    // set a temp ansNode to root
    Node* ansNode = root;
    
    // now check iteratively using its binary serach where we get the value, if we suppose our value to right
    // point ansNode to right and if we suppose our value in left point ansNode to left and after the end of the loop if we
    // we are not able to find ans that means searched value is not present here so return NULL
    while(ansNode != NULL)
    {
        if(ansNode -> data == val)
            return ansNode;
        
        if(ansNode -> data > val)
            ansNode = ansNode -> left;
        
        else
            ansNode = ansNode -> right;
    }
    
    return NULL;
        
    }
int main()
{

    return 0;
}