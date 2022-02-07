
// Bubble sort using recursion

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int size) // in bubble sort we have to repeatdly swap two adjacent element
{
    // base condition
    if (size == 0 || size == 1)       // already sorted conditions
    {
        return;
    }
    // one case solved in which max element swaped to its right place (at last).
    // rest same cases will be done by recursion
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,size-1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i< size; i++)
    {
        cout << arr[i] << " ";
    }
}


int main()
{
    int arr[6] = {3,4,1,6,2,5};

    // Bubble sort using recursion:
    bubbleSort(arr,6);

    // array after sorting
    printArray(arr,6);

    return 0;
}