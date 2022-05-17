// question link: https://leetcode.com/problems/sum-of-left-leaves/
#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

// calculate only left leaves sum , so make a flag which tells  us we are not left or not

class Solution
{
public:
    int sumOfLeftLeaves(Node *root, bool isleft = false)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return isleft ? root->data : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};

int main()
{

    return 0;
}