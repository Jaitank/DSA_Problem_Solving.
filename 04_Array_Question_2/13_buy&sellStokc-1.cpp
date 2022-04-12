// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: In this we are using space of O(n) and time complexity is also O(n).
// here we have to store the future max selling prices so that we can find profit in same itreation

int maxProfit(vector<int>& prices) {
        vector<int> maxsofar;
        int size = prices.size();
        int maxi = INT_MIN;
        int maxiProfit = 0;
         
        // using space for storing maxsofar so that we can check for each day that if we buy on that value then it can be sell on that max value and so we can find profit
        for(int i = size - 1; i >=0; i--)
        {
            maxi = max(maxi, prices[i]);
            maxsofar.push_back(maxi);
        }
        reverse(maxsofar.begin(), maxsofar.end());

        for(int i = 0; i < size-1; i++)
        {
            cout << maxsofar[i] << " ";
        }
        cout << endl;
        
        // now we have to check for each day and find how much max profit we can gain
        for(int i = 0; i < size - 1; i++)
        {
            int val = maxsofar[i] - prices[i];
            maxiProfit = max(maxiProfit, val);

        }
        // now we have to return maxProfit
        
        return maxiProfit;
    }



// Approach 2: Here we have to optimised our solution in O(n) without space as we stored maxsofar in space in above here
// we are going to use minsofar and there is no need of extra space, it can be solved in constant space.


int maxProfit2(vector<int>& prices)
{
    int minsofar = INT_MAX;
    int maxiProfit = 0;
    int size = prices.size();


    // here we will maintain minsofar means, if we are on middle of an array then we have stored prior min buying prices so 
    // we can compare to gain maxProfit for each values with that min one.

    for(int i = 0; i < size; i++)
    {
        minsofar = min(minsofar, prices[i]);
        maxiProfit = max(maxiProfit, (prices[i] - minsofar));
    }

    return maxiProfit;
}



int main()
{

    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit2(prices);
	return 0;
}