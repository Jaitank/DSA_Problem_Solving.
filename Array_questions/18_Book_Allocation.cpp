/*
Given an array 'arr' of integer numbers , where 'arr[i] represents the number of pages.
There are 'm' number of students and the task is to allocate all the books to their students.
Allocate books in such a way that:

1. Each student gets at least one book.

2. Each book should be allocated to a student.

3. Book allocation should be in contiguous manner.

You have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.

Approach: To learn its approach Revise this video:
https://www.youtube.com/watch?v=YTTdLgyqOLY&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15&t=2172s&ab_channel=CodeHelp-byBabbar
*/
#include <bits/stdc++.h>
using namespace std;

bool isPossible_Soln(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }

    return true;
}

int allocateBooks(int arr[], int n, int m) //  here n = size of array and m = no of students.
{
    int s = 0; // intialised start
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;

    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossible_Soln(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
int main()
{
    int arr[] = {10, 20, 30, 40}; //  This is the pages of each book in every index.
    int size = sizeof(arr) / sizeof(arr[0]);
    int m = 2; // No of students

    cout << "Anwer is :" << allocateBooks(arr, size, m);

    return 0;
}