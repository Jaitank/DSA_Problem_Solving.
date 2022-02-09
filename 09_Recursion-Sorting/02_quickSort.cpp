
// Quick sort :-

#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int st, int end)
{

    // here our task is to shift st element to its right place, where in left all elements are smaller than
    // st element and in right all elements are larger than st element
    int count = 0;
    for (int i = st + 1; i <= end; i++)
    {
        if (arr[st] > arr[i])
        {
            count++;
        }
    }
    int rightIndex = st + count;
    // so here in count we get that how many elements are smaller than our st element, of that partition
    // so we have to place it to its correct position
    swap(arr[st], arr[rightIndex]);

    /*
     Now that st element is at its right place, now we have to shift all smaller than it to left
     all larger than it to its right
     for this we are use two pointer approach, one on st and one on end, compare them with rightIndex's value
    in right if we get smaller, and if in left we get larger than swap both of them.
    */
    int i = st;
    int j = end;
    while (i < rightIndex && j > rightIndex)
    {
        while (arr[i] < arr[rightIndex])
        {
            i++;
        }
        while (arr[j] > arr[rightIndex])
        {
            j--;
        }

        if (i < rightIndex && j > rightIndex)
            swap(arr[i++], arr[j--]);
    }

    return rightIndex;
}

void quickSort(int *arr, int st, int end)
{
    // base condition
    if (st >= end)
    {
        return;
    }

    int pos = partition(arr, st, end);

    quickSort(arr, st, pos - 1);
    quickSort(arr, pos + 1, end);
}

int main()
{
    int arr[15] = {9, 3, 7, 5, 6, 4, 8, 2, 12, 51, -132, 13, 12, 13, 134};
    int size = 15;
    quickSort(arr, 0, size - 1); // in this we have to send starting and ending value, so we can find mid in function.

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}