
// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

// Approach: Sell the stock when you get profit > 0 and then update minsofar to prices, when you have selled, then again start same till last of the array.

int maxProfit(vector<int> &prices)
{
    int minSofar = INT_MAX;
    int size = prices.size();
    int totalProfit = 0; // we will add, profit each time we buy and sell

    for (int i = 0; i < size; i++)
    {
        minSofar = min(minSofar, prices[i]); // select starting minSofar
        totalProfit = totalProfit + prices[i] - minSofar; // and add profit in totalProfit
        if ((prices[i] - minSofar) > 0) // if buy and selling diff. or profit is greater than zero -> means now we have to sell, 
        //and have to change minsofar, with same day prize, means again we have to start counting minSofar for further values and
        // repeat that process again.
        {
            minSofar = prices[i];
        }
    }
    return totalProfit;
}
int main()
{

    return 0;
}