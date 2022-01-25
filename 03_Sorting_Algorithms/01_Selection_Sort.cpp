// Selection Sort : We have to find minimum element in unsorted array and swap it with element at begining and in next iteration
// repeat the same procedure for rest unsorted array and so on.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {64,25,12,22,11,-1,4,52,3,-234};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n-1; i++)             // i traverse from 0 to n-1 becuase for last element there is no need to check further.
    {
        int minIndex = i;              // minIndex is set for i and then it compared with rest unsorted array and if any minimum than this
        for(int j = i+1; j < n; j++)     //  is found then minIndex updated and at last it swaped with swap(a[i],a[minIndex]).
        {
            if(arr[j]<arr[minIndex])
               minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }

    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}