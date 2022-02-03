/*
Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.


Example 1:

Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 4, -2, 5) which
is a contiguous subarray.


Example 2:

Input:
N = 4
Arr[] = {-1,-2,-3,-4}
Output:
-1
Explanation:
Max subarray sum is -1
of element (-1)

*/

/*
Approach: BruteForce:  There will be a brute force approach in which we have to traverse for all the subarrays and store there sum
                       in maxi after comparing from the previous one. and at last we get max subarray sum in maxi it takes o(n3)
          
          Optimal  : in this we will going to store sum of array after each value traversed.
        (kadane's    for eg: if arr = {1,2,3,-7,5}, int currSum = 0;
          Algorithm) in first iteration = we get 1, currSum = (1 + currSum) => currSum = 1, stored it in ansArray  = {1}
                     in second iteration = we get 2, currSum = (2 + currSum) => currSum = 3, stored it in ansArray = {1,3}
                     in third iteration = we get 4, currSum = (4 + currSum) => currSum = 7, stored it in ansArray = {1,3,7}
                     in forth iteration = we get -7, currSum = (-7 + currSum) => currSum = 0, now we have another condition
                     when we get currSum <= 0  then make currSum again 0 and start sum again from next and stores only positive.
                     by this we will get the max subarray sum in our ans array.
                     then, we have to just check max from that ansArray and return it.
                     Now there could be a condition in which all the elements are -negative, in that every time we get cur<= 0,
                     so for that we have maintain a test = 0 variable, and whenever or currSum is positive then we do test = 1,
                     so if test remains 0 means currSum never becomes postive in any iteration means all the elements are -1,
                     so in that situation when test == 0 ==> return max of our main array, becuase when all negativesthere, then max 
                     subarray is of greatest one.
                     and if test == 1 then return max of ansArray.
*/

#include <bits/stdc++.h>
using namespace std;

// arr: input array
// n: size of array
// Function to find the sum of contiguous subarray with maximum sum.
long long maxSubarraySum(int arr[], int n)
{

    int ans[n] = {0};
    int currSum = 0;
    int test = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum <= 0)
        {
            currSum = 0;
        }
        else
        {
            ans[i] = currSum;
            test = 1;
        }
    }

    if (test == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }
    else
    {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(ans[i], maxi);
        }
        return maxi;
    }
}
int main()
{

    int arr[5];
    int size = 5;
    cout<<"Enter 5 elements for array: ";
    for (int i = 0; i <  size; i++)
    {
        cin >> arr[i];
    }

    long long maxSubArray = maxSubarraySum(arr,size);
    cout << "Maximum Sub Array's Sum is : "<< maxSubArray;
    return 0;
}