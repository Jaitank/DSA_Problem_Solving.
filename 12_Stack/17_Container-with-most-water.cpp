// question link: https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;

/* Approach: We have given height, and we have to calculate max Area
             so we have to, calculate this, for that we have to maintain two pointers,
             one on startin and one on end, then calculate area for both, and store it in maxArea,
             and if starter pointers height is lesser then increase start pointer, and if end pointers
             heights is lesser then decrease end pointer, because we are calculating max Area,
             and every time compare and store maxArea.
*/
int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxArea = 0;

    // starting pointer
    int st = 0;
    // ending pointer
    int end = n - 1;
    while (st < end) // till start pointer not cross end pointer
    {
        int len = min(height[st], height[end]); // select height which is min, so that we can calculate area b/w them
        int wid = end - st; // distace b/w them
        int area = len * wid;
        maxArea = max(maxArea, area); // check that area is max if yes then store

        // which height is lesser, shift that pointer
        if (height[st] < height[end]) 
            st++;
        else if (height[end] < height[st])
            end--;
        else // if both heights are same then shift both
        {
            st++, end--;
        }
    }
    return maxArea;
}

int main()
{

    return 0;
}