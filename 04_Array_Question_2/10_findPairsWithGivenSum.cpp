//Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
// link : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#


#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) // tc- o(n2)
{
    /* two pointer approach - iterating all pairs.
     iterate pointer -  "end" till it is equal to st + 1, so that we get all pair for that st,
     and when end will less than or equal to st, then again set end = n -1 and st++; now again check all pairs respective to that st
    */
    int st = 0;
    int end = n - 1;
    int count = 0;
    while (st < n - 1)
    {
        if (arr[st] + arr[end] == k)
        {
            count++;
            end--;
            if (st + 1 > end)
            {
                
                end = n - 1;
                st++;
            }
        }
        else
        {
            end--;
            if (st + 1 > end)
            {
                
                end = n - 1;
                st++;
            }
        }
    }
    return count;
}


int getPairsCount2(int arr[], int n, int k) //TC- O(n) and SC= O(1)
{
    if (n == 1)
        return 0;
    unordered_map<int, int> umap;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += umap[k - arr[i]];
        umap[arr[i]]++;
    }
    return ans;
}

int main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int n= 9;
    int k = 8;

    cout << getPairsCount(arr, n, k);


    return 0;
}