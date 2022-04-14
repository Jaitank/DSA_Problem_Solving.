// question link: https://leetcode.com/problems/unique-number-of-occurrences/

/*
Approach:  - First calculate and store occurence in an unordered_map, then 
           - store their occurence values in a vector
           - sort vector and if any adjaccent are same then not unique occurences and if not same then unique
*/

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> occ;
    int n = arr.size();

    // map no of occurences in map
    for (int i = 0; i < n; i++)
    {
        // if value comes second and more than second time then increment in occuremce
        if (occ.find(arr[i]) != occ.end())
        {
            occ[arr[i]]++;
        }
        else // if no comes first time make occ = 1
        {
            occ[arr[i]] = 1;
        }
    }

    // now we have mapped our all occ now we have to check uniqueness

    // for that first store values in vector so we can sort them
    vector<int> occVal(occ.size());
    int j = 0;
    for (auto i = occ.begin(); i != occ.end(); i++)
    {
        occVal[j++] = i->second;
    }

    // now sort
    sort(occVal.begin(), occVal.end());

    // now check uniqueness
    for (int i = 0; i < occVal.size() - 1; i++)
    {
        if (occVal[i] == occVal[i + 1])
            return false;
    }
    return true;
}
int main()
{

    return 0;
}