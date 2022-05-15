// question link: https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
#include "001Tree.h"


/* Diameter: Max distance b/w any two nodes 
For calculating diameter we can see that, we have three options to get diameter - 
      MAX [ 1. diameter of left side,
        2. diameter of right side, 
        3. heightleft + heightRight ]

        max of them are called diameter of binary tree


*/


// 1. Approach 1: Brute force approach -  In this approach time complexity will be O(n2) because we have to count height "n" times (in each recursion)

class Solution1 {
private:
    int height(Node* root)
    {
        if(root == NULL)
            return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
    int diameter(Node* root)
    {
        if(root == NULL)
            return 0;
        
        int op1 = diameter(root->left);
        int op2 = diameter(root -> right);
        int op3 = height(root->left) + height(root -> right) + 1;
        
        int ans = max(op1, max(op2, op3));
        return ans;
    }
    
public:
    int diameterOfBinaryTree(Node* root) {
        
        int ans = diameter(root);
        return ans - 1;
    }
};


// Apporach 2: we can observe we have to decrease time of calculating height of tree every time

// So we will decide to calculate height and diameter at same time and store them in pair<int, int> ans, in which first - diamter, second - height

// TC - O(n)


class Solution2 {
private:
    pair<int, int> diameter(Node* root)
    {
        if(root == NULL)
            return {0,0};
        
        pair<int, int> left = diameter(root -> left);
        pair<int, int> right = diameter(root -> right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    
public:
    int diameterOfBinaryTree(Node* root) {
        
       return diameter(root).first; // diameter
       // if we have to return no of edges between them
       return diameter(root).first - 1;
    }
};


// Approach 3: we can also calculate usig referencing method, here we will not use pairs
// Tc - O(n) most optimised Solution

class Solution3 {
private:
    int height(Node* root, int &diameter)
    {
        if(root == NULL)
            return 0;
        
        int left = height(root -> left, diameter);
        int right = height(root -> right, diameter);
        
        diameter = max(diameter, left + right);
        return (max(left, right) + 1);
    }
public:
    int diameterOfBinaryTree(Node* root) {
        
        int diameter = 0;
        height(root, diameter);

        // if have to return no of edges 
        return diameter;
        // if have to return no of nodess
        return diameter + 1;
    }
};






using namespace std;
int main()
{
    
    return 0;
}