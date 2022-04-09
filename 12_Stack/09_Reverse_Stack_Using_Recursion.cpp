#include <bits/stdc++.h>
using namespace std;

// Approach: We will first empty full list and then insert that first no at botton, we will do this for every element
// so its time complexity will be O(n2).

void insertAtBottom(stack<int> &stack, int element)
{
    if (stack.empty())
    {
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertAtBottom(stack, element);

    stack.push(num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();

    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main()
{

    return 0;
}