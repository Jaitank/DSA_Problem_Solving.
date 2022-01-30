#include <bits/stdc++.h>
using namespace std;

// Here we have to print our 2d array in spiral way 
// check question description here: https://leetcode.com/problems/spiral-matrix/submissions/

/*
Approach: When we are analysing that printing, we have found that we have to print in 4 ways:
           1. Print startingRow and then shifts startingRow to down, then
           2. Print  endingcOl and then shifts endingCol to its left, then
           3. Print endingRow and then shifts endingRow to up, then
           4. Print startingCol and then shifts startingCol to its right, and that's it.
*/
vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    // index initialisation
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total)
    {

        // print starting row
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // print ending column
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // print ending row
        for (int index = endingCol; count < total && index >= startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // print starting column
        for (int index = endingRow; count < total && index >= startingRow; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    
    return 0;
}