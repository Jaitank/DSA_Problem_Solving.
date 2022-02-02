#include <bits/stdc++.h>
using namespace std;

// we have to make Jaggered array- array of array with different sizes. means columns size can be different, for each row.
int main()
{
    int row;
    cout << "Enter row size";
    cin >> row;
    int **arr = new int *[row];

    // Now column size can be different for each row, so we are left column size on runtime, what user want to give.
    int colx[row]; // array which store different columns sizes for every row.
    
    for (int i = 0; i < row; i++)
    {
        int col;

        cout << "Enter size of element you want in " << i << " row :"; // col size can be difference in that jaggered array.

        cin >> col;

        colx[i] = col; // saving column values in another array, so later we can print them

        arr[i] = new int[col];

        cout << "Now Enter " << col << " elements in this row :";

        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j]; // taking input for that particular row acc. to its column size.
        }
    }

    // taking output
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colx[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}