#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{

    int row = matrix.size();

    int col = matrix[0].size();
    if (row == 1 && col == 1)
    {

        return;
    }

    // first transpose the matrix
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            // cout << j;
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // now when matrix is transposed now we have to shift col
    int stCol = 0;
    int endCol = col - 1;
    while (stCol < endCol)
    {
        for (int i = 0; i < row; i++)
        {
            swap(matrix[i][stCol], matrix[i][endCol]);
        }
        stCol++;
        endCol--;
    }

}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<vector<int>> matrix;
        int n;
        cin >> n;
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < n; j++)
            {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            matrix.push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        rotate(matrix);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}