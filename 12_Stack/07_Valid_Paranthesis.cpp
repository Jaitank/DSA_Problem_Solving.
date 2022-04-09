#include <bits/stdc++.h>
using namespace std;


bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening bracket stack push
        // if closing bracket stack top check and pop

        if (ch == '{' || ch == '[' || ch == '(') // if opening brackets then push them in stack
        {
            s.push(ch);
        }
        else // if closing bracket then compare stack top and if mathces with opening brackets respective closing bracket then pop
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == '}' && top == '{') ||
                    (ch == ']' && top == '[') ||
                    (ch == ')' && top == '('))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    
    return 0;
}