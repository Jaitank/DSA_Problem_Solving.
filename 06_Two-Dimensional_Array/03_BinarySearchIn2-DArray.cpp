#include <bits/stdc++.h>
using namespace std;

/*
Problem: In the 2-D array, every row is sorted and every row's last element is smaller
         than its next row's first element.
         Means we can consider all elements (row-wise) as linear list and we can apply binary search in that
*/

bool binarySearch(vector<vector<int>> matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1; // end index is found out by total size of array - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = matrix[mid / col][mid % col]; // mid we get in linear list is on which positon, so to get that index of rows and column
        // consider notes
        if (element == target)
        {
            return 1;
        }

        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int key;
    cout << "Enter element you want to search in array : ";
    cin >> key;

    // Search that key in that 2-D Array by using Binary search.

    if (binarySearch(arr, key))
    {
        cout << "Element Founded !";
    }
    else
    {
        cout << "Element Not Founded !";
    }
    return 0;
}