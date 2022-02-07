
// Task: Find power :  a, b => a^b; measn if a = 2 and b = 3 then return 2^3 = 8

#include <bits/stdc++.h>
using namespace std;

int getPower(int a, int b)
{
    // base condition
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    // Recursive Call
    int ans = getPower(a,b/2);
    
    // if b is even
    if(b%2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
    
}
int main()
{
    int a;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b :";
    int b;
    cin >> b;

    cout << "Power of (a,b) is : " << getPower(a,b);
    return 0;
}