#include <bits/stdc++.h>
using namespace std;


/* Approach 1: We have to maintain an unordered map in which we have to store all numbers with their respective index;
 then we have to find -->

 for e.g if we have list like - 2,4,5 and we have to search for target = 9;
 then we have to store in map - {(2,0), (4,1), (5,2)};
 Now while iterating over numbers vector if we on 2, so target - 2 = 7, so we have to search 7 on unordered map, if we dound then ans is that and if not then iterate to next element and check again then we have to find

 */

vector<int> twoSum_byUnorderedMap(vector<int> &numbers, int target)
{
	unordered_map<int, int> hash; // Number, Index

	for (int i = 0; i < numbers.size(); i++)
	{
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end())
			return {hash[numberToFind], i};

		hash[numbers[i]] = i;
	}
	return {}; // means there is no ans;
}

/* 

Approach 2: In that approach we have to maintain a vectors of pair, in which pair stores elements with their index,
             then we have to sort them ,
			 and after sorting we have to apply two pointer approach for searching the target


			 as we know list is now sorted, so we maintained two pointers st, end,
			 and we check that st+end == target then return them, if not
			 then two case : 1 st+end > target --> then shift end-- as end has larger value, and we want smallers
			          case : 2 st+end < target --> then shift st++ as st has smaller value and we want larger


*/

vector<int> twoSum_byPairs(vector<int>& numbers, int target)
    {
        vector<pair<int,int>> v;
        for(int i = 0; i < numbers.size(); i++)
        {
            v.push_back({numbers[i], i});
        }
        sort(v.begin(), v.end());
        
        int st = 0;
        int end = numbers.size() - 1;
        while(st < end)
        {
            int sum = v[st].first + v[end].first;
            if(sum == target) return {v[st].second, v[end].second};
            if(sum > target)  end--;
            else st++;
        }
        return{-1,-1};
    }


int main()
{

	return 0;
}