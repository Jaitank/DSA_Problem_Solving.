#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <int> s;

    s.push(2);
    s.push(3);

    cout << "Element on the top :" << s.top() << endl;

    s.pop(); // it will delete the element present on the top

    cout << "Element on the top :" << s.top() << endl;

    cout << "size of the stack is: " << s.size() << endl;

    s.pop();

    if(s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not emtpy" << endl;
    }
    return 0;
}