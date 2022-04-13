#include <bits/stdc++.h>
using namespace std;

/*

Approach:

Step1: Check if string is in odd then we cant make string valid with reverse any of bracket, we need even

Step2: Now remove valid paranthese, we want to find cost to make invalid paranthese valid, so remove valid ones.

Step3: Now when our stack have only invalid parathesis - they can be of three types:
    - i)    {{{{ - only even because odd one we have already discarded -

             => in them we can observe opening bracket are - 4 and close are 0; and if reverser two we can make them valid so
            cost = 4 /2 or we can say no a / 2; where a =  no. of opening brackets


    - ii)   }}}} - only even becaude odd one we have already discarded

            => in them we can observe closing brackets are - 4 and opening are 0, so same as above point
            it ca be handled in cost = b /2 , where b is no of closing brackets;

    - iii)  }}{{ - here patter can be of four types
           a) }}}{{{ : a = odd(no of open) and b = odd(no of close) and total is even so chlega
           b) }}}{{  : a = odd and b = even and so total is odd which is not acceptable and discarded in step 1
           c) }}{{{  : a = even and b = odd and so total is odd which is not acceptable and discarded in step 1
           d) }}{{   : a = even and b = even and total is even so chlega

           so from above four we have to face two conditions - 
           when a = odd, b = odd
           and a = even , b = even

           and now we have to calculate cost for both of them
           lets take and example:
           for case1:  a = odd, b = odd
                       }}}{{{ - so to make them valid we have to reverse like
                       {}{}{} - so we have to change 4 means
                       when a = 3 and b = 3 we have to change four time
                       means = (a + 1)/2 + (b+1)/2 => (3+1)/2 + (3+1)/2 = 2 + 2 = 4;
            for case2: a = even, b = even
                       }}{{ - so to make them valid we have to reverse like
                       {}{} - we have to reverse two of them
                       so (2+1)/2 + (2+1)/2 = 3/2 + 3/2 = 1 + 1 (integer dividation) = 2
        so now we have with our formula with that iii.) condition
    
    And we can see that formula is also true for above two condition, so we can simply use that formula to get ans
*/

#include <stack>
int findMinimumCost(string str)
{
    // step1: if odd then return -1
    if (str.length() % 2 != 0)
        return -1;

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{') // if ch is opening bracket
            st.push(ch);
        else
        {
            // if ch is close bracket
            // and if that close bracket have respective opening bracket then remove that
            // becuase we want only invalid paranthesies in our stack
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
            {
                st.push(ch);
            }
        }
    }
    // after above loop we only have invalid paranthesis
    // now count for both type of bracket b'coz ans is depend on that
    int a = 0, b = 0;
    while (!st.empty()) // counting no of opening and closing brackets and storing in a and b;
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }
    // using formula
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main()
{

    return 0;
}