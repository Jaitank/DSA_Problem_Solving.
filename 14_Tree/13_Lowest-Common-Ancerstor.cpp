// question link:   https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/


#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

class Solution {
public:
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        
        Node* leftAns = lowestCommonAncestor(root -> left, p, q);
        Node* rightAns = lowestCommonAncestor(root -> right, p, q);


       /// we have to check after recursive calls because we have to check for ancestors thats why we have to check while returning 
        
        if(leftAns != NULL && rightAns != NULL)
            return root;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};

int main()
{
    
    return 0;
}