
// Task: Reverse string using recursion


#include <bits/stdc++.h>
using namespace std;

void reverseString(string &S, int st, int end) // two pointer approach in recursion
{
    // base condition
    if (st > end)
    {
        return;
    }

    swap(S[st], S[end]);
    reverseString(S, ++st, --end);
}

void reverseString_2(string &str, int i)      // using formula size - i - 1 (more optimised)
{
    // base condition
    if (i > str.size() - i - 1) // by using formula
    {
        return;
    }

    swap(str[i], str[str.size() - i - 1]);

    reverseString_2(str, ++i);
}
int main()
{
    string S = "abcdefg";

    // reverseString(S, 0, S.size() - 1);

    reverseString_2(S, 0);

    cout << S;
    return 0;
}