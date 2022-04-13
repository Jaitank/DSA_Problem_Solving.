// question link: https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;

// we will maintain two stacks 1 for all main function operations and one for mini elements, where minimum one always on top

class MinStack
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
        s1.push(val);
        if (s2.empty() || val <= getMin())
            s2.push(val);
    }

    void pop()
    {
        if (s1.top() == getMin())
            s2.pop();
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s2.top();
    }
};

int main()
{

    /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

    return 0;
}