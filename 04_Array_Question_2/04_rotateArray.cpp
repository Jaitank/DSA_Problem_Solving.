#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());

    // right roatation

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i]; // cyclic rotation happens by that formula. suppose we have on 'n' so if now we have to shift
                                               // of 'n' by two so we have to send it to index '1' so, by using formula (i+k) % n ==> here i = 5(last index), k = 2.
                                               // and n = 6(array size), so (5+2) % 6 => 1, so by that last index's value is shifted to index '1'
    }

    /*

    left rotation ->

    int size = nums.size();
    int mod = k % size;
    int temp[size];
    for (int i = 0; i < size; i++)
    {

      temp[i] = (arr[(mod + i) % size]);

    }
    */

    // Copying the temp in nums
    nums = temp;
}

// rotate array in-place alog

void reverse(vector<int> &nums, int s, int e)
{
    while (s < e)
    {
        swap(nums[s++], nums[e--]);
    }
}

void rotateInPlace(vector<int> nums, int k)
{
    int n = nums.size();

    // edge case if k > n
    k = k % n; // so we will do mod
    if (k == 0)
        return;
    if (n == 1)
        return;

    // step 1: rev n- k from left or start
    reverse(nums, 0, n - k - 1); // for n - k , index = n - k -1

    // step2: rev last k numbers
    reverse(nums, n - k, n - 1);

    // step rev full numbers
    reverse(nums, 0, n - 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    int k = 3; // rotate by k

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}