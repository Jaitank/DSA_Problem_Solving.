/*

Check if an array is sorted and rotated or not. if sorted and rotated (by some value[including zero]) means if only sorted, 
then return true and if not then return false.

eg:  {4,5,1,2,3} => this is a rotated sorted array,
     {3,4,5,1,2} => this is also,

Approach:  We can observe in that array : if there is rotated sorted array then only time it can be possible that
           prevElement  > nextElement.(only 1 time it can be true)==> and if it is then surely it is rotated sorted array.
           So, we can check this condition's count if it not equal to 1 then array is not rotated sorted.

           and if only sorted then this condition never becomes true then also return true

           eg: if all value are equal {1,1,1} = > then also it is rotated and sorted, so we have to check condition
           if our condition is fullfilled by 1 or less than 1 then ==> rotated and sorted

*/

#include <bits/stdc++.h>
using namespace std;

bool isSorted_Rotated(vector<int> nums)
{
    int size = nums.size();

    int count = 0;

    for (int i = 0; i < size - 1; i++) // here we take size -1 as becuase, we are going to check last index element in its previous one.
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
        }

        if (nums[size - 1] > nums[0])
        {
            count++;
        }
    }

    return (count <= 1);
}
int main()
{
    vector<int> nums = {1,2,3,4,5,1}; // sorted and rotated array

    if (isSorted_Rotated(nums))
    {
        cout << "Array is rotated and sorted";
    }
    else
    {
        cout << "Array is not rotated and sorted";
    }

    return 0;
}