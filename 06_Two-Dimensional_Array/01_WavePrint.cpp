/*
Problem Statement
For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e.,
print the first column top to bottom, next column bottom to top, and so on.
For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 2, 4].

Approach: When we get index = even then we have to go (up to down) in col,
          when we get index = odd then we have to go (down to up) in col
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int cols = 0; cols < mCols; cols++)
    {
        if (cols & 1) // odd index -->
        {
            for (int rows = nRows - 1; rows >= 0; rows--)
            {
                ans.push_back(arr[rows][cols]);
            }
        }
        else // for even index -->
        {
            for (int rows = 0; rows < nRows; rows++)
            {
                ans.push_back(arr[rows][cols]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};

    int row = arr.size();    // finding size of row of 2-d array, 2-d vector and matrix.
    int col = arr[0].size(); // finding size of column of 2-d array, 2-d vector and matrix.

    // Printing 2-D array/vector and matrix.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Printing them in wave form

    vector<int> ans = wavePrint(arr, row, col);

    cout << "Printing in wave form :" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}