// Say digits, ex: i/p: 4132 then o/p: Four One Three Two

#include <bits/stdc++.h>
using namespace std;

void sayDigits(int n, string arr[])
{
    // base condtion
    if (n == 0)
    {
        return;
    }
    
    int digit = n % 10;
    
    // cout << arr[digit] << " ";  if we print here then becasue we extract digit from last then, digits will be print in reverse order for us.

    n = n / 10;

    sayDigits(n,arr);

    cout << arr[digit] << " "; // but if we print here, then it will going to print after base condition get trues, means, when all recursive calls returns there value.

}
int main()
{
    int n;
    cout << "Enter numbers :";
    cin >> n;

    string arr[10] = {"Zero", "One", "Two", "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine"};

    if (n == 0)
    {
        cout << "Zero";
    }

    sayDigits(n, arr);

    return 0;
}