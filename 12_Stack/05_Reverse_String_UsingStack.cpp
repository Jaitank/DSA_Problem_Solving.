#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> s;
    string s1 =  "this is jai tank";

    for(int i = 0; i < s1.length(); i++)
    {
        s.push(s1[i]);
    }

    for(int i = 0; i < s1.length(); i++)
    {
        s1[i] = s.top();
        s.pop();

    }


    for(int i = 0; i < s1.length(); i++)
    {
        cout << s1[i];
    }cout << endl;


    return 0;
}