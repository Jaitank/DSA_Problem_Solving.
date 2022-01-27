/* Move all zero to right side of array and non-zero to left in same order as they present intially
   For Eg: a[] = [1,2,0,3,0,0,7,0] ==> [1,2,3,7,0,0,0,0]
*/

#include <bits/stdc++.h>
using namespace std;
/* Appraoch 1: Here we traverse array and count zero, that how much zeroes our array have. 
               And during traversing array when we get non-zero number then we will send them to j = 0 and do j++ and 
               if again find non-zero then it will send to j = 1 and do j++ by this, left side will filled by non-zero 
               elements and when array ends. Then we going to use zeroes count. Suppose in traversing we have 5 zero then
               5 indexes after that non-zero elements are filled with 0
*/
void moveZeros_1(int nums[], int size)
{

    int countZero = 0;
    int n = size;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
        else
        {
            countZero++;
        }
    }
    while (countZero != 0)
    {
        nums[j] = 0;
        j++;
        countZero--;
    }
}

/* Approach 2: Here we going to use 2 pointer approach 1 pointer as 'i = 0' for filling non zero values,
               and 'j' for traverse on array and when j is on non zero it send that to i and then i ++;
               and by that all non zero value in same order are filled in array on left side and zeroes remains
               on right side
*/

void moveZeros_2(int arr[], int size)
{
    int i = 0;
    for ( int j = 0; j < size; j++)
    {
        if ( arr[j] != 0)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {1, 2, 0, 3, 0, 0, 7, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // moveZeros_1(arr,size);

    moveZeros_2(arr,size);

    printArray(arr,size);

    return 0;
}