/*
Here we have to find square root of a value 'n'.
we will going to use binarySearch approach for this.
here we use two functions to get square root.

1. It will give us integer value only of n's square root
   for ex: n = 37 and sqrt(37) = 6.082, so this function return us only that integer 6 only.

2. It will give us our ans with some precison in decimal (like 6.082)

How to use binary search in this?

Suppose we have n = 25, now we know that its sqrt(25) somewhere lies b/w (0,25) so {0,1,2.....23,24,25} is our search span
and we can apply binary search here to find sqrt()

Apporach : Here start = 0, end = 25, and mid = (start+end)/2 = 12

if our (mid*mid > n) ==> (12*12 > 25)-->True--> then we know it means squre of value large than 12 can never thier sqaure as 25.
so here we have to reduce  our search space b/w (s,mid) for this we have to end = mid-1;
now e = 12-1; means e = 11; and now s=0,e =11, so mid = (s+e)/2 => is 5 so if(mid*mid == n) ==> return mid; but
and if (mid*mid < n) ==> then we have to save this mid as ans and reduce search space b/w(mid+1,e) => for that s = mid+1
here we are storing our mid in ans because it can be possible that our sqrt(37) somewhere is 6.028 and if mid= 6 and if
mid*mid < n, and we want integer 6 as ans so we have saved this mid in ans and if it not so then ans will update in next loop.

*/

#include <iostream>
using namespace std;

// 1. This function will give you integer part of ans
long long int mySqrt(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int sq;
    long long int ans = -1;

    while (s <= e)
    {
        sq = mid * mid;
        if (sq == n)
        {
            return mid;
        }
        if (sq > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// 2. This function will give you ans with some precision in decimal like sqrt(37) = 6.082

/*
Here Approach is : when we have successfully find our integer part of ans. Now we have to find its decimal part also, for this
we have to add 0.1 in our ans(tempsol or integer part) means it is now (suppose of integer part of tempSol = 6 ) then 6+0.1 =6.01.
Now condition for this (6.01*6.01) < n(37) if no then once again in next iteration 0.1 more add in ans, now our ans is 6.01+0.1 = 6.02
now process continues till we get less than n and if condition get true means now our ans's square is greater than n(37) then we will
add more factor by breaking that nested loop of 'j'.
*/

double sqrtWithdecimal(int precision, int n, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (double i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    cout << "Enter value whose square root you wanna find : ";
    int n;
    cin >> n;
    int tempSol = mySqrt(n); // here you get only integer part of answer

    cout << "Squaroot of " << n << " is :" << sqrtWithdecimal(3, n, tempSol); // here we pass 3 becuase we want 3 no.s after decimal

    return 0;
}