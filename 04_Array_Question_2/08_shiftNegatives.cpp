#include <bits/stdc++.h>
using namespace std;

// shift all negatives in left with same order of elements.

// this is o(n2) approach this problem can be solve by o(n) approach (find that s0lution later!)

void func(int *arr, int size)
{
    int filling = size - 1;
    for (int comparing = size - 1; comparing >= 0 ; comparing--)
    {
        if(arr[comparing] < 0)
        {
            int temp = arr[comparing];
            for (int i = comparing; i < filling; i++)
            {
                arr[i] = arr[i+1];
            }
            arr[filling--] = temp;
        }

    }
}
int main()
{
    int arr[] = {-2, 5, 32, -34, 2, 56, -3, -5, 8, 3, -3, -4, -6};
    int size = sizeof(arr) / sizeof(arr[0]);

    func(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}