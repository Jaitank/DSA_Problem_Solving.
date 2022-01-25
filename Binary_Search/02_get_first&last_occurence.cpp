/*
You have been given a sorted array/list ARR consisting of ‘N’ elements. You are also given an integer ‘K’.
Now, your task is to find the first and last occurrence of ‘K’ in ARR.
Note :
1. If ‘K’ is not present in the array, then the first and the last occurrence will be -1. 
2. ARR may contain duplicate elements.
For example, if ARR = [0, 1, 1, 5] and K = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.
*/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int firstOcc(vector<int> &arr, int n, int key)
{

    int s = 0, e = n - 1;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {

        if (arr[mid] == key) 
        {
            ans = mid;         
            e = mid - 1; // here we are changing end because we are checking for first occurence this will push our loop on left side of mid.
        }

        else if (key > arr[mid])
        { 

            s = mid + 1;
        }

        else if (key < arr[mid])
        { 

            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int lastOcc(vector<int> &arr, int n, int key)
{

    int s = 0, e = n - 1;

    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {

        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;  // here we are changing start because we are checking for last occurence this will push our loop on right side of mid.
        }

        else if (key > arr[mid])
        { 

            s = mid + 1;
        }

        else if (key < arr[mid])
        { 

            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)

{
    pair<int, int> p;

    p.first = firstOcc(arr, n, k);

    p.second = lastOcc(arr, n, k);

    return p;
}