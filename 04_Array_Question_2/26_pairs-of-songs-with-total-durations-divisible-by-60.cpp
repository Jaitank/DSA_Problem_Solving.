
// quesiton link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/


// Approach link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/1661803/     Easy-C%2B%2B-solution-with-explanation-and-intuition-in-detail

#include <bits/stdc++.h>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    int n = time.size();
    vector<int> v(60, 0);
    int i = 0;
    int count = 0;
    while (i < n)
    {
        int a = time[i] % 60;
        if (a != 0)
        {
            count += v[60 - a];
        }
        else
        {
            count += v[0];
        }
        v[a]++;
        i++;
    }
    return count;
}
int main()
{

    return 0;
}