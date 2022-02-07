
// Task:  There is an array, we have to check, array is sorted or note using recursion

#include <bits/stdc++.h>
using namespace std;

bool isSorted_1(int arr[], int size)
{
    // base condition
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])   // in this we are checking arr[0] and arr[1] and then send arr+1 for next recursion 
    {
        return false;
    }
    else
    {
        return isSorted_1(arr + 1, size - 1);
    }
}

bool isSorted_2(int arr[], int size)
{
    // base condition
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[size-1] < arr[size-2]) // in this we are checking array's last two values and then send size-1 to next recursion
    {                              //  so that next we can check next last values.
        return false;
    }
    else
    {   
        return isSorted_2(arr, size - 1);
    }
}
int main()
{
    int arr[] = {2,4,6,9,21,12,15};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted_2(arr,size))
    {
        cout << "Given array is Sorted";
    }
    else
    {
        cout << "Given array is not Sorted";
    }
    return 0;
}
