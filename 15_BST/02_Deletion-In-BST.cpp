#include <bits/stdc++.h>
#include "001_BST.h"
using namespace std;

class Solution {
private:
    Node* minVal(Node* root)
    {
        Node* temp = root;
        while(temp -> left != NULL)
        {
            temp = temp -> left;
        }

        return temp;
    }
public:
    Node* deleteNode(Node* root, int key) {
        
        if(root == NULL)
            return root;
        
        if(root ->data == key)
        {
            // 0 child
            if(root -> left == NULL && root -> right == NULL)
            {
                delete root;
                return NULL;
            }
            
            // 1 child
            
            //left child
            else if(root -> left != NULL && root -> right == NULL)
            {
                Node* temp = root -> left;
                delete root;
                return temp;
            }
            
            //right
            else if(root -> left == NULL && root -> right != NULL)
            {
                Node* temp = root -> right;
                delete root;
                return temp;
            }
            
            // 2 child
            else if(root -> left != NULL && root -> right != NULL)
            {
                // from here we can set left's part maxdataue or right part mindataue
                // lets set rights part mindataue here
                int miniFromRight = minVal(root->right) ->data;
                root ->data = miniFromRight;
                
                // now we have to delete this miniFromRightdataue from right side of that node
                root-> right = deleteNode(root -> right, miniFromRight);
                return root; 
            }
        }
        
        else if(root ->data > key)
        {
            // go in left of the tree
            root -> left = deleteNode(root->left, key);
            return root;
        }
        else
        {
            // go in left of the tree
            root -> right = deleteNode(root->right, key);
            return root;
        }
        
        return root;
    }
};
int main()
{
    
    return 0;
}