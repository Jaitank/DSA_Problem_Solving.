// question link: https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

/*
    We have to check for all nodes that after them all the values shoudl be equals

    in every call
     1. Go right and left at same time for both trees  and check for their left and right
     2. their data should be equal at all level

*/

class Solution
{
public:
    bool isSameTree(Node *p, Node *q)
    {

        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q == NULL || p == NULL && q != NULL)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool cond = p->data == q->data;

        if (left && right && cond)
            return true;
        else
            return false;
    }
};
int main()
{

    return 0;
}