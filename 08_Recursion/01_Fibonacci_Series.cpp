/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each 
number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).


Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.


*/

/*

Recursion: Two Necessary condition:
            i) Base condtion: Where we have to stop recursion. Here return is mandatory,
                              if we not write that condition then segmentation fault occur 
                              due to stack goes overflow of program.

            ii) Recursive Relation: It is also mandatory to write in which we have to call same function acc. to our need.

*/

#include <bits/stdc++.h>
using namespace std;

int getFibonacci(int n)                // by recursion time complexity is little large
{
    // base condition
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // recursive relation.
    return getFibonacci(n-1) + getFibonacci(n-2); // fibonacci no. is calculated by sum of its previous two numbers.

}


int getFibonaccibyLoop(int n) // fibonacci no. by loop, it is less time complex than recursion
{
    int ans;
    int first = 0;
    int second = 1;
    if ( n == 0)
    {
        return 0;
    }
    
    if (n == second){
        return 1;
    }
    
    for(int i = 0; i < n-1; i++)
    {   
        ans = first + second;           // becuase fibonacci no. is calculated by sum of its previous two numbers.
        first = second;
        second = ans;
    }
    return ans;
}

int main()
{
    int n; // give fibonacci series till nth number
    cout << "Enter number :";
    cin >> n;

    cout << "Febonnaci no. by recursion :" << getFibonacci(n) << endl;

    cout << "Febonnaci no. by loop :" << getFibonaccibyLoop(n);

    return 0;
}