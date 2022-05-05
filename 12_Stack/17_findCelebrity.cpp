// question link: get it from gfg


// check babbar's lecture 57 (stack) for better understanding



#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>>M, int a, int b)
{
    if(M[a][b] == 1)
        return true;
    else 
        return false;
}

int Celebrity(vector<vector<int>>M, int n)
{
    // Step 1: Create stack and push candidates{0, 1, 2};
    stack<int>s;
    for(int i = 0; i < n; i++)
        s.push(i);

    // Step 2: Now we have to pop two candidates and check whether they know each other
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(M,a,b))
            s.push(b);
        else
            s.push(a);
    }

    // Now we have left with 1 candidate in stack which is a potential celebrity

    // Step3: Now check whether that candidate is celebrity or not
    int ansCandidate = s.top();
    int zeroCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(M[ansCandidate][i] == 0)
            zeroCount++;
    }

    int oneCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(M[i][ansCandidate] == 1)
            oneCount++;
    }

    // So we know that for a candidate it is compulsary that, it should know no one, and all should know it
    // means its row should have all zeros and one should have all one becuase it should know self too(so dont consider that box)

    if(zeroCount == n && oneCount == n-1)
        return ansCandidate;
    else return -1;

}
int main()
{

    vector<vector<int>> M = {  {0, 1, 0},
                      {0, 0, 0},
                      {0, 1, 0}   };

    // check which is celebrity among them


    cout << Celebrity(M, 3);

    
    return 0;
}