#include <bits/stdc++.h>
using namespace std;


void solve(stack<int>&inputStack, int count, int size)
{
	// base case
	if(count == size/2) // we have to pop middle element
	{
		inputStack.pop();
		return;
	}
	
	// in every recursion we have to save its top and while returning we will update it again
	int num = inputStack.top();
	inputStack.pop();
	
	// recursive call
	solve(inputStack, count+1, size);
	
	// while returning from calls
	inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
    int count = 0;
	
	solve(inputStack, count, N);
   
}


int main()
{
    // 
    return 0;
}