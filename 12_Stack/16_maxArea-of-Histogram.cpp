// question link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

// Approach : Count prevSmaller Element and nextSmaller element for each element of heights and calculate area, the max area we get is our ans

class Solution {
private: 
    vector<int> nextSmallerElements(vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            // now it containts next smaller element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerElements(vector<int> heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (s.top() != -1 && heights[s.top()] >= curr)
            {
                s.pop();
            }
            // now it containts next smaller element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElements(heights, n);
        vector<int> prev(n);
        prev = prevSmallerElements(heights, n);
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++)
        {   
            if(next[i] == -1) // if on last index
            {
                next[i] = n;
            }
            int len = heights[i];
            
            int wid = next[i] - prev[i] - 1;
            
            int area = len * wid;
            maxArea = max(maxArea, area);
            
        }
        return maxArea;
    }
};
int main()
{
    
    return 0;
}