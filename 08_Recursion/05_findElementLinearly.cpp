// Task: Find element in array using recursion - linear search

#include <bits/stdc++.h>
using namespace std;

bool findElement_linearSearch(int *arr, int size, int key)
{
    // base condition
    if (size == 0)
    {
        return 0; // if element not found
    }

    if (arr[0] == key)
    {
        return 1; // if element founded
    }

    bool ans = findElement_linearSearch(arr + 1, size - 1, key);
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 1;


    if (findElement_linearSearch(arr, size, key))
    {
        cout << "Element founded !";
    }
    else
    {
        cout << "Element not founded !";
    }
    return 0;
}