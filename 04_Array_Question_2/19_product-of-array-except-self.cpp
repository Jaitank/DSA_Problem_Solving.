// question link: https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 1);
    int fromBegin = 1;
    int fromLast = 1;
    // we will store in ith place its leftside product and rightside product.
    for (int i = 0; i < n; i++)
    {
        res[i] *= fromBegin;
        fromBegin *= nums[i];

        res[n - 1 - i] *= fromLast;
        fromLast *= nums[n - 1 - i];
    }
    return res;
}
int main()
{

    return 0;
}