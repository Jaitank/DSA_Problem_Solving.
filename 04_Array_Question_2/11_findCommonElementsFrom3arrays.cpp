// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

#include <bits/stdc++.h>
using namespace std;

// Approach: Using Three pointer, and which array's element is mini, increment it pointer then compare again (sorted array).

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int mini;
    while (p1 <= n1 - 1 && p2 <= n2 - 1 && p3 <= n3 - 1) // if any array finished then stop
    {
        if (A[p1] == B[p2] && B[p2] == C[p3]) // if all three are equals then push that element.
        {
            ans.push_back(A[p1]); // can push any array element becuase all are same
            while (A[p1] == A[p1 + 1] && p1 < n1) // we have to shift pointer till we will reach to another element, so that we 
                p1++;                            // can handle duplicates
            p1++;
            while (B[p2] == B[p2 + 1] && p2 < n2)
                p2++;
            p2++;
            while (C[p3] == C[p3 + 1] && p3 < n3)
                p3++;
            p3++;
        }
        else
        {   // finding index of mini element and then performing increment in particular.
            if (A[p1] <= B[p2] && A[p1] <= C[p3]) // it says A[p1] is mini so increment in p1;
            {
                p1++;
            }
            else if (B[p2] <= A[p1] && B[p2] <= C[p3])// it says B[p2] is mini so increment in p2;
            {
                p2++;
            }
            else if (C[p3] <= B[p2] && C[p3] <= A[p1])// it says C[p3] is mini so increment in p3;
            {
                p3++;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}