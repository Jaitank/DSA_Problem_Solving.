/*
 Here we have to find, Majority's element : element which is present more than half of size of array. if size is 10 then element present more than 5.

 1. Brute force Approach: In which we have to maintain count, for each element, complexity: O(n2)
 2. By using sorting: We can see order does not matter, here, so first sort array (O N*logN) and then traverse and calculate max
                      count in just one traversal in O(N) => time complexity => O(N*log N + N).
 3. By using Hash Map: in which we are saving frequecy count for all element, and this took O(N) time and O(N) space.

 4. But optimal solution in which we have to find in, in constant space and O(N) time.: Here we use Moore's voting Algo.
    IN which we have start mainting count from first index and make first index and ansIndex, then in next iteration we check is that element is equal to arr[ansIndex], if it so then increase count (count++) and if not, then decrease count, and when count becomes zero, then make that index ans index and count =1 and start checking for rest, and at last check the ansIdex, count to verify answer

*/
#include <bits/stdc++.h>
using namespace std;

int majortiyElement (int * arr, int size){

    int ansIndex = 0;
    int count = 1;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == arr[ansIndex])
        {
            count++;
        }
        else{
            count--;
        }
        if(count == 0)
        {
            ansIndex = i;
            count = 1;
        }
    }
    // verify if your ans index is majority or not
    int verifyCount = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[ansIndex] == arr[i])
        {
            verifyCount++;
        }
    }

    if(verifyCount > size/2)
    {
        return arr[ansIndex];
    }
    else{
        return -1; // NO majority element exist in array.
    }
}
int main()
{
    int arr[5] = {1,1,3,2,3};
    int size = 5;

    int ans = majortiyElement(arr, size);

    cout << "Majority element is : " << ans;

    return 0;
}