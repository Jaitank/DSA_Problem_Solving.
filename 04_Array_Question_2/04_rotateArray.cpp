#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];     // cyclic rotation happens by that formula. suppose we have on 'n' so if now we have to shift
                    // of 'n' by two so we have to send it to index '1' so, by using formula (i+k) % n ==> here i = 5(last index), k = 2. 
                    // and n = 6(array size), so (5+2) % 6 => 1, so by that last index's value is shifted to index '1'
    
    }

    // Copying the temp in nums
    nums = temp;
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