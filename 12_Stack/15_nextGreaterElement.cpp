// question link: https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

/* Approach:  start traversing from last of the array & push element in stack and check whether stack top has max element than
  that, or if not then pop till you wont get. and when you get map than element with its next greater so that we can
  find ans
*/

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    stack<int> s;
    s.push(-1);
    int n2 = nums2.size();
    int n1 = nums1.size();
    vector<int> ans(n1);

    unordered_map<int, int> umap;

    for (int i = n2 - 1; i >= 0; i--)
    {
        int curr = nums2[i];
        while (s.top() <= curr && s.top() != -1)
            s.pop();
        // now we have max then curr on top
        umap[nums2[i]] = s.top();
        s.push(curr);
    }
    // now we have mapped all nextGreater with their values
    for (int i = 0; i < n1; i++)
    {
        ans[i] = umap[nums1[i]];
    }

    return ans;
}

int main()
{

    return 0;
}