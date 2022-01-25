/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
and each integer appearsonce or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Sample Input : nums = [4,3,2,7,8,2,3,1]
Sample Output: ans = [2,3]
*/

#include<iostream>
#include<vector>
using namespace std;

/*Brute force apporach Here brute force apporach is we wil run two loops and compare each element with each other if
any element matches then push it in ans[] array and at last we get ans[] array with twice repated values.
It has time complexity : O(n^2)
But we have to solve this in optimised way and in O(n)

So there is an Idea ->
If you Look This ->array of integers, 1 ≤ a[i] ≤ n (n = size of array)constrain [ given ]
We Can Easily Identify That All element's Are greater Then or equal 1 and Less Then or Equall size of the array
And 2 . Constrain elements appear twice and others appear once

So try To Use Those Information To Come Up better a solution

What We can Do is That We Can Use That Given Array As an Frequency Array
and Instead of Count The each Element we Can Use -[minus] To track Each Element we are traverse Or Not 
[as They said That any element can occoure max Twice]
While Traverseing if We Get Negetive element again We Know That It's Allredy Visited So It Wolud 
Be a duplicate num <= Push That Into ANS array

Lastly Return ANS array

Eg :at i = 0 : 
       num[num[i]-1] => num[4-1] => num[3] => 7 makes it negative = > -7
       Now vector nums  => [4,3,2,-7,8,2,3,1] 
    at i = 1 :
       num[num[i]-1] => num[3-1] => num[2] =>2  makes it negative = > -2
       Now vector nums  => [4,3,-2,-7,8,2,3,1]

       and so on.....

       suppose at i = 6 
         num[num[i]-1] => num[3-1] => num[2] => here value is already negative. means value at i = 6 was somewhere
         present too at any i means 3 is repeating so if this conditions true then push num[6] in ans vector

*/



vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())return {}; // if nums is empty return 
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0) //  if the element of ith index is negative means it is repeating
                ans.push_back(abs(nums[i])); // if above condition true then push the value in vector ans
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1]; // here we make the  element value negative.
        }
        return ans;
    }

int main()
{
    vector<int> nums  = {4,3,2,7,8,2,3,1};

    vector<int> ans = findDuplicates(nums);

    for (int i:ans)
    {
        cout<<i<<" ";
    }

    return 0;
}
