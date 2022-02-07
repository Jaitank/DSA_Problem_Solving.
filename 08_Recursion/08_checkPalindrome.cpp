
// Task: check palindrome using recursion - Palindrome: if reverser of string is also same then it is palindrome.


#include <bits/stdc++.h>
using namespace std;


bool checkPalindrome(string &str, int i)      // using formula size - i - 1 (more optimised)
{
    // base condition
    if(str[i] !=  str[str.size() - i - 1])
    {
        return 0;
    }
    if (i > str.size() - i - 1)
    {
        return 1;
    }

    return checkPalindrome(str, ++i);
}
int main()
{
    string S = "sis";

    // reverseString(S, 0, S.size() - 1);

    if(checkPalindrome(S, 0))
    {
        cout << "This is Palindrome";
    }
    else
    {
        cout << "This is not Palindrome";
    }

    return 0;
}