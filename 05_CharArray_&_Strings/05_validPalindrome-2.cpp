// question link :  https://leetcode.com/problems/valid-palindrome-ii/

#include <bits/stdc++.h>
using namespace std;

// Approach: we will use recursion to check and becuase we can give only 1 chance to delete a word so,
// if base case chance > 1 then return false, and on 1st chance we will run recusively both situation st +1 and end - 1 too

class Solution
{
private:
    bool isPalindrome(string s, int st, int end, int chance = 0)
    {
        // base case;
        if (chance > 1)
            return false;

        while (st < end)
        {
            if (s[st] == s[end])
                st++, end--;
            else
            {
                return isPalindrome(s, st + 1, end, chance + 1) ||
                       isPalindrome(s, st, end - 1, chance + 1);
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {

        int st = 0;
        int end = s.length() - 1;

        if (s.length() == 2)
            return true;

        return isPalindrome(s, st, end);
    }
};
int main()
{

    return 0;
}