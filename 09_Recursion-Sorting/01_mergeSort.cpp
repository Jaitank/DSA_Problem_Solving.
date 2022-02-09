
// Merge sort :-

#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int st, int end)
{
    int mid = st + (end - st) / 2;

    // we have to create two new arrays where we have to store our array values,
    // and then we will merge them both. so we  have to find their length that how much large we have to create.
    int len1 = mid - st + 1;
    int len2 = end - mid;

    // now dynamically create two array of respective size
    int *first = new int[len1];
    int *second = new int[len2];

    // now copy elements in them
    int mainArrayIndex = st;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // now merge them both
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = st;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Now always remember that after using dynamic memory, free them-
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int st, int end)
{
    // base case
    if (st >= end)
    {
        return;
    }

    int mid = st + (end - st) / 2; // we have find mid, now we have to break mid

    // left part
    mergeSort(arr, st, mid);

    // right part
    mergeSort(arr, mid + 1, end);


    // now merge them
    merge(arr, st, end);
}
int main()
{
    int arr[8] = {9, 3, 7, 5, 6, 4, 8, 2};
    int size = 8;
    mergeSort(arr, 0, size - 1); // in this we have to send starting and ending value, so we can find mid in function.

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}