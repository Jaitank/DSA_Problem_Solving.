#include <bits/stdc++.h>
using namespace std;

// Approach: First fully list empty using recursion and then insert value in sorted order

// how to push in sorted order:
 // push if you get top is minimum then your number or when stack is empty

void insertSorted(stack<int> &s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	if(s.top() < x)
	{
		s.push(x);
		return;
	}
	
	int num = s.top();
	s.pop();
	
	insertSorted(s, x);
	
	s.push(num);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	
	int num = stack.top();
	stack.pop();
	
	sortStack(stack);
	
	insertSorted(stack, num);
}

int main()
{
    
    return 0;
}