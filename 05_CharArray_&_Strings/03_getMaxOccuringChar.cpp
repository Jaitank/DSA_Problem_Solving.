/*

Given a string str. The task is to find the maximum occurring character in the string str. If more than one character 
occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.
Example 2:

Input:
str = output
Output: t
Explanation:  t and u are the characters
with the same frequency, but t is
lexicographically smaller.

*/

#include <bits/stdc++.h>
using namespace std;

/*
 we are making array for all characters in alphabest (26) and, index from 0 to 25 indicating
 a/A to z/Z, and while traversing on string whenever we get alphabet then its respective index's 
 values will be increased by 1 and by that we get count of each character in array.
 and then we search for maximum from 0 to 26 and if we get max while traversing from 0 - 26 => then max
 has been updated and by that we will get most occuring character which is lexicographically smaller.
*/

char maxOccuring_char(string s)
{
    int arr[26] = {0};
    // this loop fill the array with respective character count.
    for (int i = 0; i<s.length(); i++)
    {
        char ch = s[i];
        int number = 0;

        // for lower case
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';        // if at that round of traversing we have ch  = d then number will be d -a means 4 so we get d's index as 4
        }
        else // for upper case
        {
            number = ch - 'A';       // same as above logic
        }
        arr[number]++;       // what index we get, thats value is being increased
    }

    // now loop for found maximum from that array
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if(maxi < arr[i])
        {
            ans = i;          // in ans we store the index on which we have max count
            maxi = arr[i];
        }
    }
    // at the end we get the the maximum count in maxi. now we have to return its index respective character
    // means if maxi is at index 4 then character is 'd'

    char finalAns = 'a' + ans ;   // now we add 'a' in max count index so that we get character. eg: 'a' + 0 = 'a',
                                 // 'a' + 1 = b suppose ans is 3 then 'a'+ 3 = d.

    return finalAns;
}

int main()
{
    string s;
    cout<<"Enter string :";
    cin>>s;

    cout<<"maximum occuring character is "<<maxOccuring_char(s);    
    return 0;
}