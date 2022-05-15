#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

int maxDepth(Node *root)
{

    if (root == NULL)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main()
{

    return 0;
}