/*
Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list
represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards.
 Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the
‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.
For Example :
array/list elements are {2, 1, 5, 6, 2, 3}.
A painter can paint blocks {5,6} or {1,5,6,2} together but not {2,5,6} or {5,6,3}.

Sample Input : 5 5 5 5
Sample Output : 10

Same as Book allocation problem has been solved.

Approach: To learn its approach Revise this video:
https://www.youtube.com/watch?v=YTTdLgyqOLY&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15&t=2172s&ab_channel=CodeHelp-byBabbar


*/
#include <bits/stdc++.h>
using namespace std;
bool isPaint_Possible(vector<int> &boards, int k, int mid, int size)
{
    int painterCount = 1;
    int boardsection = 0;
    for (int i = 0; i < size; i++)
    {
        if (boardsection + boards[i] <= mid)
        {
            boardsection += boards[i];
        }
        else
        {
            painterCount++;
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }
            boardsection = boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int size = boards.size();

    for (int i = 0; i < size; i++)
    {
        sum += boards[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPaint_Possible(boards, k, mid, size))
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
    vector<int> boards = {5, 5, 5, 5};
    int No_of_Painters = 2;
    cout << "Answer is : " << findLargestMinDistance(boards, No_of_Painters);
    return 0;
}