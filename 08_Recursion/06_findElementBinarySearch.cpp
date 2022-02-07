// Task: Find element in array using recursion - apply binary search

#include <bits/stdc++.h>
using namespace std;

bool findElement_binarySearch(int arr[], int size, int key, int st, int end)
{
    // base condition
    if ( st > end)          
    {
        return 0;         // Element not found
    }
    int mid =  st + (end - st) / 2;

    if (arr[mid] == key)
    {
        return 1; // element founded
    }

    else
    {
        if (arr[mid] > key)
            return findElement_binarySearch(arr, size, key, st, mid - 1);
        else
            return findElement_binarySearch(arr, size, key, mid + 1, end);
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 6;

    int st = 0;
    int end = size -1;

    if (findElement_binarySearch(arr, size, key, st, end))
    {
        cout << "Element founded !";
    }
    else
    {
        cout << "Element not founded !";
    }
    return 0;
}