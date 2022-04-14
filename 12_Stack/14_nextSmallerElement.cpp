// question link: https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

/* Approach:  start traversing from last of the array & push element in stack and check whether stack top has mini element than
  that or not if not then pop till you wont get.
*/            

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // now it containts next smaller element
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{

    return 0;
}