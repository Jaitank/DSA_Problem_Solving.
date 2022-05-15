// question link: https://practice.geeksforgeeks.org/problems/sum-tree/1/

#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

/*

    1. when we on the leaf return its value
    2. when we on any parent node in tree(other than leaf) check its leftSum and rightSum should be equla to its data
    3. and return sum = root -> val + leftSum + rightSum;


*/

class Solution
{
private:
    int checkSumTree(Node *root, bool &ans)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->data;

        int leftSum = checkSumTree(root->left, ans);
        int rightSum = checkSumTree(root->right, ans);

        if (leftSum + rightSum != root->data)
            ans = false;

        int Sum = 2 * root->data; // this should be written as 2* becuase we know leftSum + rightSum = root -> data

        return Sum;
    }

public:
    bool isSumTree(Node *root)
    {
        bool ans = true;
        checkSumTree(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}