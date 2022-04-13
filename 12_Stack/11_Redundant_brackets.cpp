#include <bits/stdc++.h>
using namespace std;
// question link: https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio
// paranthesis are valid, only check redundacy :

bool findRedundantBrackets(string &st)
{
    stack<char> s;

    for (int i = 0; i < st.length(); i++)
    {
        char ch = st[i];
        // if we get opening praranthesis or operator then push them in stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);
        else
        {
            // either ch is closing bracket or lowecase letter, ignore lowecase letter
            if (ch == ')')
            {
                bool redundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        // means operator founded
                        redundant = false;
                    }
                    s.pop();
                }
                // by above loop we have poped operator from stack now its top left with opening bracket - 
                // when we get an opening bracket then we comes out of the loop, and now we have to remove that opening bracket also

                if (redundant == true)
                    return true;
                s.pop();
            }
        }
    }
    return false;
}

int main()
{

    return 0;
}