/*
Let's call an array arr a mountain if the following properties hold:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such 
that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,5,10,2]
Output: 2

Constraints:

3 <= arr.length <= 104
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 
Follow up: Finding the O(n) is straightforward, could you find an O(log(n)) solution?
*/

#include <iostream>
#include<vector>

using namespace std;

int peakIndexInMountainArray(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1]) // if arr[mid] is less than its next element means it is on left
        {                            // side of peak so we have to shift or s on right side of mid
            s = mid + 1;
        }
        else    // here control comes if arr[mid] greater than its next element means it is on right
        {         // side of peak or can be peak so now we have to take our end on this mid;
            e = mid;   // here we cant do e = mid-1; bcoz it can be possible that mid is peak.
        }
        mid = s + (e - s) / 2; // as usual mid updation
    }
    return s;
}

int main()
{
    vector<int> arr = {0,1,2,10,15,56,34,23,22};
    int ans = peakIndexInMountainArray(arr);

    cout<<ans;

    return 0;
}