// question link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
const int MOD = 1e9 + 7;
#include <bits/stdc++.h>
using namespace std;


/* we have given horizontal cuts and vertical cuts, height and width and now after applying that cuts in h and w,
 we have to find remaining max area, so that we first sorts the cuts, so we can find differnce in heights

 suppose horizontal cuts are - [1,3,4] on h = 5 => so remaining heights are 1-0 = 1, 3-1 = 2, 4 -3 = 1,  5-4 = 1
 in them max height is  2 from (3-1) cuts and similiary find max widhth remaining from vertical cuts and then 
 we get maxheight and maxwidth now return their product as we have to return area
 */

long int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{

    int hSize = horizontalCuts.size();
    int vSize = verticalCuts.size();
    // sort them
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    
    // first rem height b/w end of rectangle and last cut
    long int maxRemHeight = h - horizontalCuts[hSize - 1];

    // now find all heights b/w cuts
    for (int i = hSize - 1; i > 0; i--)
    {
        long int remHeight = horizontalCuts[i] - horizontalCuts[i - 1];
        maxRemHeight = max(maxRemHeight, remHeight);
    }
    // at last height b/w start of rectange and first cut = (horizontalCuts[0] - 0)
    maxRemHeight = max(maxRemHeight, (long int)horizontalCuts[0]);


    // now similiarly find maxwidth
    long int maxRemWidth = w - verticalCuts[vSize - 1];
    for (int i = vSize - 1; i > 0; i--)
    {
        long int remWidth = verticalCuts[i] - verticalCuts[i - 1];
        maxRemWidth = max(maxRemWidth, remWidth);
    }
    maxRemWidth = max(maxRemWidth, (long int)verticalCuts[0]);

    return (maxRemHeight * maxRemWidth) % MOD;
}
int main()
{

    return 0;
}