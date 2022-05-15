#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

// question link: https://leetcode.com/problems/balanced-binary-tree/

/* Approach 1: TC- O(n2)

we have to check three condition
        1. left part should be balanced,
        2. right part should be balanced
        3. diff b/w heights should be less than equals to 1

*/
class Solution
{
private:
    int height(Node *root)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right) + 1;
        return ans;
    }

public:
    bool isBalanced(Node *root)
    {

        if (root == NULL)
            return true;
        // we have to check three condition
        // 1. left part should be balanced,
        // 2. right part should be balanced
        // 3. diff b/w heights should be less than equals to 1

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diffCond = abs(height(root->left) - height(root->right)) <= 1;

        if (left && right && diffCond)
            return 1;
        else
            return 0;
    }
};

// Approach 2: Otimised approach check balancing while counting heights

// TC-O(n)

class Solution
{
private:
    int height(Node *root, bool &ans)
    {
        if (root == NULL)
            return 0;

        int left = height(root->left, ans);
        int right = height(root->right, ans);

        if (abs(left - right) > 1)
            ans = false;

        int a = max(left, right) + 1;
        return a;
    }

public:
    bool isBalanced(Node *root)
    {

        bool ans = true;
        height(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}