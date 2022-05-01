// question link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Approach: we have to search substring without repeating characters in it: abcabde -> in this abde is that substing

// for that we have to maintain two pointers 1 is right which always pointed end of substing and on is right which always
// pointing on start of the substring and then we have to travese right pointer towards strings end and check for ansSubstring
// and we have to store each character along with it index in map, and when we get a repeating character on right pointer,
// then we will shift our left pointer towards that repeating characters index (which we have stored in map) 
// that's how we can calcuate length of each substring and then return max from it.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{

    unordered_map<char, int> freq;
    int n = s.length();
    int sizeCount = -1;
    int l = 0;
    int r = 0;

    while (r < n)
    {

        if (freq.find(s[r]) != freq.end())
        {
            while (freq.find(s[r]) != freq.end())
            {
                freq.erase(s[l++]);
            }
        }
        else
        {
            int length = r - l + 1;
            sizeCount = max(sizeCount, length);
            freq[s[r]]++;

            r++;
        }
    }
    if (sizeCount == -1)
        return 0;
    return sizeCount;
}

int main()
{
    
    return 0;
}