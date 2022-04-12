// question link:  https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

// Solution: Time complexity - O(n) and space - O(1)


// Approach 1: use of carry - 

vector<int> plusOne(vector<int> &digits)
{
    vector<int> ans;
    int carry = 0;

    // for last digit - we have to add one
    int end = digits.size() - 1;
    int sum = digits[end] + carry + 1;
    // if two digit value obtained in sum then we have to maintain carry
    if ((sum / 10) != 0)
    {
        int val = sum % 10;
        carry = sum / 10;
        ans.push_back(val);
    }
    else // if single digit then directly push and make carry = 0
    {
        ans.push_back(sum);
        carry = 0;
    }

    // for digits prior then last one
    int i = end - 1; // maintain  i for prior digits then last one
    while (i >= 0) // if this value false in first time that means input value only contains 1 digit
    {
        int sum = digits[i] + carry;
        if ((sum / 10) != 0) // if two digit value obtained in sum then we have to maintain carry
        {
            int val = sum % 10;
            carry = sum / 10;
            ans.push_back(val);
        }
        else   // if single digit then directly push and make carry = 0
        {
            ans.push_back(sum);
            carry = 0;
        }
        i--;
    }
    if (carry != 0)
    {
        ans.push_back(carry);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Approach 2: directly code according to digits is 9 or something else

void plusone2(vector<int> &digits)
{
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9) 
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++; // if digit is not 9 then, do not have to move further just increase one and return the ans.
			return;
		}
	}
		digits[0] =1;
		digits.push_back(0);
		
}

int main()
{
    vector<int> digits = {1, 2, 9};
    vector<int> ans = plusOne(digits);

    plusone2(digits);

    for(int i = 0; i < digits.size(); i++)
    {
        cout << digits[i] << " ";
    } cout << endl;
    return 0;
}