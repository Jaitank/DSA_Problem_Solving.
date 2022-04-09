#include <bits/stdc++.h>
using namespace std;

// push element at the bottom of the stack


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
	if(myStack.empty())
	{
		myStack.push(x);
		return myStack;
	}
	
	// store values
	int num =  myStack.top();
	myStack.pop();
	
	pushAtBottom(myStack, x);


	// again set all values while returning
	myStack.push(num);
	
	return myStack;

}


int main()
{
   return 0;
}