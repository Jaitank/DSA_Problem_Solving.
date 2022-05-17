// question link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <bits/stdc++.h>
#include "001Tree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(Node* root) {
        
        map<int,  map<int, multiset<int> > > nodes;
        // we can use vector too but then we have to sort it while stroing in ans
        queue<pair < Node*, pair<int, int> > >q;
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        // first push root node
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty())
        {
            pair < Node*, pair<int, int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            // now map according to hd and lvl
            nodes[hd][lvl].insert(frontNode -> data);
            // if we use vector 
            // nodes[hd][lvl].push_back(frontNode -> data);
            if(frontNode -> left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ) );
            if(frontNode -> right)
                q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1) ) );
            
        }
        
        for(auto i: nodes)
        {
            vector<int>tempAns;
            for(auto j: i.second)
            {
                // sort(j.second.begin(), j.second.end());
                // if we use vector then we have to sort here
                for(auto k: j.second)
                {
                    tempAns.push_back(k);
                }
            }
            ans.push_back(tempAns);
        }
        
        return ans;
        
    }
};


int main()
{
    
    return 0;
}

