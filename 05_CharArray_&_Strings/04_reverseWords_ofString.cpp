/*
Reverse words: In this question we have to reverse the every word present in string.
Note: only lower case characters are present in our string.

Ex:  string s = 'my name is jai'
     Now we have to reverse every words so now our s should be like this
     s = 'ym eman si iaj'

Approach: For this, we know while traversing, there are two condition before which we have to reverse the word
          i) if space comes
          ii) if '\0' null characters comes
*/

#include <bits/stdc++.h>
using namespace std;

void rev_String(string &s, int st, int e)
{

    while (st <= e)
    {
        swap(s[st++], s[e--]);
    }

    // cout<<s<<endl;
}
/* if we here accept as reverseWords ( string s) then below string is just copy and string is reverse in this only
 not in string of our main function so we have to accept as reference with '&', so whatever we change here it  creates impact on real string, because by refrence that actual string's address is passed here and we perform changes in that actually */

void reverseWords(string &s)
{
    int count = 0; // here we counts the words length 
    int init = 0;       // here we count the words starting index
    for (int i = 0; i <= s.length(); i++)
    {
        int end = i - 1; // here we count the words ending index

        if (s[i] == ' ' || s[i] == '\0')
        {
            init = end - count + 1;
            rev_String(s, init, end); // here we send string with particular word (init) starting & (end) ending index so that only that word rev.
            count = 0;      // after reversing a words then again make count = 0 so that we can start count for another word.          
        }
        else
        {
            count++;
        }
    }
}
int main()
{
    string s = "my name is jai";

    cout << s << endl;

    reverseWords(s);

    cout << s;

    return 0;
}