// Task: Find sum of array using recursion.

#include <bits/stdc++.h>
using namespace std;

int findSum(int *arr, int size, int sum = 0)
{
    // base condition
    if (size == 0)
    {
        return sum; // when whole array decayed and we have size == 0 then return sum we have calculated till now
    }
    sum = sum + arr[size - 1];   // update sum with addition of one  last number of array accoding to size
    findSum(arr, size - 1, sum); // then send size-1 in next recursion.
}
int main()
{
    int arr[] = {1, 2, 13, 24, -23, 4, 52};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Sum of array is : " << findSum(arr, size);
    return 0;
}